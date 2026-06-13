#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
public:
int bookID;
string title;
string author;
bool issued;
Book(int id, string t, string a) {
bookID = id;
title = t;
author = a;
issued = false;
}
};
class Library {
private;
vector<Book> books;
public:
    void addBook();
    void displayBooks();
    void searchByTitle();
    void searchByAuthor();
    void issueBook();
    void returnBook();
};

void Library::addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "\nBook Added Successfully!\n";
}

void Library::displayBooks() {
    if (books.empty()) {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (auto &b : books) {
        cout << "\nBook ID : " << b.bookID;
        cout << "\nTitle   : " << b.title;
        cout << "\nAuthor  : " << b.author;
        cout << "\nStatus  : " << (b.issued ? "Issued" : "Available");
        cout << "\n---------------------";
    }
}

void Library::searchByTitle() {
    string title;
    bool found = false;

    cin.ignore();
    cout << "\nEnter Book Title: ";
    getline(cin, title);

    for (auto &b : books) {
        if (b.title == title) {
            cout << "\nBook Found!";
            cout << "\nID: " << b.bookID;
            cout << "\nAuthor: " << b.author;
            cout << "\nStatus: " << (b.issued ? "Issued" : "Available");
            found = true;
        }
    }

    if (!found)
        cout << "\nBook Not Found!";
}

void Library::searchByAuthor() {
    string author;
    bool found = false;

    cin.ignore();
    cout << "\nEnter Author Name: ";
    getline(cin, author);

    for (auto &b : books) {
        if (b.author == author) {
            cout << "\nBook ID : " << b.bookID;
            cout << "\nTitle   : " << b.title;
            cout << "\nStatus  : " << (b.issued ? "Issued" : "Available");
            cout << "\n---------------------";
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Books Found!";
}

void Library::issueBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (auto &b : books) {
        if (b.bookID == id) {
            found = true;

            if (b.issued)
                cout << "\nBook Already Issued!";
            else {
                b.issued = true;
                cout << "\nBook Issued Successfully!";
            }
            break;
        }
    }

    if (!found)
        cout << "\nBook Not Found!";
}

void Library::returnBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (auto &b : books) {
        if (b.bookID == id) {
            found = true;

            if (!b.issued)
                cout << "\nBook Was Not Issued!";
            else {
                b.issued = false;
                cout << "\nBook Returned Successfully!";
            }
            break;
        }
    }

    if (!found)
        cout << "\nBook Not Found!";
}

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search by Title";
        cout << "\n4. Search by Author";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                lib.searchByTitle();
                break;
            case 4:
                lib.searchByAuthor();
                break;
            case 5:
                lib.issueBook();
                break;
            case 6:
                lib.returnBook();
                break;
            case 7:
                cout << "\nExiting Program...";
                break;
            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 7);

    return 0;
}
