#include <bits/stdc++.h>

using namespace std;

void dfs(int v, int p, int d, vector<vector<int> > &g, vector<int> &fl)
{
    int tr = d <= 2;
    for (auto u : g[v]) if (u != p)
    {
        dfs(u, v, d + 1, g, fl);
        if (fl[u] == 1)
            tr = 1;
    }
    if (tr == 0 && fl[v] == 0)
        fl[p] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> fl(n);
    dfs(0, 0, 0, g, fl);
    cout << accumulate(fl.begin() + 1, fl.end(), 0);
}