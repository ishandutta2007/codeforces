#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<bool> have(m + 1);
    int min = m;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        min = std::min(min, a);
        have[a] = true;
    }
    
    std::vector<int> cnt(m + 1);
    std::vector<int> dp(m + 1, m);
    for (int i = 1; i <= m; i++) {
        if (have[i]) {
            cnt[m]++;
        }
    }
    
    int ans = m;
    int max = m;
    for (int i = m; i > 0; i--) {
        if (have[i]) {
            cnt[dp[i]]--;
        }
        dp[i] = i;
        if (have[i]) {
            cnt[dp[i]]++;
        }
        for (int j = 1; i * j <= m; j++) {
            if (have[i * j]) {
                cnt[dp[i * j]]--;
            }
            dp[i * j] = std::min(dp[i * j], std::max(dp[j], i));
            if (have[i * j]) {
                cnt[dp[i * j]]++;
            }
        }
        while (!cnt[max]) {
            max--;
        }
        if (i <= min) {
            ans = std::min(ans, max - i);
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