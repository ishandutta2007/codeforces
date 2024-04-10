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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector dsu(30, DSU(n));
    
    std::vector<bool> good(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        if (~w & 1) {
            good[u] = good[v] = true;
        }
        for (int j = 0; j < 30; j++) {
            if (w >> j & 1) {
                dsu[j].merge(u, v);
            }
        }
    }
    
    std::vector goodr(30, std::vector<bool>(n));
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            for (int j = 0; j < 30; j++) {
                goodr[j][dsu[j].leader(i)] = true;
            }
        }
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        
        int ans = 2;
        for (int j = 0; j < 30; j++) {
            if (dsu[j].same(u, v)) {
                ans = 0;
            }
        }
        if (ans == 0) {
            std::cout << "0\n";
            continue;
        }
        
        for (int j = 1; j < 30; j++) {
            if (goodr[j][dsu[j].leader(u)]) {
                ans = 1;
            }
        }
        
        std::cout << ans << "\n";
    }
    
    
    return 0;
}