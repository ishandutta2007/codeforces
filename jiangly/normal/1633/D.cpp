#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1000;

int dp[N + 1];

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    k = std::min(k, 12 * n);
    
    std::vector<int> f(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= dp[b[i]]; j--) {
            f[j] = std::max(f[j], f[j - dp[b[i]]] + c[i]);
        }
    }
    
    std::cout << f[k] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::fill(dp, dp + N + 1, 1E9);
    dp[1] = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= N) {
                dp[i + i / j] = std::min(dp[i + i / j], dp[i] + 1);
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}