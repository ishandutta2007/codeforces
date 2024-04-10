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
        int n, m;
        std::cin >> n >> m;
        std::vector<long long> t(n);
        long long cnt = (1ll << m) - n;
        long long k = (cnt - 1) / 2;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            for (int j = 0; j < m; ++j)
                t[i] = 2 * t[i] + s[j] - '0';
        }
        std::sort(t.begin(), t.end());
        long long ans = -1;
        long long last = 0;
        for (int i = 0; i < n; ++i) {
            if (k < t[i] - last) {
                ans = last + k;
                break;
            }
            k -= t[i] - last;
            last = t[i] + 1;
        }
        if (ans == -1)
            ans = last + k;
        for (int i = m - 1; i >= 0; --i)
            std::cout << (ans >> i & 1);
        std::cout << "\n";
    }
    return 0;
}