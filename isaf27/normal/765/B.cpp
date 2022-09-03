#include <bits/stdc++.h>

using namespace std;

string s;
int a[26];

int main()
{
    cin >> s;
    for (int i = 0; i < 26; i++)
        a[i] = -1;
    for (int i = 0; i < s.size(); i++)
        if (a[s[i] - 'a'] == -1)
            a[s[i] - 'a'] = i;
    int to = 26;
    for (int i = 0; i < 26; i++)
        if (a[i] == -1)
        {
            to = i;
            break;
        }
    for (int i = to; i < 26; i++)
        if (a[i] != -1)
        {
            cout << "NO";
            return 0;
        }
    for (int i = 1; i < to; i++)
        if (a[i - 1] > a[i])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}