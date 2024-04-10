#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

constexpr int N = 5e5;

std::vector<std::pair<int, int>> e[N];
int nd[N], type[N], in[N], out[N], t[N], euler[N], dep[N], a[N], el[2 * N];
int cnt, now;

void dfs(int u, int p) {
    euler[u] = cnt;
    el[cnt++] = u;
    in[u] = now++;
    a[in[u]] = u;
    for (auto [v, i] : e[u]) {
        if (v == p) continue;
        nd[i] = v;
        dep[v] = dep[u] + 1;
        t[v] = t[u] ^ type[i];
        dfs(v, u);
        el[cnt++] = u;
    }
    out[u] = now;
}
int st[2 * N][20];


int lca(int u, int v) {
    u = euler[u];
    v = euler[v];
    if (u > v) std::swap(u, v);
    ++v;
    int k = std::__lg(v - u);
    int x = st[u][k], y = st[v - (1 << k)][k];
    return dep[x] < dep[y] ? x : y;
}
int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

struct Diameter { int u, v, l; };
struct Data { Diameter d[2]; };
Diameter merge(const Diameter &a, const Diameter &b) {
    if (a.u == -1) return b;
    if (b.u == -1) return a;
    auto c = a.l > b.l ? a : b;
    for (auto u : {a.u, a.v}) {
        for (auto v : {b.u, b.v}) {
            Diameter d = {u, v, dis(u, v)};
            if (d.l > c.l) c = d;
        }
    }
    return c;
}
Data merge(const Data &a, const Data &b) { return Data{merge(a.d[0], b.d[0]), merge(a.d[1], b.d[1])}; }

constexpr int M = 1 << 20;

Data seg[M];
bool tag[M];
    
void build(int p, int l, int r) {
    if (r - l == 1) {
        int u = a[l];
        seg[p].d[t[u]] = {u, u, 0};
        seg[p].d[!t[u]] = {-1, -1, -1};
    } else {
        int m = (l + r) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m, r);
        seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
    }
}

void fl(int p) {
    tag[p] ^= 1;
    std::swap(seg[p].d[0], seg[p].d[1]);
}
void push(int p) {
    if (tag[p]) {
        fl(2 * p);
        fl(2 * p + 1);
        tag[p] = 0;
    }
}

void flip(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) return fl(p);
    int m = (l + r) / 2;
    push(p);
    flip(2 * p, l, m, x, y);
    flip(2 * p + 1, m, r, x, y);
    seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
}

int getAns() { return std::max(seg[1].d[0].l, seg[1].d[1].l); };
    
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v >> type[i];
        --u, --v;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    dfs(0, -1);
    int lg = std::__lg(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i) st[i][0] = el[i];
    for (int j = 1; j <= lg; ++j) {
        for (int i = 0; i + (1 << j) <= 2 * n - 1; ++i) {
            int u = st[i][j - 1], v = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = dep[u] < dep[v] ? u : v;
        }
    }
    build(1, 0, n);
    
    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;
        --x;
        flip(1, 0, n, in[nd[x]], out[nd[x]]);
        std::cout << getAns() << "\n";
    }
    
    return 0;
}