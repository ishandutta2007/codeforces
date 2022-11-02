#include <bits/stdc++.h>

#define fir first
#define sec second
#define mkp std::make_pair
#define Debug std::cerr << "Debug(" << __LINE__ << "): "

using pair = std::pair<int, int>;

const int N = 300005;
const int M = 500005;
const int L = 1048576;

bool use[L], has[L];

int n, m, cnt;
int fi[N], fa[N], deep[N], size[N], son[N], top[N], dfn[N], val[N];
int eu[M], ev[M], ew[M], ans[M];

std::vector<pair> to[N];

inline int find(int u) { return fi[u] == u ? u : (fi[u] = find(fi[u])); }

inline void dfs1(int u, int f) {
    size[u] = 1, fa[u] = f, deep[u] = deep[f] + 1;
    for (pair e : to[u]) {
        if (e.fir == f) continue;
        val[e.fir] = e.sec ^ val[u], dfs1(e.fir, u), size[u] += size[e.fir];
        if (size[e.fir] > size[son[u]]) son[u] = e.fir;
    }
}

inline void dfs2(int u, int p) {
    top[u] = p, dfn[u] = ++cnt;
    if (son[u]) dfs2(son[u], p);
    for (pair e : to[u]) {
        if (e.fir == fa[u] || e.fir == son[u]) continue;
        dfs2(e.fir, e.fir);
    }
}

inline void update(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return void(has[u] = use[u] = true);
    int mid = l + r >> 1;
    if (x <= mid) update(u << 1, l, mid, x, y);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y);
    has[u] = has[u << 1] || has[u << 1 | 1];
}

inline void updateS(int u, int v) {
    while (top[u] != top[v]) {
        if (deep[top[u]] < deep[top[v]]) std::swap(u, v);
        update(1, 1, n, dfn[top[u]], dfn[u]), u = fa[top[u]];
    }
    if (deep[u] > deep[v]) std::swap(u, v);
    if (u != v) update(1, 1, n, dfn[u] + 1, dfn[v]);
}

inline bool query(int u, int l, int r, int x, int y) {
    if (use[u] || l >= x && r <= y) return has[u];
    int mid = l + r >> 1;
    return x <= mid && query(u << 1, l, mid, x, y) ||
           y > mid && query(u << 1 | 1, mid + 1, r, x, y);
}

inline bool queryS(int u, int v) {
    while (top[u] != top[v]) {
        if (deep[top[u]] < deep[top[v]]) std::swap(u, v);
        if (query(1, 1, n, dfn[top[u]], dfn[u])) return true;
        u = fa[top[u]];
    }
    if (deep[u] > deep[v]) std::swap(u, v);
    return u != v && query(1, 1, n, dfn[u] + 1, dfn[v]);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) fi[i] = i;
    for (int i = 1; i <= m; ++i) {
        std::cin >> eu[i] >> ev[i] >> ew[i];
        if (find(eu[i]) == find(ev[i])) continue;
        ans[i] = 1, fi[find(eu[i])] = find(ev[i]);
        to[eu[i]].push_back(mkp(ev[i], ew[i]));
        to[ev[i]].push_back(mkp(eu[i], ew[i]));
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) dfs1(i, i), dfs2(i, i);
    }
    for (int i = 1; i <= m; ++i) {
        if (ans[i]) continue;
        if (val[eu[i]] ^ val[ev[i]] ^ ew[i] != 1) continue;
        if (queryS(eu[i], ev[i])) continue;
        ans[i] = 1, updateS(eu[i], ev[i]);
    }
    for (int i = 1; i <= m; ++i) std::cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}