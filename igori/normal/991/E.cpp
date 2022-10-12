#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnk[50][50];

void rec(int x, vector<int> &cnt, ll &ans, ll ways, ll placed)
{
    //cout << x << " " << ans << " " << ways << endl;
    if (x == 0)
    {
        if (cnt[x] == 0)
            ans += ways;
        for (int sel = 1; sel <= cnt[x]; sel++)
        {
            ans += ways * cnk[placed + sel - 1][sel];
        }
        return;
    }
    if (cnt[x] == 0)
        rec(x - 1, cnt, ans, ways, placed);
    for (int sel = 1; sel <= cnt[x]; sel++)
    {
        rec(x - 1, cnt, ans, ways * cnk[placed + sel][sel], placed + sel);
    }
}

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> cnt(10);
    for (int i = 0; i < s.size(); i++) cnt[s[i] - '0']++;

    rec(9, cnt, ans, 1, 0);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 50; i++) cnk[i][i] = cnk[i][0] = 1;
    for (int i = 1; i < 50; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
        }
    }

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}