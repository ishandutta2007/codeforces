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
#include <map>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        if (m <= n / k) {
            std::cout << m << "\n";
        } else {
            std::cout << n / k - (m - n / k + k - 2) / (k - 1) << "\n";
        }
    }
    return 0;
}