#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> x;
    for (int i = 0; i < s.size(); i++)
        x.insert(s[i]);
    int kol = x.size();
    cout << ((kol % 2) ? "IGNORE HIM!" : "CHAT WITH HER!");
    return 0;
}