#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];
        int64 need = 0;
        for (int i = 0; i < n; i++) need += a[i];
        int64 cur = 0;
        for (int i = 0; i < n; i++) cur += b[i];
        const int64 inf = (int64)(1e18) + 7;
        int64 ans = inf;
        for (int fir = 0; fir < 2; fir++) {
            std::vector<int64> dp(2, inf);
            dp[fir] = cur;
            for (int i = 0; i < n; i++) {
                int j = (i + n - 1) % n;
                std::vector<int64> ndp(2, inf);
                for (int was = 0; was < 2; was++) {
                    for (int here = 0; here < 2; here++) {
                        int64 cost = dp[was];
                        if (!here) cost += a[i];
                        if (!here && !was) cost -= b[j];
                        ndp[here] = std::min(ndp[here], cost);
                    }
                }
                dp = ndp;
            }
            ans = std::min(ans, dp[fir]);
        }
        std::cout << (ans == need ? "YES" : "NO") << '\n';
    }
}