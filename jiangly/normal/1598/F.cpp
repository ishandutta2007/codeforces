#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int ans = 0;
    
    std::vector<std::string> s(n);
    std::vector<int> a(n), min(n), cntmin(n);
    std::vector<std::vector<int>> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        int m = s[i].length();
        
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '(') {
                sum++;
            } else {
                sum--;
            }
            if (sum < min[i]) {
                min[i] = sum;
                cntmin[i] = 0;
            }
            if (sum == min[i]) {
                cntmin[i]++;
            }
        }
        a[i] = sum;
        f[i].resize(m + 1, -1);
    }
    
    std::vector<int> dp(1 << n, -1), sum(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        int u = __builtin_ctz(mask);
        sum[mask] = sum[mask & ~(1 << u)] + a[u];
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == -1) {
            continue;
        }
        ans = std::max(ans, dp[mask]);
        for (int i = 0; i < n; i++) {
            if (~mask >> i & 1) {
                int nmask = mask | (1 << i);
                if (sum[mask] + min[i] >= 0) {
                    dp[nmask] = std::max(dp[nmask], dp[mask] + (sum[mask] + min[i] == 0) * cntmin[i]);
                }
                if (sum[mask] <= int(s[i].length())) {
                    f[i][sum[mask]] = std::max(f[i][sum[mask]], dp[mask]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        int m = s[i].length();
        
        int sum = 0, min = 0, cntmin = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '(') {
                sum++;
            } else {
                sum--;
            }
            if (sum < min) {
                min = sum;
                cntmin = 0;
            }
            if (sum == min) {
                cntmin++;
                if (f[i][-sum] != -1) {
                    ans = std::max(ans, f[i][-sum] + cntmin);
                }
            }
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}