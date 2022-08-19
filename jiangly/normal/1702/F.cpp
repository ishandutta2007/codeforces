#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::map<int, std::array<std::vector<int>, 2>> p;
    for (int i = 0; i < n; i++) {
        int x = __builtin_ctz(a[i]);
        p[a[i] >> x][0].push_back(x);
        x = __builtin_ctz(b[i]);
        p[b[i] >> x][1].push_back(x);
    }
    
    while (!p.empty()) {
        auto [v, f] = *p.rbegin();
        p.erase(p.rbegin()->first);
        
        if (f[0].size() < f[1].size()) {
            std::cout << "NO\n";
            return;
        }
        std::sort(f[0].begin(), f[0].end(), std::greater());
        std::sort(f[1].begin(), f[1].end(), std::greater());
        
        while (f[0].size() > f[1].size()) {
            int d = f[0].back();
            f[0].pop_back();
            int t = __builtin_ctz(v >> 1);
            p[v >> (t + 1)][0].push_back(t);
        }
    }
    
    std::cout << "YES\n";
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