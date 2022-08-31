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
    int n;
    std::cin >> n;
    int m = (n + 1) / 2;
    std::vector<long long> a(m);
    for (int i = 0; i < m; ++i)
        std::cin >> a[i];
    int x;
    std::cin >> x;
    for (int i = m - 2; i >= 0; --i)
        a[i] += a[i + 1];
    for (int i = 0; i < m; ++i)
        a[i] += 1ll * i * x;
    for (int i = 1; i < m; ++i)
        a[i] = std::min(a[i], a[i - 1]);
    for (int k = n; n - k < m; --k) {
        if (a[n - k] > 1ll * (m - k) * x) {
            std::cout << k << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";
    return 0;
}