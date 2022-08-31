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
        std::string s;
        std::cin >> s;
        int n = s.length();
        std::vector<int> sum(n + 1);
        int ans = n;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + s[i] - '0';
        for (int i = 0; i <= n; ++i)
            ans = std::min({ans, sum[i] + (n - i) - (sum[n] - sum[i]), i - sum[i] + (sum[n] - sum[i])});
        std::cout << ans << "\n";
    }
    return 0;
}