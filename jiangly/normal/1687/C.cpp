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
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    DSU dsu(n + 2);
    
    std::vector<i64> sa(n + 1), sb(n + 1);
    for (int i = 0; i < n; i++) {
        sa[i + 1] = sa[i] + a[i];
        sb[i + 1] = sb[i] + b[i];
    }
    
    std::vector<int> l(m), r(m), deg(m);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
        deg[i] = 2;
        g[l[i]].push_back(i);
        g[r[i]].push_back(i);
    }
    std::function<void(int)> set = [&](int i) {
        dsu.merge(i + 1, i);
        for (auto j : g[i]) {
            if (--deg[j] == 0) {
                int x = dsu.leader(l[j]);
                while (x <= r[j]) {
                    set(x);
                    x = dsu.leader(x);
                }
            }
        }
    };
    for (int i = 0; i <= n; i++) {
        if (sa[i] == sb[i]) {
            set(i);
        }
    }
    if (dsu.leader(0) == n + 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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