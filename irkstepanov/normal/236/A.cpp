#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    int kol = 0;
    int m[30];
    for (int i = 0; i < 30; i++)
        m[i] = 0;

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i] - 'a'] == 0) {m[s[i] - 'a'] = 1; ++kol;}
    }

    if (kol % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";

}