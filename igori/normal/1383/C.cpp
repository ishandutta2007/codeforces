#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<int> &c, vector<vector<int> > &g)
{
    c[v] = 1;
    for (auto u : g[v]) if (c[u] == 0) dfs(u, c, g);
}

void solve()
{
    int n, m = 20;
    string s, t;
    cin >> n >> s >> t;
    vector<int> go(m);
    vector<vector<int> > g(m);
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a', y = t[i] - 'a';
        go[x] |= (1 << y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> c(m);
    int res = 40;
    for (int i = 0; i < m; i++)
    {
        if (c[i] == 0)
        {
            dfs(i, c, g);
            res--;
        }
    }
    vector<int> dp(1 << m);
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        if (dp[i])
        {
            for (int j = 0; j < m; j++)
            {
                if (!(i & (1 << j)) && (go[j] & i) == 0)
                    dp[i + (1 << j)] = 1;
            }
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << res - ans << "\n";
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