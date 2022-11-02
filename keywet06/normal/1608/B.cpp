#include <bits/stdc++.h>

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int N = 1000005;

int64 T, n, m, a, b, e;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> a >> b;
        if (std::abs(a - b) > 1 || a + b + 2 > n) {
            std::cout << -1 << '\n';
            continue;
        }
        if (a > b) {
            e = n - a * 2;
            for (int i = 1; i <= a; ++i) {
                std::cout << e + i << ' ' << e + a + i << ' ';
            }
            for (int i = 1; i <= e; ++i) {
                std::cout << e - i + 1 << " \n"[i == e];
            }
        } else if (a == b) {
            for (int i = 1; i <= a; ++i) {
                std::cout << i << ' ' << a + i + 1 << ' ';
            }
            std::cout << a + 1 << ' ';
            for (int i = a * 2 + 2; i <= n; ++i) {
                std::cout << i << " \n"[i == n];
            }
        } else {
            for (int i = 1; i <= b; ++i) {
                std::cout << b + i << ' ' << i << ' ';
            }
            for (int i = 2 * b + 1; i <= n; ++i) {
                std::cout << i << " \n"[i == n];
            }
        }
    }
    return 0;
}