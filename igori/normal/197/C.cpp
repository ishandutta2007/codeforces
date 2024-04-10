#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)

void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string res = "";
    res += s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= res.back()) res += s[i];
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}