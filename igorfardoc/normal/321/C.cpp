#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int> > g;
int sz[100001];
vector<bool> used;
vector<char> res;

void dfs(int v, int p)
{
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p || used[u])
        {
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int find_centroid(int v, int p, int all1)
{
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(u == p || used[u])
        {
            continue;
        }
        if(sz[u] * 2 >= sz[all1])
        {
            return find_centroid(u, v, all1);
        }
    }
    return v;
}

void solve(int v, char char1)
{
    dfs(v, -1);
    int c = find_centroid(v, -1, v);
    res[c] = char1;
    used[c] = true;
    for(int i = 0; i < g[c].size(); i++)
    {
        if(used[g[c][i]])
        {
            continue;
        }
        solve(g[c][i], char1 + 1);
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
    cin >> n;
    g.resize(n);
    res.resize(n);
    used.assign(n, false);
    for(int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    solve(0, 'A');
    for(int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
}