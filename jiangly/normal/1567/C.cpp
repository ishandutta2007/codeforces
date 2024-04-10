#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> d;
    while (n > 0) {
        d.push_back(n % 10);
        n /= 10;
    }
    
    i64 dp[4] = {};
    dp[0] = 1;
    std::reverse(d.begin(), d.end());
    
    for (auto x : d) {
        i64 g[4] = {};
        for (int i = 0; i < 4; i++) {
            for (int c = 0; c < 2; c++) {
                int s = c * 10 + x - (i & 1);
                g[i] += dp[i >> 1 | c << 1] * (10 - std::abs(s - 9));
            }
        }
        for (int i = 0; i < 4; i++) {
            dp[i] = g[i];
        }
    }
    
    std::cout << dp[0] - 2 << "\n";
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