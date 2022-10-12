#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void dfs(int v, vi &col, vi &ord, vvi &inv_graph)
{
    col[v] = -1;
    for (auto u : inv_graph[v]) if (col[u] == 0)
        dfs(u, col, ord, inv_graph);
    ord.push_back(v);
}

void dfs(int v, vi &col, int fl, vvi &graph)
{
    col[v] = fl;
    for (auto u : graph[v]) if (col[u] == -1)
        dfs(u, col, fl, graph);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> v(m), u(m);
    for (int i = 0; i < m; i++) cin >> v[i] >> u[i], v[i]--, u[i]--;

    if (0 && h == 2)
    {
        vector<int> cnt(n);
        for (int i = 0; i < m; i++)
        {
            cnt[v[i]]++;
            cnt[u[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] == 0)
            {
                cout << 1 << "\n";
                cout << i + 1 << "\n";
                return 0;
            }
        }
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << i + 1 << " ";
        }
        return 0;
    }

    vector<vector<int> > graph(n);
    vector<vector<int> > inv_graph(n);

    for (int i = 0; i < m; i++)
    {
        if ((a[v[i]] + 1) % h == a[u[i]])
            graph[v[i]].push_back(u[i]), inv_graph[u[i]].push_back(v[i]);
        if ((a[u[i]] + 1) % h == a[v[i]])
            graph[u[i]].push_back(v[i]), inv_graph[v[i]].push_back(u[i]);
    }

    vector<int> col(n);
    vector<int> ord;
    int fl = 0;

    for (int i = 0; i < n; i++)
    {
        if (col[i] == 0)
        {
            dfs(i, col, ord, inv_graph);
        }
    }
    reverse(all(ord));
    for (auto i : ord)
    {
        if (col[i] == -1)
        {
            dfs(i, col, fl, graph);
            fl++;
        }
    }

    vector<int> cnt_out(fl);
    vector<int> sz(fl);
    for (int i = 0; i < m; i++)
    {
        if (col[v[i]] != col[u[i]] && (a[v[i]] + 1) % h == a[u[i]])
            cnt_out[col[v[i]]]++;
        if (col[v[i]] != col[u[i]] && (a[u[i]] + 1) % h == a[v[i]])
            cnt_out[col[u[i]]]++;
    }
    for (int i = 0; i < n; i++)
    {
        sz[col[i]]++;
    }

    int opt = -1;
    for (int i = 0; i < fl; i++)
    {
        if (cnt_out[i] == 0)
        {
            if (opt == -1) opt = i;
            if (sz[i] < sz[opt]) opt = i;
        }
    }

    cout << sz[opt] << "\n";
    for (int i = 0; i < n; i++)
    {
        if (col[i] == opt)
        {
            cout << i + 1 << " ";
        }
    }
}