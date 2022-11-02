#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

using int32 = int;
using i5 = int32;
using pi5 = std::pair<i5, i5>;

const int N = 500005;
const int M = 1048576;

int n, m, rx, ry, l, x, y, z;
int dep[N], r[N], rid[N], col[N], s[N];

std::vector<int> to[N];

std::vector<pi5> et[N];

struct solver {
    int root, cnt;
    int dep[N], a[N], b[N], dfn[N], last[N], ed[N];
    int m0[M], m1[M], g[M];
    inline void dfs(int u, int f, int c) {
        (c ? b : a)[dfn[u] = ++cnt] = dep[u] = dep[f] + 1, (c ? a : b)[cnt] = 0;
        for (pi5 &e : et[u]) {
            if (e.first == f) continue;
            ed[e.second] = e.first;
            dfs(e.first, u, c ^ col[e.second]);
        }
        last[u] = cnt;
    }
    inline void build(int u, int l, int r) {
        if (l == r) return void((m0[u] = a[l], m1[u] = b[l]));
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        m0[u] = std::max(m0[u << 1], m0[u << 1 | 1]);
        m1[u] = std::max(m1[u << 1], m1[u << 1 | 1]);
    }
    inline solver(int _root) : root(_root), cnt(0) {
        dep[root] = -1, dfs(root, root, 0), build(1, 1, n);
    }
    inline void pushdown(int u) {
        if (!g[u]) return;
        std::swap(m0[u << 1], m1[u << 1]), g[u << 1] ^= 1, g[u] = 0;
        std::swap(m0[u << 1 | 1], m1[u << 1 | 1]), g[u << 1 | 1] ^= 1;
    }
    inline void flip(int u, int l, int r, int x, int y) {
        if (l >= x && r <= y) return g[u] ^= 1, std::swap(m0[u], m1[u]);
        int mid = l + r >> 1;
        pushdown(u);
        if (x <= mid) flip(u << 1, l, mid, x, y);
        if (y > mid) flip(u << 1 | 1, mid + 1, r, x, y);
        m0[u] = std::max(m0[u << 1], m0[u << 1 | 1]);
        m1[u] = std::max(m1[u << 1], m1[u << 1 | 1]);
    }
    inline int solve(int x) {
        return flip(1, 1, n, dfn[ed[x]], last[ed[x]]), m0[1];
    }
};

inline void dfs(int u, int f) {
    int max = 0, mar = 0, idx = u, idr = u;
    for (int &v : to[u]) {
        if (v == f) continue;
        dfs(v, u);
        if (r[v] >= max) {
            mar = max, idr = idx;
            max = r[v] + 1, idx = s[v];
        } else if (r[v] >= mar) {
            mar = r[v] + 1, idr = s[v];
        }
    }
    if ((s[u] = idx, r[u] = max) + mar > l) l = max + mar, rx = idx, ry = idr;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y >> col[i];
        to[x].push_back(y);
        to[y].push_back(x);
        et[x].emplace_back(y, i);
        et[y].emplace_back(x, i);
    }
    dfs(1, 1);
    solver sx(rx), sy(ry);
    std::cin >> m;
    while (m--) {
        std::cin >> x;
        std::cout << std::max(sx.solve(x), sy.solve(x)) << '\n';
    }
    return 0;
}