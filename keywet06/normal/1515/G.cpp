#include <bits/stdc++.h>

#define Debug Deb << "Debug(" << __LINE__ << "): "
#define Deb std::cerr
#define fi first
#define se second
#define mkp std::make_pair

using int64 = long long;
using pair = std::pair<int, int>;

const int C = 20;
const int N = 200005;

int n, m, q, x, y, z, cnt, bcnt, l;
int deep[N], block[N], dfn[N], low[N], ins[N], top[N];
int fa[N][C];

int64 dep[N], bgd[N];

std::vector<pair> to[N];

std::stack<int> sta;

inline void tarjan(int u, int f) {
    dfn[u] = low[u] = ++cnt, sta.push(u), ins[u] = 1, fa[u][0] = f;
    for (int i = 1; i < C; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (pair e : to[u]) {
        if (!dfn[e.fi]) {
            deep[e.fi] = deep[u] + 1, dep[e.fi] = dep[u] + e.se;
            tarjan(e.fi, u);
            low[u] = std::min(low[u], low[e.fi]);
        } else if (ins[e.fi]) {
            low[u] = std::min(low[u], dfn[e.fi]);
        }
    }
    if (dfn[u] == low[u]) {
        top[++bcnt] = u;
        while (sta.top() != u) {
            block[sta.top()] = bcnt, ins[sta.top()] = 0, sta.pop();
        }
        block[u] = bcnt, ins[u] = 0, sta.pop();
    }
}

inline int lca(int u, int v) {
    if (deep[u] < deep[v]) std::swap(u, v);
    int c = deep[u] - deep[v];
    for (int i = 0; i < C; ++i) {
        if ((1 << i) & c) u = fa[u][i];
    }
    for (int i = C - 1; i; --i) {
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return u == v ? u : fa[u][0];
}

inline int64 gcd(int64 x, int64 y) { return y ? gcd(y, x % y) : x; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x >> y >> z;
        to[x].push_back(mkp(y, z));
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i, i);
    }
    for (int i = 1; i <= n; ++i) {
        for (pair e : to[i]) {
            if (block[i] != block[e.fi]) continue;
            // Debug << i << " --> " << e.fi << " (" << e.se << ") : ";
            if ((l = lca(i, e.fi)) == i) {
                // Deb << std::abs(dep[e.fi] - dep[i] - e.se) << 'a' << std::endl;
                bgd[block[i]] =
                    gcd(bgd[block[i]], std::abs(dep[e.fi] - dep[i] - e.se));
            } else if (l == e.fi) {
                // Deb << dep[i] - dep[e.fi] + e.se << 'b' << std::endl;
                bgd[block[i]] = gcd(bgd[block[i]], dep[i] - dep[e.fi] + e.se);
            } else {
                // Deb << std::abs(dep[i] + e.se - dep[l]) << 'c' << std::endl;
                bgd[block[i]] =
                    gcd(bgd[block[i]], std::abs(dep[i] + e.se - dep[e.fi]));
            }
        }
    }
    // Debug << "dep = {";
    // for (int i = 1; i <= n; ++i) Deb << dep[i] << ", ";
    // Deb << "...}" << std::endl;
    // Debug << "bcnt = " << bcnt << ";" << std::endl;
    // Debug << "block = {";
    // for (int i = 1; i <= n; ++i) Deb << block[i] << ", ";
    // Deb << "...}" << std::endl;
    // Debug << "bgd = {";
    // for (int i = 1; i <= bcnt; ++i) Deb << bgd[i] << ", ";
    // Deb << "...}" << std::endl;
    std::cin >> q;
    while (q--) {
        std::cin >> x >> y >> z;
        if (!y) {
            std::cout << "YES\n";
        } else if (!bgd[block[x]]) {
            std::cout << "NO\n";
        } else if (gcd(y, z) % gcd(bgd[block[x]], z) == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}