#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[505][5050];
array<int, 3> pa[505][5050];

void solve()
{
    ll m, s;
    cin >> m >> s;
    for (int i = 0; i < 505; i++)
        for (int j = 0; j < 5050; j++)
            dp[i][j] = 1e9;
    vector<pair<int, pair<int, int> > > q;
    q.push_back({0, {0, 0}});
    dp[0][0] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        auto it = q[i];
        int r = it.second.first;
        int si = it.second.second;
        for (int w = 0; w < 10; w++)
        {
            if (si + w <= s && dp[(r * 10 + w) % m][si + w] == 1e9)
            {
                dp[(r * 10 + w) % m][si + w] = dp[r][si] + 1;
                pa[(r * 10 + w) % m][si + w] = {r, si, w};
                q.push_back({dp[r][si] + 1, {(r * 10 + w) % m, si + w}});
            }
        }
    }
    if (dp[0][s] == 1e9)
    {
        cout << -1;
        return;
    }
    //cerr << dp[0][s] << "\n";
    vector<int> ans;
    int md = 0, si = s;
    for (int i = 0; i < dp[0][s]; i++)
    {
        array<int, 3> x = pa[md][si];
        ans.push_back(x.at(2));
        md = x.at(0), si = x.at(1);
    }
    reverse(ans.begin(), ans.end());
    for (auto e : ans) cout << e;
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