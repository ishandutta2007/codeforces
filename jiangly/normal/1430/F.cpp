#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> l(n), r(n), a(n);
    for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i] >> a[i];
    std::vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        int need = a[i];
        if (i + 1 < n && r[i] == l[i + 1]) need += dp[i + 1];
        if (1ll * (r[i] - l[i] + 1) * k < need) {
            std::cout << -1 << "\n";
            return 0;
        }
        dp[i] = std::max(0ll, need - 1ll * (r[i] - l[i]) * k);
    }
    int64_t ans = 0;
    int cur = k;
    for (int i = 0; i < n; ++i) {
        if (cur < dp[i]) {
            ans += cur;
            cur = k;
        }
        ans += a[i];
        cur = ((cur - a[i]) % k + k) % k;
    }
    std::cout << ans << "\n";
    
    return 0;
}