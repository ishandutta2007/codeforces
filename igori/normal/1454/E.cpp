#include <bits/stdc++.h>

using namespace std;

void dfs(int v, int p, vector<vector<int> > &g, vector<int> &c, vector<int> &par, vector<int> &mark, int &t)
{
    if (t)
        return;
    par[v] = p;
    c[v] = 1;
    for (auto u : g[v]) if (u != p)
    {
        if (c[u] == 0)
        {
            dfs(u, v, g, c, par, mark, t);
        }
        else if (c[u] == 1)
        {
            mark[u] = 1;
            int fl = v;
            while (mark[fl] == 0)
            {
                mark[fl] = 1;
                fl = par[fl];
            }
            t = 1;
            return;
        }
    }
    c[v] = 2;
}

long long dfs2(int v, int p, vector<vector<int> > &g, vector<int> &mark)
{
    long long res = 1;
    for (auto u : g[v]) if (mark[u] == 0 && u != p)
    {
        res += dfs2(u, v, g, mark);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> mark(n);
        int t = 0;
        vector<vector<int> > g(n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        long long ans = 0;
        vector<int> c(n), p(n);
        dfs(0, 0, g, c, p, mark, t);
        vector<long long> s;
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
            {
                s.push_back(dfs2(i, i, g, mark));
            }
        }
        long long si = accumulate(s.begin(), s.end(), 0ll);
        for (int i = 0; i < s.size(); i++)
        {
            ans = ans + s[i] * (si - s[i]) + s[i] * (s[i] - 1) / 2;
        }
        cout << ans << "\n";
    }
}