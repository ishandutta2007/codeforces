#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, d, e, f;
        std::cin >> a >> b >> c >> d >> e >> f;
        if (e > f) {
            std::swap(e, f);
            std::swap(d, c);
        }
        int ans = 0;
        for (int i = 0; i <= c && 1ll * e * i <= a; ++i) {
            int j = std::min(d, (a - e * i) / f);
            int rc = c - i;
            int rd = d - j;
            int x = std::min(rc, b / e);
            int y = std::min(rd, (b - e * x) / f);
            ans = std::max(ans, i + j + x + y);
        }
        std::cout << ans << "\n";
    }
    return 0;
}