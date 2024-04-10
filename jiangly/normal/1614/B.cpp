#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] > a[j]; });
    
    std::vector<int> x(n + 1);
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        x[p[i] + 1] = (i % 2 == 0 ? 1 : -1) * (i / 2 + 1);
        res += 2LL * std::abs(x[p[i] + 1]) * a[p[i]];
    }
    
    std::cout << res << '\n';
    for (int i = 0; i <= n; i++) {
        std::cout << x[i] << " \n"[i == n];
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