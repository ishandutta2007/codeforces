#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> l, r;
vector<vector<int> > g;
vector<pair<ll, ll> > dp;

void dfs(int v, int p)
{
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p)
        {
            continue;
        }
        dfs(u, v);
    }
    dp[v].first = 0;
    dp[v].second = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p)
        {
            continue;
        }
        dp[v].first += max(abs(l[v] - l[u]) + dp[u].first, abs(l[v] - r[u]) + dp[u].second);
        dp[v].second += max(abs(r[v] - l[u]) + dp[u].first, abs(r[v] - r[u]) + dp[u].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        l.resize(n);
        r.resize(n);
        g.assign(n, vector<int>(0));
        for(int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        dp.resize(n);
        dfs(0, -1);
        cout << max(dp[0].first, dp[0].second) << '\n';
    }
}