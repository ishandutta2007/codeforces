#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    int ans = std::min(std::abs(a[0] - b[0]) + std::abs(a[n - 1] - b[n - 1]),
            std::abs(a[0] - b[n - 1]) + std::abs(a[n - 1] - b[0]));
    
    int a0 = inf, b0 = inf, a1 = inf, b1 = inf;
    for (int i = 0; i < n; i++) {
        a0 = std::min(a0, std::abs(a[0] - b[i]));
        a1 = std::min(a1, std::abs(a[n - 1] - b[i]));
        b0 = std::min(b0, std::abs(b[0] - a[i]));
        b1 = std::min(b1, std::abs(b[n - 1] - a[i]));
    }
    
    ans = std::min({1LL * ans, 1LL * std::abs(a[0] - b[0]) + a1 + b1,
        1LL * std::abs(a[0] - b[n - 1]) + a1 + b0,
        1LL * std::abs(a[n - 1] - b[0]) + a0 + b1,
        1LL * std::abs(a[n - 1] - b[n - 1]) + a0 + b0});
    
    ans = std::min(1LL * ans, 1LL * a0 + a1 + b0 + b1);
    
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