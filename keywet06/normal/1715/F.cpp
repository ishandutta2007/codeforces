#include <bits/stdc++.h>

using float64 = long double;

int n, m;

float64 x, y, s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    std::cin >> n >> m;
    std::cout << "? " << 2 * m + 1 << '\n';
    for (int i = 0; i < m; ++i) {
        std::cout << n << ' ' << i << '\n';
        std::cout << 0 << ' ' << i << '\n';
    }
    std::cout << n << ' ' << m << std::endl;
    std::cin >> s;
    x = s * n - 0.5;
    std::cout << "? " << 2 * n + 1 << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << i << ' ' << m << '\n';
        std::cout << i << ' ' << 0 << '\n';
    }
    std::cout << n << ' ' << m << std::endl;
    std::cin >> s;
    y = s * m - 0.5;
    std::cout << "! " << x << ' ' << y << '\n';
    return 0;
}