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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::vector<int> lc(n, -1), rc(n, -1);
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            rc[stk.back()] = lc[i];
            lc[i] = stk.back();
            stk.pop_back();
        }
        stk.push_back(i);
    }
    while (stk.size() >= 2) {
        int u = stk.back();
        stk.pop_back();
        rc[stk.back()] = u;
    }
    int ans = 0;
    struct Data {
        int pre, suf, sum;
    };
    std::function<Data(int)> dfs = [&](int u) {
        if (u == -1)
            return Data{0, 0, 0};
        auto l = dfs(lc[u]), r = dfs(rc[u]);
        ans = std::max(ans, l.suf + r.pre);
        return Data{std::max(l.pre, l.sum + a[u] + r.pre), std::max({r.suf, l.suf + a[u] + r.sum}), l.sum + a[u] + r.sum};
    };
    dfs(stk[0]);
    std::cout << ans << "\n";
    return 0;
}