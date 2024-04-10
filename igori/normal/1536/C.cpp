#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<pair<int, int>, int> mm;
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'K') x++;
            else y++;
            int g = __gcd(x, y);
            mm[{x / g, y / g}]++;
            cout << mm[{x / g, y / g}] << "\n";
        }
    }
}