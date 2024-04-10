#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

struct edge {
    int u, v;
    ll c;
    bool operator<(const edge& other) const {
        return c < other.c;
    }
};

vector<int> parent;
vector<int> size;

int get(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = get(parent[v]);
}

void unite(int a, int b) {
    a = get(a), b = get(b);
    if (size[a] < size[b]) {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}

const int rmax = 18;

vector<vector<int> > p;
vector<vector<ll> > maxx;
vector<vector<edge> > g;
vector<int> tin, tout;
int timer = 0;

void dfs(int v, int par) {
    tin[v] = timer++;
    p[v][0] = par;
    for (edge& e : g[v]) {
        if (e.v != par) {
            maxx[e.v][0] = e.c;
            dfs(e.v, v);
        }
    }
    tout[v] = timer++;
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(p[u][r], v)) {
            u = p[u][r];
        }
    }
    return p[u][0];
}

ll getMax(int u, int v) {
    assert(u != v && ancestor(v, u));
    ll ans = 0;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(p[u][r], v)) {
            ans = max(ans, maxx[u][r]);
            u = p[u][r];
        }
    }
    return max(ans, maxx[u][0]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        edges[i] = {u, v, c};
    }
    sort(all(edges));

    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    ll total = 0;
    vector<edge> useful;

    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        u = get(u), v = get(v);
        if (u == v) {
            continue;
        }
        unite(u, v);
        total += edges[i].c;
        useful.pb(edges[i]);
    }

    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(get(i));
    }

    if (sz(s) == 1) {
        p = vector<vector<int> >(n, vector<int>(rmax));
        maxx = vector<vector<ll> >(n, vector<ll>(rmax));
        g.resize(n);
        for (edge& e : useful) {
            int u = e.u, v = e.v;
            ll c = e.c;
            g[u].pb({u, v, c});
            g[v].pb({v, u, c});
        }
        tin.resize(n);
        tout.resize(n);
        dfs(0, 0);
        for (int r = 0; r + 1 < rmax; ++r) {
            for (int v = 0; v < n; ++v) {
                int t = p[v][r];
                p[v][r + 1] = p[t][r];
                maxx[v][r + 1] = max(maxx[v][r], maxx[t][r]);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (sz(s) > 2) {
            cout << "-1\n";
            continue;
        }
        if (sz(s) == 2) {
            a = get(a), b = get(b);
            if (a == b) {
                cout << "-1\n";
                continue;
            }
            cout << total << "\n";
            continue;
        }
        int w = lca(a, b);
        ll ans = 0;
        if (a != w) {
            ans = max(ans, getMax(a, w));
        }
        if (b != w) {
            ans = max(ans, getMax(b, w));
        }
        cout << total - ans << "\n";
    }

}