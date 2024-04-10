#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> d[i];
    int64_t ans = 0;
    std::vector<int64_t> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
    if (k == 0) {
        int64_t sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += a[i];
            ans = std::max(ans, sum - d[i]);
        }
    } else if (k == 1) {
        // i -> 1
        int mn = d[0];
        for (int i = 1; i < n - 1; ++i) {
            mn = std::min(mn, d[i]);
            ans = std::max(ans, std::max(0ll, sum[i + 1] - mn) + std::max(0ll, sum[n] - sum[i + 1] - d[i + 1]));
        }
        // i -> i + 2
        for (int i = 1; i < n; ++i) ans = std::max(ans, sum[n] - sum[i] - d[i]);
        int mx = std::max(-a[n - 2], -d[n - 2]);
        for (int i = n - 3; i >= 0; --i) {
            ans = std::max(ans, sum[n] - sum[i] - d[i] + mx);
            mx = std::max({mx, -a[i], -d[i]});
        }
    } else {
        int mn = 1e9;
        for (int i = 0; i < n - 1; ++i) mn = std::min(mn, d[i]);
        ans = std::max(ans, sum[n] - mn);
        ans = std::max(ans, 1ll * a[n - 1] - d[n - 1]);
    }
    std::cout << ans << "\n";
    
    return 0;
}