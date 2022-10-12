#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] == '0')
        {
            cout << i + 1 << " " << s.size() << " " << i + 2 << " " << s.size() << "\n";
            return;
        }
    }
    for (int i = s.size() / 2; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            return;
        }
    }
    cout << 1 << " " << s.size() / 2 * 2 << " " << 1 << " " << s.size() / 2 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}