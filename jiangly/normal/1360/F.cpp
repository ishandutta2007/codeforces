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
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i)
            std::cin >> s[i];
        auto check = [&](std::string t) {
            for (int i = 0; i < n; ++i) {
                int cnt = 0;
                for (int j = 0; j < m; ++j)
                    cnt += (s[i][j] != t[j]);
                if (cnt > 1)
                    return false;
            }
            return true;
        };
        std::string ans = "-1";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int c = 0; c < 26; ++c) {
                    std::string t = s[i];
                    t[j] = 'a' + c;
                    if (check(t))
                        ans = t;
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}