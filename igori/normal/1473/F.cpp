#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e9;

vector<int> to, cap, f;
vector<vector<int> > g;
vector<int> pnt, dist;

void Add_edge(int from, int t, int c)
{
    //cout << from << " " << t << " " << c << endl;
    g[from].push_back(to.size());
    to.push_back(t), cap.push_back(c), f.push_back(0);
    g[t].push_back(to.size());
    to.push_back(from), cap.push_back(0), f.push_back(0);
}

int dfs(int v, int want)
{
    if (v == g.size() - 1) return want;
    if (want == 0) return want;
    for (; pnt[v] < g[v].size(); pnt[v]++)
    {
        int e = g[v][pnt[v]];
        if (dist[to[e]] == dist[v] + 1 && f[e] < cap[e])
        {
            int go = dfs(to[e], min(want, cap[e] - f[e]));
            if (go > 0)
            {
                f[e] += go;
                f[e ^ 1] -= go;
                return go;
            }
        }
    }
    return 0;
}

ll Flow()
{
    dist = vector<int>(g.size(), inf);
    pnt = vector<int>(g.size(), 0);
    vector<int> q = {0};
    dist[0] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        for (auto e : g[q[i]])
        {
            if (f[e] < cap[e] && dist[to[e]] == inf)
            {
                dist[to[e]] = dist[q[i]] + 1;
                q.push_back(to[e]);
            }
        }
    }
    if (dist[g.size() - 1] == inf) return 0;
    int z = dfs(0, inf);
    ll ans = 0;
    while (z > 0)
    {
        ans += z;
        z = dfs(0, inf);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int opt = 0;
    for (int i = 0; i < n; i++)
        opt += max(0, b[i]);

    g = vector<vector<int> > (n + 2);

    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
            Add_edge(0, i + 1, b[i]);
        if (b[i] < 0)
            Add_edge(i + 1, n + 1, -b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> divs(a[i] + 1);
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] % a[j] == 0 && divs[a[j]] == 0)
                Add_edge(i + 1, j + 1, inf), divs[a[j]] = 1;
        }
    }
    ll ans = 0;
    int z = Flow();
    while (z)
    {
        ans += z;
        z = Flow();
    }
    cout << opt - ans << "\n";
}