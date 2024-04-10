#include <bits/stdc++.h>
constexpr long long INF = 1e18;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        long long ans = -1;
        for (int c = 0; c < 10; ++c) {
            for (int d = 0; 9 * d + c <= n; ++d) {
                int a = k + 1, b = 0;
                for (int i = 0; i <= k; ++i)
                    b += (i + c) % 10 + (i + c < 10 ? 9 * d : 1);
                b = n - b;
                if (b < 0 || b % a != 0)
                    continue;
                int x = b / a;
                long long v;
                if (x < 8) {
                    v = x;
                } else {
                    x -= 8;
                    v = x % 9;
                    x -= v;
                    for (int i = 0; i < x / 9; ++i)
                        v = std::min(INF, 10 * v + 9);
                    v = std::min(INF, 10 * v + 8);
                }
                for (int i = 0; i < d; ++i)
                    v = std::min(INF, 10 * v + 9);
                v = std::min(INF, 10 * v + c);
                if (v < INF && (ans == -1 || v < ans))
                    ans = v;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}