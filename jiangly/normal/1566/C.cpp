#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s[2];
    std::cin >> s[0] >> s[1];
    
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = -1E9;
    }
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int cnt[3] = {};
        int mex = 0;
        for (int j = 0; i + j < n && j < 2; j++) {
            cnt[s[0][i + j] - '0']++;
            cnt[s[1][i + j] - '0']++;
            while (cnt[mex] > 0) {
                mex++;
            }
            dp[i + j + 1] = std::max(dp[i + j + 1], dp[i] + mex);
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