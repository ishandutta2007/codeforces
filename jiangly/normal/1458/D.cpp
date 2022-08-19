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
#include <cassert>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> match(n);
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '0' ? 1 : -1);
    }
    std::vector<int> up(2 * n + 1), down(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        if (pre[i] < pre[i + 1]) {
            ++up[pre[i] + n];
        } else {
            ++down[pre[i] + n];
        }
    }
    std::vector<int> a(n + 1);
    int x = n;
    for (int i = 1; i <= n; ++i) {
        if (up[x] > 0 && (down[x] == 0 || down[x + 1] > 0)) {
            --up[x];
            ++x;
        } else {
            --down[x];
            --x;
        }
        a[i] = x - n;
    }
    for (int i = 0; i < n; ++i) {
        s[i] = a[i] < a[i + 1] ? '0' : '1';
    }
    std::cout << s << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}