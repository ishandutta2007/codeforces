#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) {
            continue;
        }
        std::vector<int> cnt(n);
        int mx = 0;
        for (int j = i; j <= n; j++) {
            if (j > i) {
                mx = std::max(mx, ++cnt[a[j - 1]]);
            }
            if ((j - i) % 2 == 0 && mx * 2 <= j - i) {
                if (j == n) {
                    dp[n] = std::max(dp[n], dp[i]);
                } else if (i == 0 || a[i - 1] == a[j]) {
                    dp[j + 1] = std::max(dp[j + 1], dp[i] + 1);
                }
            }
        }
    }
    
    std::cout << dp[n] << "\n";
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