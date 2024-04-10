#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    i64 res = 0;
    for (int i = 1; i + 1 < n; i += 2) {
        res += std::max({h[i - 1] + 1, h[i + 1] + 1, h[i]}) - h[i];
    }
    
    i64 ans = res;
    if (n % 2 == 0) {
        for (int i = n - 2; i > 0; i--) {
            res += (i % 2 == 0 ? 1 : -1) * (std::max({h[i - 1] + 1, h[i + 1] + 1, h[i]}) - h[i]);
            ans = std::min(ans, res);
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