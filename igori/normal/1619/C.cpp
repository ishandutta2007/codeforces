#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string a, s;
    cin >> a >> s;
    string b = "";
    while (s.size())
    {
        if (a.size() == 0)
            a.push_back('0');
        if (a.back() <= s.back())
        {
            b.push_back(s.back() - a.back() + '0');
            a.pop_back();
            s.pop_back();
        }
        else
        {
            if (s.size() == 1)
            {
                cout << -1 << "\n";
                return;
            }
            int x = s[s.size() - 2];
            if (x != '1')
            {
                cout << -1 << "\n";
                return;
            }
            b.push_back(s.back() - a.back() + '0' + 10);
            s.pop_back();
            s.pop_back();
            a.pop_back();
        }
    }
    if (a.size())
    {
        cout << -1 << "\n";
        return;
    }
    while (b.size() > 1 && b.back() == '0') b.pop_back();
    reverse(b.begin(), b.end());
    cout << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}