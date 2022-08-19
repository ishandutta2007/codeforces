#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <tuple>
#include <queue>
#include <complex>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <functional>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    i64 g = 0;
    for (int i = 0; i < n - 1; ++i) {
        g = std::gcd(g, a[i] - a[i + 1]);
    }
    
    for (int i = 0; i < m; ++i) {
        std::cout << std::gcd(g, a[0] + b[i]) << " \n"[i == m - 1];
    }
    
    return 0;
}