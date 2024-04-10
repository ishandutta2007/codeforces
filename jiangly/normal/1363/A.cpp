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
        int cnt[2] = {};
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            ++cnt[a & 1];
        }
        if (x == n) {
            std::cout << (cnt[1] & 1 ? "Yes" : "No") << "\n";
        } else if (!cnt[1] || (!cnt[0] && !(x & 1))) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }
    return 0;
}