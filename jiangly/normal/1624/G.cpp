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
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v, w};
    }
    
    int ans = 0;
    for (int t = 29; t >= 0; t--) {
        DSU g(n);
        int s = n;
        for (auto [u, v, w] : edges) {
            if (~w >> t & 1) {
                s -= g.merge(u, v);
            }
        }
        if (s == 1) {
            edges.erase(std::remove_if(edges.begin(), edges.end(), [&](auto e) {
                return std::get<2>(e) >> t & 1;
            }), edges.end());
        } else {
            ans |= 1 << t;
        }
    }
    
    std::cout << ans << "\n";
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