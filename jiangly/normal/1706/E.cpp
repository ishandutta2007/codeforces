#include <bits/stdc++.h>

using i64 = long long;
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

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<int> parent(2 * n - 1, -1), siz(2 * n - 1), index(2 * n - 1, -1);
    std::vector<std::vector<int>> adj(2 * n - 1);
    DSU dsu(2 * n - 1);
    for (int i = n; i < 2 * n - 1; i++) {
        dsu.siz[i] = 0;
    }
    int cnt = n;
    for (int i = 0; i < n; i++) {
        siz[i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        if (!dsu.same(u, v)) {
            u = dsu.leader(u);
            v = dsu.leader(v);
            if (siz[u] < siz[v]) {
                std::swap(u, v);
            }
            parent[u] = parent[v] = cnt;
            adj[cnt] = {u, v};
            index[cnt] = i;
            dsu.merge(cnt, u);
            dsu.merge(cnt, v);
            siz[cnt] = dsu.size(cnt);
            cnt++;
        }
    }
    
    std::vector<int> top(2 * n - 1), dep(2 * n - 1), in(n);
    cnt = 0;
    
    std::function<void(int)> dfs = [&](int x) {
        if (x < n) {
            in[x] = cnt++;
        }
        for (auto v : adj[x]) {
            dep[v] = dep[x] + 1;
            top[v] = v == adj[x][0] ? top[x] : v;
            dfs(v);
        }
    };
    top[2 * n - 2] = 2 * n - 2;
    dfs(2 * n - 2);
    
    auto lca = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                v = parent[top[v]];
            } else {
                u = parent[top[u]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    };
    
    int lg = std::__lg(n);
    
    std::vector mx(lg + 1, std::vector<int>(n)), mn(mx);
    for (int i = 0; i < n; i++) {
        mx[0][i] = mn[0][i] = i;
    }
    for (int j = 0; j < lg; j++) {
        for (int i = 0; i + (2 << j) <= n; i++) {
            mx[j + 1][i] = in[mx[j][i]] > in[mx[j][i + (1 << j)]] ? mx[j][i] : mx[j][i + (1 << j)];
            mn[j + 1][i] = in[mn[j][i]] < in[mn[j][i + (1 << j)]] ? mn[j][i] : mn[j][i + (1 << j)];
        }
    }
    
    auto getMax = [&](int l, int r) {
        int k = std::__lg(r - l);
        return in[mx[k][l]] > in[mx[k][r - (1 << k)]] ? mx[k][l] : mx[k][r - (1 << k)];
    };
    
    auto getMin = [&](int l, int r) {
        int k = std::__lg(r - l);
        return in[mn[k][l]] < in[mn[k][r - (1 << k)]] ? mn[k][l] : mn[k][r - (1 << k)];
    };
    
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        
        int x = lca(getMin(l, r), getMax(l, r));
        std::cout << index[x] + 1 << " \n"[q == 0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}