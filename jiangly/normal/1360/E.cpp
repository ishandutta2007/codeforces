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
        int n;
        std::cin >> n;
        std::vector<std::vector<bool>> a(n, std::vector<bool>(n));
        std::vector<std::string> t(n);
        for (int i = 0; i < n; ++i)
            std::cin >> t[i];
        for (int i = 0; i < n; ++i) {
            if (t[n - 1][i] == '1')
                a[n - 1][i] = true;
            if (t[i][n - 1] == '1')
                a[i][n - 1] = true;
        }
        for (int i = n - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                a[i][j] = (t[i][j] == '1') && (a[i + 1][j] || a[i][j + 1]);
        bool ok = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (t[i][j] == '1' && !a[i][j])
                    ok = false;
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}