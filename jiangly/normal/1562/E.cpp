#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int res = 0;
    
    int dp[n];
    
    int lcp[n + 1][n + 1];
    std::memset(lcp, 0, sizeof(lcp));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            lcp[i][j] = s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        dp[i] = n - i;
        for (int j = 0; j < i; j++) {
            int x = lcp[i][j];
            if (i + x < n && s[i + x] > s[j + x]) {
                dp[i] = std::max(dp[i], dp[j] + n - i - x);
            }
        }
        res = std::max(res, dp[i]);
    }
    std::cout << res << "\n";
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