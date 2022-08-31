#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>
#include <set>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <cstring>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, a, b;
        std::cin >> n >> m >> a >> b;
        if (a * n != b * m) {
            std::cout << "NO\n";
            continue;
        }
        std::function<std::vector<std::string>(int, int, int, int)> get = [&](int n, int m, int a, int b) {
            if (m == 0)
                return std::vector<std::string>(n);
            int t = n / m;
            auto f = get(m, n - t * m, b - t * a, a);
            std::vector<std::string> s(n, std::string(m, '0'));
            for (int i = 0; i < t; ++i)
                for (int j = 0; j < m; ++j)
                    for (int k = 0; k < a; ++k)
                        s[i * m + j][(j + k) % m] = '1';
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n - t * m; ++j)
                    s[t * m + j][i] = f[i][j];
            return s;
        };
        std::cout << "YES\n";
        auto s = get(n, m, a, b);
        for (int i = 0; i < n; ++i)
            std::cout << s[i] << "\n";
    }
    return 0;
}