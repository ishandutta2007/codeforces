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
        int n, k;
        std::cin >> n >> k;
        int ans = n;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i <= k)
                    ans = std::min(ans, n / i);
                if (n / i <= k)
                    ans = std::min(ans, i);
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}