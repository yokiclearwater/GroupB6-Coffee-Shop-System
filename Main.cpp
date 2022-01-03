#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Headers/Console.h"
#include "Headers/Login.h"
#include "Headers/Coffee.h"
#include "Headers/Menu.h"
using namespace std;

int main() {
    int choice;
    UserList *ul = readUserInfo();

    string welcome="***** WELCOME TO COFFEE MANAGEMENT SYSTEM *****";
    clearScreen();
    cout<<"\n\t";
    int n = welcome.size();
    sleepTime(500);
    for(int ii = 0; ii < n; ii++)
    {
        cout << welcome[ii];
        sleepTime(70);
    }

    loadingbar();

    do {
        choice = loginOrSignup();
    } while(choice < 1 || choice > 3);

    while(choice >= 1 && choice <= 2) {
        if(choice == 1) {
            UserInfo *U1 = logIn();
            if(U1) {
                cout << "Login Successfully!!" << endl;
                mainMenu(U1);
            }
        }
        else if(choice == 2) {
            signUp(ul);
        }
        choice = loginOrSignup();
    }

    return 0;
}