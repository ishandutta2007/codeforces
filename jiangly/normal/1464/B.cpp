#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <tuple>
#include <queue>
#include <complex>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <functional>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    int n = s.length();
    int x, y;
    std::cin >> x >> y;
    
    i64 s0 = 0, s1 = 0;
    int c0 = 0, c1 = 0;
    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++c0;
            s0 += i;
        } else if (s[i] == '1') {
            ++c1;
            s1 += i;
        } else {
            p.push_back(i);
        }
    }
    
    i64 ans = 9e18;
    
    int m = p.size();
    
    if (x > y) {
        std::swap(s0, s1);
        std::swap(c0, c1);
        std::swap(x, y);
    }
    
    s1 += std::accumulate(p.begin(), p.end(), 0ll);
    c1 += m;
    
    for (int i = 0; i <= m; ++i) {
        ans = std::min(ans, (s0 - i64(c0) * (c0 - 1) / 2) * y + (s1 - i64(c1) * (c1 - 1) / 2) * x);
        if (i < m) {
            s0 += p[i];
            ++c0;
            s1 -= p[i];
            --c1;
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}