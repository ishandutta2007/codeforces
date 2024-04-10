#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, m, k;
int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k;
        if (n & 1) {
            if (k < m / 2) {
                std::cout << "NO\n";
                continue;
            }
            k -= m / 2, --n;
            std::cout << (k & 1 ? "NO\n" : "YES\n");
            continue;
        }
        if (m & 1) {
            if (k & 1 || k > m / 2 * n) {
                std::cout << "NO\n";
                continue;
            }
            std::cout << "YES\n";
            continue;
        }
        std::cout << (k & 1 ? "NO\n" : "YES\n");
    }
    return 0;
}