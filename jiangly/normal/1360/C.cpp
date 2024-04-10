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
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int even = std::count_if(a.begin(), a.end(), [&](int n) {return n % 2 == 0;});
        if (even % 2 == 0) {
            std::cout << "YES\n";
        } else {
            bool ok = false;
            for (int i = 0; i < n - 1; ++i)
                if (a[i + 1] - a[i] == 1)
                    ok = true;
            if (ok) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}