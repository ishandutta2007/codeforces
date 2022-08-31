#include <bits/stdc++.h>

using i64 = long long;

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
    
    i64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += std::min(std::abs(a[i] - a[i + 1]) + std::abs(b[i] - b[i + 1]),
                std::abs(a[i] - b[i + 1]) + std::abs(b[i] - a[i + 1]));
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