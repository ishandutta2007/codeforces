#include <iostream>
#include <vector>
int t, a, b, c;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i < (1 << 7); ++i) {
            int x = 0, y = 0, z = 0;
            for (int j = 1; j <= 7; ++j) {
                if (i >> (j - 1) & 1) {
                    x += j & 1;
                    y += j >> 1 & 1;
                    z += j >> 2;
                }
            }
            if (x <= a && y <= b && z <= c)
                ans = std::max(ans, __builtin_popcount(i));
        }
        std::cout << ans << "\n";
    }
    return 0;
}