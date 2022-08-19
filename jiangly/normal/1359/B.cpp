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
        int n, m, x, y;
        std::cin >> n >> m >> x >> y;
        int ans = 0;
        y = std::min(y, 2 * x);
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            for (int l = 0, r; l < m; ) {
                if (s[l] == '*') {
                    ++l;
                } else {
                    for (r = l; r < m && s[r] == '.'; ++r)
                        ;
                    ans += (r - l) / 2 * y + (r - l) % 2 * x;
                    l = r;
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}