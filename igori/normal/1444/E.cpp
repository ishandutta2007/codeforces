#include <bits/stdc++.h>

using namespace std;

const int N = 109;

vector<int> solve(vector<vector<int> > a, vector<int> &w)
{
    int n = a.size();
    vector<int> res(N, 1);
    for (int j = N - 1; j >= 0; j--)
    {
        res[j] = 0;
        int t = 1;
        vector<int> bad(n, 1);
        for (int b = N - 1; b >= 0; b--)
        {
            if (res[b])
            {
                vector<int> g;
                int id = -1, cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (!bad[i]) continue;
                    vector<int> cur;
                    for (int j = b; j >= 0; j--)
                        cur.push_back(a[i][j]);
                    if (g.size() == 0 || cur > g)
                    {
                        g = cur;
                        id = i;
                    }
                    if (cur[0]) cnt++;
                }
                if (id >= 0 && g[0] == 0)
                {
                    bad[id] = 0;
                }
                if (cnt >= 2)
                {
                    t = 0;
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (bad[i] && a[i][b])
                        t = 0;
                }
            }
        }
        if (accumulate(bad.begin(), bad.end(), 0))
            t = 0;
        if (!t)
            res[j] = 1;
    }
    int t = 1;
    vector<int> bad(n, 1);
    for (int b = N - 1; b >= 0; b--)
    {
        if (res[b])
        {
            vector<int> g;
            int id = -1, cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (!bad[i]) continue;
                vector<int> cur;
                for (int j = b; j >= 0; j--)
                    cur.push_back(a[i][j]);
                if (g.size() == 0 || cur > g)
                {
                    g = cur;
                    id = i;
                }
                if (cur[0]) cnt++;
            }
            if (id >= 0 && g[0] == 0)
            {
                bad[id] = 0;
                w[id] = b;
            }
            if (cnt >= 2)
            {
                t = 0;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (bad[i] && a[i][b])
                    t = 0;
            }
        }
    }
    return res;
}

vector<int> g[N];

vector<int> d[N];
int x[N], y[N];
int c[N];

void dfs(int v, int p)
{
    vector<vector<int> > a;
    vector<int> w;
    for (auto e : g[v])
    {
        int u = x[e] + y[e] - v;
        if (u != p)
        {
            dfs(u, v);
            a.push_back(d[u]);
            w.push_back(0);
        }
    }
    d[v] = solve(a, w);
    int pnt = 0;
    for (auto e : g[v])
    {
        if (x[e] + y[e] - v != p)
        {
            c[e] = w[pnt++] + 1;
        }
    }
}

void dfs(int v, int p, vector<int> &z)
{
    z[v] = 0;
    for (auto e : g[v])
    {
        int u = x[e] + y[e] - v;
        if (u != p)
        {
            dfs(u, v, z);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        g[x[i]].push_back(i);
        g[y[i]].push_back(i);
    }
    dfs(0, 0);
    vector<int> z(n, 1);
    while (1)
    {
        if (accumulate(z.begin(), z.end(), 0) == 1)
        {
            int v = 0;
            for (int i = 0; i < n; i++) if (z[i]) v = i;
            cout << "! " << v + 1 << endl;
            return 0;
        }
        int id = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (z[x[i]] && z[y[i]] && (id == -1 || c[id] < c[i]))
                id = i;
        }
        cout << "? " << x[id] + 1 << " " << y[id] + 1 << endl;
        int r;
        cin >> r;
        r--;
        if (r == y[id])
        {
            dfs(x[id], y[id], z);
        }
        else
        {
            dfs(y[id], x[id], z);
        }
    }
}