#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        sum += b[i];
    }
    
    std::vector<bool> dp(sum + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        std::vector<bool> ndp(sum + 1);
        for (int j = 0; j <= sum; j++) {
            if (dp[j]) {
                ndp[j + a[i]] = true;
                ndp[j + b[i]] = true;
            }
        }
        dp = ndp;
    }
    
    int ans = sum * sum;
    for (int i = 0; i <= sum; i++) {
        if (dp[i]) {
            ans = std::min(ans, i * i + (sum - i) * (sum - i));
        }
    }
    
    for (int i = 0; i < n; i++) {
        ans += (a[i] * a[i] + b[i] * b[i]) * (n - 2);
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