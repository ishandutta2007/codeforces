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
    long long x;
    std::cin >> x;
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i)
        std::cin >> d[i];
    n *= 2;
    d.insert(d.end(), d.begin(), d.end());
    long long s = 0, ans = 0, v = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        s += d[i];
        v += 1ll * d[i] * (d[i] + 1) / 2;
        while (s - d[j] >= x) {
            v -= 1ll * d[j] * (d[j] + 1) / 2;
            s -= d[j++];
        }
        if (s >= x)
            ans = std::max(ans, v - (s - x) * (s - x + 1) / 2);
    }
    std::cout << ans << "\n";
    return 0;
}