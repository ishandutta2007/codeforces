#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        int ans = 1e9, d0 = -1;
        for (int d = 1; d <= y - x; ++d) {
            if ((y - x) % d == 0) {
                int p = std::min(n, (y - 1) / d + 1);
                if (p - 1 < (y - x) / d)
                    continue;
                int res = y + (n - p) * d;
                if (res < ans) {
                    ans = res;
                    d0 = d;
                }
            }
        }
        int p = std::min(n, (y - 1) / d0 + 1);
        for (int i = 1; i <= n; ++i)
            std::cout << y + (i - p) * d0 << " \n"[i == n];
    }
    return 0;
}