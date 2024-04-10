#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<int> > r(4);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int a;
        cin >> a;
        if (s == "00") r[0].push_back(a);
        if (s == "01") r[1].push_back(a);
        if (s == "10") r[2].push_back(a);
        if (s == "11") r[3].push_back(a);
    }
    for (int i = 0; i < 4; i++)
    {
        sort(r[i].rbegin(), r[i].rend());
    }
    ll ans = 0;
    for (int i = 0; i < r[3].size(); i++)
        ans += r[3][i];
    for (int i = 0; i < min(r[1].size(), r[2].size()); i++)
        ans += r[1][i] + r[2][i];
    for (int i = min(r[1].size(), r[2].size()); i < max(r[1].size(), r[2].size()); i++)
    {
        if (i < r[1].size()) r[0].push_back(r[1][i]);
        if (i < r[2].size()) r[0].push_back(r[2][i]);
    }
    for (int i = 0; i < 4; i++)
    {
        sort(r[i].rbegin(), r[i].rend());
    }
    for (int i = 0; i < min(r[3].size(), r[0].size()); i++)
        ans += r[0][i];
    cout << ans << "\n";
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