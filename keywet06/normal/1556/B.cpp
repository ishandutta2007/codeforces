#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int64 T, n, k, x, y, z;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, x = y = z = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], x += a[i] & 1;
        if (std::abs(n - x - x) > 1) {
            std::cout << -1 << '\n';
            continue;
        }
        if (n & 1) {
            if (x == n / 2) {
                for (int i = 1; i <= n; ++i) {
                    if (a[i] & 1) z += std::abs(i - (++y) * 2);
                }
            } else {
                for (int i = 1; i <= n; ++i) {
                    if (a[i] & 1) z += std::abs(i - (++y) * 2 + 1);
                }
            }
            std::cout << z << '\n';
        } else {
            for (int i = 1; i <= n; ++i) {
                if (a[i] & 1) z += std::abs(i - (++y) * 2);
            }
            k = z, y = z = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] & 1) z += std::abs(i - (++y) * 2 + 1);
            }
            std::cout << std::min(k, z) << '\n';
        }
    }
    return 0;
}