#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int last = 0, x, Min = n, Max = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> x;
            if (last == x) {
                Min = std::min(Min, i);
                Max = std::max(Max, i);
            }
            last = x;
        }
        std::cout << (Max <= Min ? 0 : std::max(Max - Min - 1, 1)) << '\n';
    }
    return 0;
}