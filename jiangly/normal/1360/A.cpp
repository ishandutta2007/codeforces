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
        int a, b;
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        int c = std::max(2 * a, b);
        std::cout << c * c << "\n";
    }
    return 0;
}