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
        int n, x;
        std::cin >> n >> x;
        int deg = 0;
        for (int i = 0; i < n - 1; ++i){
            int u, v;
            std::cin >> u >> v;
            if (u == x || v == x)
                ++deg;
        }
        if (deg >= 2 && (n & 1)) {
            std::cout << "Ashish\n";
        } else {
            std::cout << "Ayush\n";
        }
    }
    return 0;
}