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
    int n;
    std::cin >> n;
    
    std::vector<int> c(n), l(n), r(n);
    std::vector<int> p[2];
    for (int i = 0; i < n; i++) {
        std::cin >> c[i] >> l[i] >> r[i];
        p[c[i]].push_back(i);
    }
    
    for (int c = 0; c < 2; c++) {
        std::sort(p[c].begin(), p[c].end(), [&](int i, int j) {
            if (l[i] != l[j]) {
                return l[i] < l[j];
            } else {
                return r[i] > r[j];
            }
        });
    }
    
    DSU dsu(n);
    
    int ans = n;
    
    auto work = [&]() {
        std::vector<int> a;
        for (auto i : p[0]) {
            if (a.empty() || r[i] > r[a.back()]) {
                a.push_back(i);
            }
        }
        
        for (auto i : p[1]) {
            auto it = std::partition_point(a.begin(), a.end(), [&](int j) {
                return r[j] < l[i];
            });
            if (it != a.end()) {
                int j = *it;
                if (r[i] >= l[j]) {
                    ans -= dsu.merge(i, j);
                }
            }
        }
    };
    
    work();
    std::swap(p[0], p[1]);
    work();
    
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