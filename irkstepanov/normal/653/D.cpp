#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long double ld;

const ld eps = 1e-8;
const int inf = 1e9;
const int ops = 100;

struct edge
{
    int from, to, cap, flow;
    edge() {}
    edge(int u, int v, int c)
    {
        from = u, to = v;
        cap = c;
        flow = 0;
    }
};

vector<edge> edges;
vector<vector<int> > g;
vector<char> used;
int n, s, t;

int dfs(int v, int flow, int k)
{
    used[v] = true;
    if (v == t) {
        return flow;
    }
    for (int e : g[v]) {
        if (edges[e].cap - edges[e].flow >= k && !used[edges[e].to]) {
            int x = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow), k);
            if (x) {
                edges[e].flow += x;
                edges[e ^ 1].flow -= x;
                return x;
            }
        }
    }
    return 0;
}

int solve()
{
    int ans = 0;
    for (int k = 20; k >= 0; --k) {
        int x;
        used.assign(n, false);
        while ((x = dfs(s, inf, 1 << k))) {
            ans += x;
            used.assign(n, false);
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("in");

    int m, x;
    cin >> n >> m >> x;
    s = 0, t = n - 1;
    g.resize(n);
    edges.resize(2 * m);
    vector<ld> cap(m);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        cap[i] = c;
        --u, --v;
        edges[i * 2] = edge(u, v, c);
        g[u].pb(i * 2);
        edges[i * 2 + 1] = edge(v, u, 0);
        g[v].pb(2 * i + 1);
    }

    ld lf = 0, rg = inf;
    for (int step = 0; step < ops; ++step) {
        ld md = (lf + rg) / 2;
        for (int i = 0; i < 2 * m; i += 2) {
            edges[i].cap  = (int)min((cap[i >> 1] / md), (ld)x);
        }
        int flow = solve();
        for (int i = 0; i < 2 * m; ++i) {
            edges[i].flow = 0;
        }
        if (flow >= x) {
            lf = md;
        } else {
            rg = md;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << (ld)(x) * lf << "\n";

}