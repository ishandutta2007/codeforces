#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "
#define pub push_back
#define fi first
#define se second
#define mkp std::make_pair

using pair = std::pair<int, int>;

const int C = 20;
const int N = 300005;
const int Z = 50000000;

int n, q, x, y, z, l, r, cnt, clo, e, d;
int col[N], rt[N], dfn[N], las[N], p[N], rd[N], deep[N];
int ls[Z], rs[Z], sum[Z];
int fa[N][C];

std::vector<int> to[N];

std::vector<pair> hs[N];

std::mt19937 rad(std::chrono::system_clock::now().time_since_epoch().count());

inline int read() {
    int x = 0, ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    x = ch - '0', ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

inline int update(int u, int l, int r, int x, int v) {
    ls[++cnt] = ls[u], rs[cnt] = rs[u], sum[cnt] = sum[u] ^ v, u = cnt;
    if (l == r) return u;
    int mid = l + r >> 1;
    if (x <= mid) {
        ls[u] = update(ls[u], l, mid, x, v);
    } else {
        rs[u] = update(rs[u], mid + 1, r, x, v);
    }
    return u;
}

inline void dfs(int u, int f) {
    fa[u][0] = f, dfn[u] = ++clo, deep[u] = deep[f] + 1;
    for (int i = 1; i < C; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : to[u]) v != f && (dfs(v, u), 1);
    las[u] = clo;
}

inline int lca(int u, int v) {
    if (deep[u] < deep[v]) std::swap(u, v);
    int x = deep[u] - deep[v], y = 0, z = 0;
    for (int i = 0; i < C; ++i) {
        if (x >> i & 1) u = fa[u][i];
    }
    for (int i = C - 1; ~i; --i) {
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return u == v ? u : fa[u][0];
}

inline int query1(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return sum[u];
    int mid = l + r >> 1, ret = 0;
    if (x <= mid) ret ^= query1(ls[u], l, mid, x, y);
    if (y > mid) ret ^= query1(rs[u], mid + 1, r, x, y);
    return ret;
}

inline int query2(int u1, int u2, int u3, int u4, int l, int r) {
    if (l == r) return l;
    int mid = l + r >> 1;
    if (sum[ls[u1]] ^ sum[ls[u2]] ^ sum[ls[u3]] ^ sum[ls[u4]] ^ e && mid >= d) {
        return query2(ls[u1], ls[u2], ls[u3], ls[u4], l, mid);
    } else {
        e ^= sum[ls[u1]] ^ sum[ls[u2]] ^ sum[ls[u3]] ^ sum[ls[u4]];
        return query2(rs[u1], rs[u2], rs[u3], rs[u4], mid + 1, r);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    n = read(), q = read();
    for (int i = 1; i <= n; ++i) col[i] = read(), rd[i] = rad();
    for (int i = 1; i < n; ++i) to[x = read()].pub(y = read()), to[y].pub(x);
    dfs(1, 0), ++n;
    for (int i = 1; i < n; ++i) {
        hs[dfn[i]].pub(mkp(col[i], rd[col[i]]));
        hs[las[i] + 1].pub(mkp(col[i], rd[col[i]]));
    }
    for (int i = 1; i < n; ++i) {
        rt[i] = rt[i - 1];
        for (pair p : hs[i]) rt[i] = update(rt[i], 0, n, p.fi, p.se);
    }
    while (q--) {
        z = lca(x = read(), y = read()), l = read(), r = read(), d = l;
        e = query1(rt[dfn[x]], 0, n, 0, l - 1);
        e ^= query1(rt[dfn[y]], 0, n, 0, l - 1);
        e ^= query1(rt[dfn[z]], 0, n, 0, l - 1);
        e ^= query1(rt[dfn[fa[z][0]]], 0, n, 0, l - 1);
        e = query2(rt[dfn[x]], rt[dfn[y]], rt[dfn[z]], rt[dfn[fa[z][0]]], 0, n);
        std::cout << (e > r ? -1 : e) << '\n';
    }
    return 0;
}