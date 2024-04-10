#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int64_t mn[6] = {}, mx[6] = {};
        mn[0] = mx[0] = 1;
        for (int i = 1; i <= 5; ++i) {
            mx[i] = -1e18;
            mn[i] = 1e18;
        }
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            for (int j = 5; j > 0; --j) {
                if (x >= 0) {
                    if (mx[j - 1] != -1e18)
                        mx[j] = std::max(mx[j], mx[j - 1] * x);
                    if (mn[j - 1] != 1e18)
                        mn[j] = std::min(mn[j], mn[j - 1] * x);
                } else {
                    if (mn[j - 1] != 1e18)
                        mx[j] = std::max(mx[j], mn[j - 1] * x);
                    if (mx[j - 1] != -1e18)
                        mn[j] = std::min(mn[j], mx[j - 1] * x);
                }
            }
        }
        std::cout << mx[5] << "\n";
    }
    return 0;
}