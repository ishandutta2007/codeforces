#include <bits/stdc++.h>

using namespace std;

const int G = 18;
const int M = 200005;

struct path {
    int u, v, w;
    path(int u, int v, int w) : u(u), v(v), w(w) {}
};

int par[G][M];
int st[M], fi[M], d[M], cnt;

vector<int> adj[M];

vector<path> pv[M];

struct fw {
    int fen[M];

    void _add(int p, int val) {
        for (; p > 0; p -= p & -p) fen[p] += val;
    }
    
    int _get(int p) {
        int ans = 0;
        for (++p; p < M; p += p & -p) ans += fen[p];
        return ans;
    }
    
    void add(int l, int r, int val) { _add(r, val), _add(l, -val); }
    
    void add(int v, int val) { add(st[v], fi[v], val); }
    
    int get(int v) { return _get(st[v]); }
};

fw f1, f2;

void init(int p, int v) {
    par[0][v] = p;
    for (int i = 1; i < G; ++i) par[i][v] = par[i - 1][par[i - 1][v]];
    st[v] = cnt++;
    for (int i = 0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (u != p) d[u] = d[v] + 1, init(v, u);
    }
    fi[v] = cnt;
}

int get_parent(int v, int k) {
    for (int i = 0; i < G; ++i) {
        if ((1 << i) & k) v = par[i][v];
    }
    return v;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = get_parent(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = G - 1; i >= 0; --i) {
        if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    }
    return par[0][v];
}

int dfs(int p, int v) {
    int ans = 0;
    for (int i = 0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (u == p) continue;
        ans += dfs(v, u);
    }
    for (int i = 0; i < pv[v].size(); ++i) {
        path x = pv[v][i];
        int res = x.w;
        res += f1.get(x.u), res += f1.get(x.v), res -= f1.get(v);
        if (par[0][v] != v) res -= f1.get(par[0][v]);
        res -= f2.get(x.u), res -= f2.get(x.v), res += f2.get(v);
        if (par[0][v] != v) res -= f2.get(par[0][v]);
        ans = max(ans, res);
    }
    f1.add(par[0][v], ans);
    f2.add(v, ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p, --p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    init(0, 0);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        pv[lca(u, v)].push_back(path(u, v, w));
    }
    cout << dfs(0, 0) << "\n";
    return 0;
}