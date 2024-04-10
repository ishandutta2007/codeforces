#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    std::vector<i64> sum(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + x[i];
    }
    
    i64 ans = sum[0] * b;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, 1LL * (a + b) * x[i] + (sum[i + 1] - 1LL * x[i] * (n - i - 1)) * b);
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