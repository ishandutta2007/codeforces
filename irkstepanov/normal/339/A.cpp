#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int a1 = 0, a2 = 0, a3 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') ++a1;
        else if (s[i] == '2') ++a2;
        else if (s[i] == '3') ++a3;
    }

    if (a1) {cout << 1; --a1;}
    else if (a2) {cout << 2; --a2;}
    else if (a3) {cout << 3; --a3;}

    for (int i = 0; i < a1; i++)
        cout << '+' << 1;
    for (int i = 0; i < a2; i++)
        cout << '+' << 2;
    for (int i = 0; i < a3; i++)
        cout << '+' << 3;

}