#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3E5;

int dep[2 * N];
int st1[20][2 * N], st2[21][4 * N];
int euler1[2 * N], euler2[4 * N];

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int queryLCA(int u, int v) {
    u = euler1[u];
    v = euler1[v];
    if (u > v) {
        std::swap(u, v);
    }
    int k = std::__lg(v - u + 1);
    
    int x = st1[k][u];
    int y = st1[k][v - (1 << k) + 1];
    return dep[x] < dep[y] ? x : y;
}

int queryMax(int u, int v) {
    u = euler2[u];
    v = euler2[v];
    if (u > v) {
        std::swap(u, v);
    }
    int k = std::__lg(v - u + 1);
    
    return std::max(st2[k][u], st2[k][v - (1 << k) + 1]);
}

struct Info {
    int x;
    int v;
    Info(int x = -1, int v = -1) : x(x), v(v) {}
};

Info operator+(const Info &a, const Info &b) {
    if (a.x == -1) {
        return b;
    }
    if (b.x == -1) {
        return a;
    }
    
    return Info(queryLCA(a.x, b.x), std::max({a.v, b.v, queryMax(a.x, b.x)}));
}

constexpr int M = 1 << 20;

Info info[M], all[M];
int tag[M];

void pull(int p) {
    info[p] = info[2 * p] + info[2 * p + 1];
}

void modify(int p, int t) {
    if (t == 0) {
        tag[p] = 0;
        info[p] = Info();
    } else {
        tag[p] = 1;
        info[p] = all[p];
    }
}

void push(int p) {
    if (tag[p] != -1) {
        modify(2 * p, tag[p]);
        modify(2 * p + 1, tag[p]);
        tag[p] = -1;
    }
}

void build(int p, int l, int r) {
    tag[p] = -1;
    if (r - l == 1) {
        all[p] = Info(l, -1);
        return;
    }
    
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
    all[p] = all[2 * p] + all[2 * p + 1];
}

void rangeModify(int p, int l, int r, int x, int y, int t) {
    if (l >= y || r <= x) {
        return;
    }
    if (l >= x && r <= y) {
        modify(p, t);
        return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeModify(2 * p, l, m, x, y, t);
    rangeModify(2 * p + 1, m, r, x, y, t);
    pull(p);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<std::array<int, 3>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.push_back({w, u, v});
    }
    std::sort(edges.begin(), edges.end());
    
    std::vector<int> parent(n, -1);
    int tim = 0;
    std::function<void(int)> dfs1 = [&](int u) {
        st1[0][tim] = u;
        euler1[u] = tim++;
        for (auto [v, w] : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            st1[0][tim++] = u;
        }
    };
    dfs1(0);
    
    assert(tim == 2 * n - 1);
    
    DSU g(2 * n - 1);
    std::vector<std::array<int, 2>> ch;
    std::vector<int> weight;
    for (auto [w, u, v] : edges) {
        ch.push_back({g.leader(u), g.leader(v)});
        const int x = n + weight.size();
        g.merge(x, u);
        g.merge(x, v);
        weight.push_back(w);
    }
    
    tim = 0;
    std::function<void(int)> dfs2 = [&](int u) {
        st2[0][tim] = u < n ? -1 : weight[u - n];
        euler2[u] = tim++;
        if (u < n) {
            return;
        }
        for (auto x : ch[u - n]) {
            dfs2(x);
            st2[0][tim++] = weight[u - n];
        }
    };
    dfs2(g.leader(0));
    
    assert(tim == 4 * n - 3);
    
    for (int j = 0; (1 << (j + 1)) <= 2 * n - 1; j++) {
        for (int i = 0; i + (1 << (j + 1)) <= 2 * n - 1; i++) {
            int x = st1[j][i];
            int y = st1[j][i + (1 << j)];
            st1[j + 1][i] = dep[x] < dep[y] ? x : y;
        }
    }
    
    for (int j = 0; (1 << (j + 1)) <= 4 * n - 3; j++) {
        for (int i = 0; i + (1 << (j + 1)) <= 4 * n - 3; i++) {
            st2[j + 1][i] = std::max(st2[j][i], st2[j][i + (1 << j)]);
        }
    }
    
    build(1, 0, n);
    
    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if (t <= 2) {
            int l, r;
            std::cin >> l >> r;
            l--;
            
            rangeModify(1, 0, n, l, r, t % 2);
        } else {
            int x;
            std::cin >> x;
            x--;
            
            auto a = info[1];
            
            std::cout << std::max(a.x == -1 ? -1 : queryMax(x, a.x), a.v) << "\n";
        }
    }
    
    return 0;
}