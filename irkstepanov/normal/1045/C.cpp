#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 200500;

vector<int> g[nmax];
int ret[nmax];
int tin[nmax];
int timer = 0;
bool used[nmax];
int par[nmax];
int rev[nmax];

vector<int> tree[nmax];

void dfs(int v, int p) {
    used[v] = true;
    par[v] = p;
    tin[v] = timer++;
    rev[tin[v]] = v;
    ret[v] = tin[v];
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            dfs(to, v);
            tree[v].pb(to);
            ret[v] = min(ret[v], ret[to]);
        } else {
            ret[v] = min(ret[v], tin[to]);
        }
    }
}

int tout[nmax];
const int rmax = 20;
int wh[rmax][nmax];
int shifts[rmax][nmax];

void dfs2(int v) {
    tin[v] = timer++;
    for (int to : tree[v]) {
        dfs2(to);
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
        if (!ancestor(shifts[r][u], v)) {
            u = shifts[r][u];
        }
    }
    return shifts[0][u];
}

int get(int v, int w) {
    if (ancestor(v, w)) {
        return 0;
    }
    int ans = 0;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(wh[r][v], w)) {
            ans += (1 << r);
            v = wh[r][v];
        }
    }
    return ans + 1;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0);

    for (int i = 0; i < n; ++i) {
        if (ret[i] == tin[i]) {
            ret[i] = par[i];
        } else {
            ret[i] = rev[ret[i]];
        }
    }

    timer = 0;
    dfs2(0);

    for (int v = 0; v < n; ++v) {
        wh[0][v] = ret[v];
        shifts[0][v] = par[v];
    }

    for (int r = 0; r + 1 < rmax; ++r) {
        for (int v = 0; v < n; ++v) {
            int t = wh[r][v];
            wh[r + 1][v] = wh[r][t];
            t = shifts[r][v];
            shifts[r + 1][v] = shifts[r][t];
        }
    }
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int w = lca(u, v);
        cout << get(u, w) + get(v, w) << "\n";
    }

}