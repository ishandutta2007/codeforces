#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<vector<int> > h;
vector<char> used;
vector<int> mt;

const ll inf = 1e18;

bool dfs(int v)
{
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : h[v]) {
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

struct edge
{
    int from, to;
    ll cap, flow;
};

vector<edge> edges;
vector<vector<int> > g;
int s, t;
int vsize;
vector<int> ptr, level;

void add_edge(int u, int v, ll cap)
{
    g[u].pb(sz(edges));
    edges.pb({u, v, cap, 0});
    g[v].pb(sz(edges));
    edges.pb({v, u, 0, 0});
}

bool bfs()
{
    ptr.assign(vsize, 0);
    level.assign(vsize, vsize);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && level[edges[e].to] == vsize) {
                level[edges[e].to] = level[v] + 1;
                q.push(edges[e].to);
            }
        }
    }
    return level[t] != vsize;
}

ll dfs(int v, ll flow)
{
    if (v == t) {
        return flow;
    }
    for (int i = ptr[v]; i < sz(g[v]); ++i) {
        int e = g[v][i];
        if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
            ll k = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
            if (k) {
                edges[e].flow += k;
                edges[e ^ 1].flow -= k;
                return k;
            }
        }
        ++ptr[v];
    }
    return 0;
}

ll dinic()
{
    ll ans = 0;
    while (bfs()) {
        ll x;
        while ((x = dfs(s, inf))) {
            ans += x;
        }
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    h.resize(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int to;
            cin >> to;
            --to;
            h[i].pb(to);
        }
    }

    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    mt.assign(n, -1);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (dfs(i)) {
                used.assign(n, false);
            }
        }
    }

    vector<int> el(n);
    for (int i = 0; i < n; ++i) {
        el[mt[i]] = i;
    }

    vsize = n + 2;
    g.resize(vsize);
    s = vsize - 2, t = vsize - 1;

    for (int i = 0; i < n; ++i) {
        for (int to : h[i]) {
            if (mt[to] != i) {
                add_edge(mt[to], i, inf);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        add_edge(s, i, c[i] + ll(1e9));
        add_edge(i, t, ll(1e9));
    }
    ll ans = dinic() - ll(1e9) * ll (n);
    cout << ans << "\n";

}