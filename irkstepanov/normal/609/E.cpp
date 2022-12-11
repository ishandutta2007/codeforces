#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const ll inf = (ll) (1e9);

struct edge
{
    int to, from;
    ll cost;
    int id;
    bool operator<(const edge& other)
    {
        if (cost != other.cost) {
            return cost < other.cost;
        }
        if (to != other.to) {
            return to < other.to;
        }
        return from < other.from;
    }
};

int n, m;
vector<edge> edges;
vector<int> parent, size;
vector<vector<edge> > g;

int findSet(int v)
{
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void uniteSets(int a, int b)
{
    if (size[a] < size[b]) {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}

vector<vector<ll> > dp;
vector<vector<int> > par;
vector<int> height;
vector<int> tIn, tOut;
int timer = 0;

void dfs(int v, int p, ll len)
{
    tIn[v] = timer++;
    if (p == -1) {
        height[v] = 0;
    } else {
        height[v] = height[p] + 1;
        dp[v][0] = len;
        par[v][0] = p;
        for (int i = 1; i < 20; ++i) {
            if ((1 << i) <= height[v]) {
                par[v][i] = par[par[v][i - 1]][i - 1];
                dp[v][i] = max(dp[v][i - 1], dp[par[v][i - 1]][i - 1]);
            }
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i].from != p && g[v][i].to != p) {
            if (g[v][i].from == v) {
                dfs(g[v][i].to, v, g[v][i].cost);
            } else {
                dfs(g[v][i].from, v, g[v][i].cost);
            }
        }
    }
    tOut[v] = timer++;
}

bool ancestor(int u, int v)///u -- ancestor of v
{
    return tIn[u] <= tIn[v] && tOut[u] >= tOut[v];
}

ll lca(int u, int v)
{
    if (ancestor(u, v)) {
        ll ans = -inf;
        while (u != v) {
            int x = 0;
            for (int i = 1; i < 20; ++i) {
                if ((1 << i) <= height[v] && ancestor(u, par[v][i])) {
                    x = i;
                }
            }
            ans = max(ans, dp[v][x]);
            v = par[v][x];
        }
        return ans;
    }
    if (ancestor(v, u)) {
        return lca(v, u);
    }
    ll ans = -inf;
    while (!ancestor(u, v)) {
        int x = 0;
        for (int i = 0; i < 20; ++i) {
            if ((1 << i) <= height[u] && !ancestor(par[u][i], v)) {
                x = i;
            }
        }
        ans = max(ans, dp[u][x]);
        u = par[u][x];
    }
    ll ans1 = lca(u, v);
    return max(ans, ans1);
}

int main()
{

    //freopen("input.txt", "r", stdin);LOLS
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    scanf("%d%d", &n, &m);
    edges.resize(m);
    parent.resize(n);
    height.resize(n);
    tIn.resize(n), tOut.resize(n);
    g.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%I64d", &edges[i].to, &edges[i].from, &edges[i].cost);
        --edges[i].from;
        --edges[i].to;
        edges[i].id = i;
    }

    sort(all(edges));
    forn(i, n) {
        parent[i] = i;
    }

    int added = 0;
    ll ans = 0;
    vector<char> span(m, false);
    for (int i = 0; added != n - 1; ++i) {
        int u = findSet(edges[i].from), v = findSet(edges[i].to);
        if (u == v) {
            continue;
        }
        g[edges[i].from].pb(edges[i]);
        g[edges[i].to].pb(edges[i]);
        ++added;
        span[i] = true;
        ans += edges[i].cost;
        uniteSets(u, v);
    }

    dp.resize(n);
    par.resize(n);
    forn(i, n) {
        dp[i].assign(20, -inf);
        par[i].assign(20, -1);
    }

    height.assign(n, -1);
    dfs(0, -1, inf);

    vector<ll> out(m);

    for (int i = 0; i < m; ++i) {
        int v = edges[i].from, u = edges[i].to;
        if (span[i]) {
            out[edges[i].id] = ans;
            continue;
        }
        ll cost = edges[i].cost;
        ll x = lca(u, v);
        out[edges[i].id] = ans + cost - x;
    }

    for (int i = 0; i < m; ++i) {
        printf("%I64d\n", out[i]);
    }

}