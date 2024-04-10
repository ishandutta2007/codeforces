#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int p[100000];
int h[100000];
int sadmax[100000];
int narod[100000];

bool dfs(int v, int p1, vector<vector<int> > & g)
{
    int sadall = 0;
    narod[v] = p[v];
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p1)
        {
            continue;
        }
        if(dfs(u, v, g))
        {
            sadall += sadmax[u];
            narod[v] += narod[u];
        }
        else
        {
            return false;
        }
    }
    if((abs(h[v]) % 2 != narod[v] % 2) || abs(narod[v]) < abs(h[v]))
    {
        return false;
    }
    int sad = (narod[v] - h[v]) / 2;
    if(sad - p[v] > sadall)
    {
        return false;
    }
    sadmax[v] = min(p[v] + sadall, sad);
    return true;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        cin >> n >> m;
        vector<vector<int> > g;
        g.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(dfs(0, -1, g))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
// 6 10 14 15 33
//51