#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;
const int C = 30;

int n, m, T, x, y, z;
int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i <= C; ++i) a[i] = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x;
            for (int j = 0; j <= C; ++j) {
                if (x & (1 << j)) ++a[j];
            }
        }
        x = 0;
        for (int i = 0; i <= C; ++i) x = std::__gcd(x, a[i]);
        if (!x) {
            for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
            continue;
        }
        for (int i = 1; i <= x; ++i) {
            if (x % i == 0) std::cout << i << " \n"[i == x];
        }
    }
    return 0;
}