#include "Common.h"
#include "AGE_TextControls.h"
#include "AGE_ComboBoxes.h"
#include "AGE_CheckBoxes.h"

class AGE_List32Box
{
private:
	wxGridSizer *Buttons;
public:
	AGE_List32Box() {}
	virtual ~AGE_List32Box() {}

	wxStaticBoxSizer *ItemList;
	wxTextCtrl *Search, *SearchRecursive;
	wxListBox *List;
	TextCtrl_Long *Item;
	ComboBox_Plus1 *ItemCombo;
	wxButton *Add, *Insert, *Delete, *Copy, *Paste, *PasteInsert, *CopyAllToSelected;

	void CreateControls(wxScrolledWindow* &scroller, const wxString &listName, const wxString &itemName)
	{
		ItemList = new wxStaticBoxSizer(wxVERTICAL, scroller, listName);
		Search = new wxTextCtrl(scroller, wxID_ANY);
		SearchRecursive = new wxTextCtrl(scroller, wxID_ANY);
		List = new wxListBox(scroller, wxID_ANY, wxDefaultPosition, wxSize(10, 100), 0, NULL, wxLB_EXTENDED);
		Item = new TextCtrl_Long(scroller);
		ItemCombo = new ComboBox_Plus1(scroller, Item);
		Buttons = new wxGridSizer(3, 0, 0);
		Add = new wxButton(scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(5, 20));
		Insert = new wxButton(scroller, wxID_ANY, "Insert", wxDefaultPosition, wxSize(5, 20));
		Delete = new wxButton(scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(5, 20));
		Copy = new wxButton(scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(5, 20));
		Paste = new wxButton(scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
		PasteInsert = new wxButton(scroller, wxID_ANY, "PasteInsert", wxDefaultPosition, wxSize(5, 20));
		CopyAllToSelected = new wxButton(scroller, wxID_ANY, "Copy all to selected " + itemName, wxDefaultPosition, wxSize(5, 20));

		Buttons->Add(Add, 1, wxEXPAND);
		Buttons->Add(Insert, 1, wxEXPAND);
		Buttons->Add(Delete, 1, wxEXPAND);
		Buttons->Add(Copy, 1, wxEXPAND);
		Buttons->Add(Paste, 1, wxEXPAND);
		Buttons->Add(PasteInsert, 1, wxEXPAND);

		ItemList->Add(Search, 0, wxEXPAND);
		ItemList->Add(SearchRecursive, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(List, 1, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(Item, 0, wxEXPAND);
		ItemList->Add(ItemCombo, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(Buttons, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(CopyAllToSelected, 0, wxEXPAND);
	}
};

class AGE_AreaTT84
{
private:
	wxGridSizer *Buttons;
	wxBoxSizer *ItemList, *UsedItems_H, *Item_H;
	wxStaticText *UsedItems_T;
public:
	AGE_AreaTT84() {}
	virtual ~AGE_AreaTT84() {}

	wxStaticBoxSizer *Area;
	wxTextCtrl *Search, *SearchRecursive;
	wxListBox *List;
	TextCtrl_Long *Item, *Mode, *UsedItems;
	ComboBox_Plus1 *ItemCombo;
	wxOwnerDrawnComboBox *ModeCombo;
	wxButton *Copy, *Paste, *CopyAllToSelected;

	void CreateControls(wxScrolledWindow* &scroller, const wxString &itemName)
	{
		Area = new wxStaticBoxSizer(wxVERTICAL, scroller, "Connected Items");
		ItemList = new wxBoxSizer(wxVERTICAL);
		UsedItems_H = new wxBoxSizer(wxVERTICAL);
		UsedItems_T = new wxStaticText(scroller, wxID_ANY, " Used Ages/Units/Researches", wxDefaultPosition, wxSize(-1, 15), wxALIGN_LEFT);
		UsedItems = new TextCtrl_Long(scroller);

		Search = new wxTextCtrl(scroller, wxID_ANY);
		SearchRecursive = new wxTextCtrl(scroller, wxID_ANY);
		List = new wxListBox(scroller, wxID_ANY, wxDefaultPosition, wxSize(10, 100), 0, NULL, wxLB_EXTENDED);
		Item_H = new wxBoxSizer(wxHORIZONTAL);
		Item = new TextCtrl_Long(scroller);
		ItemCombo = new ComboBox_Plus1(scroller, Item);
		ModeCombo = new wxOwnerDrawnComboBox(scroller, wxID_ANY, "", wxDefaultPosition, wxSize(0, 20), 0, NULL, wxCB_READONLY);
		Mode = new TextCtrl_Long(scroller);
		Buttons = new wxGridSizer(2, 0, 0);
		Copy = new wxButton(scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(5, 20));
		Paste = new wxButton(scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(5, 20));
		CopyAllToSelected = new wxButton(scroller, wxID_ANY, "Copy all to selected " + itemName, wxDefaultPosition, wxSize(5, 20));

		ModeCombo->Append("Age");
		ModeCombo->Append("Building");
		ModeCombo->Append("Unit");
		ModeCombo->Append("Research");
		ModeCombo->SetSelection(0);

		Buttons->Add(Copy, 1, wxEXPAND);
		Buttons->Add(Paste, 1, wxEXPAND);

		Item_H->Add(Item, 2, wxEXPAND);
		Item_H->Add(2, -1);
		Item_H->Add(Mode, 1, wxEXPAND);

		ItemList->Add(Search, 0, wxEXPAND);
		ItemList->Add(SearchRecursive, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(List, 1, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(Item_H, 0, wxEXPAND);
		ItemList->Add(ItemCombo, 0, wxEXPAND);
		ItemList->Add(ModeCombo, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(Buttons, 0, wxEXPAND);
		ItemList->Add(-1, 2);
		ItemList->Add(CopyAllToSelected, 0, wxEXPAND);

		UsedItems_H->Add(UsedItems_T, 0, wxEXPAND);
		UsedItems_H->Add(UsedItems, 0, wxEXPAND);
		Area->Add(UsedItems_H, 0, wxEXPAND);
		Area->Add(-1, 2);
		Area->Add(ItemList, 0, wxEXPAND);
	}
};