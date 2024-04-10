#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 5e5 + 20;
int n, m, k;

int col[N];
vector <int> g[N];

struct edge {
    int u, v;
} e[N];

int ans;

int dead[N];
map <pii, bool> vis;
map <pii, vector <pii>> edges_between;

int par[N], f[N];
vector <pii> parhistory, fhistory;

int root (int v, bool save_history = 0) {
    if (par[v] < 0) return v;

    if (save_history) {
        parhistory.pb({v, par[v]});
        fhistory.pb({v, f[v]});
    }

    int res = root(par[v], save_history);
    f[v] ^= f[par[v]];
    par[v] = res;

    return res;
}

inline int merge (int u, int v, bool save_history = 0) {
    int ru = root(u, save_history), rv = root(v, save_history);

    if (ru == rv) {
        if (f[u] == f[v]) return -1;
        return 0;
    }

    if (save_history) {
        parhistory.pb({ru, -1});
        fhistory.pb({ru, 0});
    }

    if (f[u] == f[v]) f[ru] = 1;
    else f[ru] = 0;

    par[ru] = rv;

    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> col[i], col[i]--;

    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v;
        e[i].u--, e[i].v--;

        g[e[i].u].pb(e[i].v);
        g[e[i].v].pb(e[i].u);
    }

    memset(par, -1, sizeof par);


    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v;

        if (col[u] == col[v]) {
            if (merge(u, v) == -1) dead[col[u]] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) cnt += (!dead[i]);

    for (int i = 0; i < n; i++) root(i);

    ans = 1ll * cnt * (cnt - 1) / 2;

    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v;

        if (col[u] == col[v]) continue;
        if (dead[col[u]] || dead[col[v]]) continue;

        int x = col[u], y = col[v];
        if (x > y) swap(x, y);

        edges_between[{x, y}].pb({u, v});
            
        vis[{x, y}] = 1;
    }

    for (auto p : vis) {
        int x = p.F.F, y = p.F.S;
        ans--;
    
        bool ok = 1;
        for (pii ed : edges_between[{x, y}]) {
            if (merge(ed.F, ed.S, 1) == -1) {
                ok = 0;
                break;
            }
        }

        while (parhistory.size()) {
            pii p = parhistory.back();
            par[p.F] = p.S;
            parhistory.pop_back();
        }

        while (fhistory.size()) {
            pii p = fhistory.back();
            f[p.F] = p.S;
            fhistory.pop_back();
        }

        ans += ok;
    }

    cout << ans << '\n';
}