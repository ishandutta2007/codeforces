#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i)
            std::cin >> a[i] >> b[i];
        std::vector<int> v = a;
        std::sort(v.begin(), v.end());
        std::vector<int64_t> sum(m + 1);
        for (int i = m - 1; i >= 0; --i)
            sum[i] = sum[i + 1] + v[i];
        int64_t ans = sum[std::max(0, m - n)];
        for (int i = 0; i < m; ++i) {
            int cnt = std::min<int>(n - 1, m - (std::upper_bound(v.begin(), v.end(), b[i]) - v.begin()));
            int64_t res = sum[m - cnt] + 1ll * (n - 1 - cnt) * b[i];
            if (cnt > 0 && a[i] >= v[m - cnt]) {
                if (cnt < m) {
                    res += std::max(b[i], v[m - cnt - 1]);
                } else {
                    res += b[i];
                }
            } else {
                res += a[i];
            }
            ans = std::max(ans, res);
        }
        std::cout << ans << "\n";
    }
    return 0;
}