#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> g;
vector<bool> dp;
int res;

void dfs(int v, int p)
{
    int amounttrue = 0;
    int amountfalse = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p)
        {
            continue;
        }
        dfs(u, v);
        if(dp[u])
        {
            ++amounttrue;
        }
        else
        {
            ++amountfalse;
        }
    }
    if(amountfalse == 0)
    {
        dp[v] = false;
    }
    else
    {
        if(v != 0)
        {
            res += amountfalse - 1;
        }
        
        dp[v] = true;
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
        cin >> n;
        g.assign(n, vector<int>(0));
        dp.resize(n);
        for(int i = 0; i < n - 1; i++)
        {
            int v, u;
            cin >> v >> u;
            --u;
            --v;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        res = 0;
        dfs(0, -1);
        int amount = 0;
        for(int i = 0; i < g[0].size(); i++)
        {
            int u = g[0][i];
            if(!dp[u])
            {
                ++amount;
            }
        }
        res += max(1, amount);
        cout << res << '\n';
    }
}