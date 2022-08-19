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
        int h, c, t;
        std::cin >> h >> c >> t;
        if (2 * t <= h + c) {
            std::cout << 2 << "\n";
        } else if (t >= h) {
            std::cout << 1 << "\n";
        } else {
            long long n = ((h - c) / (2 * t - c - h) - 1) / 2;
            if ((4 * n * n + 6 * n + 1) * c + (4 * n * n + 10 * n + 5) * h <= 2 * (2 * n + 1) * (2 * n + 3) * t) {
                std::cout << 2 * n + 1 << "\n";
            } else {
                std::cout << 2 * n + 3 << "\n";
            }
        }
    }
    return 0;
}