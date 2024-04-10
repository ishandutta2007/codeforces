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

constexpr int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b > 0; b /= 2, a = i64(a) * a % P) {
        if (b % 2 == 1) {
            res = i64(res) * a % P;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        ++deg[v];
    }
    
    std::vector<int> que;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            que.push_back(i);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int u = que[i];
        for (auto v : e[u]) {
            if (--deg[v] == 0) {
                que.push_back(v);
            }
        }
    }
    
    std::vector<int> sg(n);
    int k = 1;
    for (int i = n - 1; i >= 0; --i) {
        int u = que[i];
        std::vector<int> cnt(e[u].size() + 1);
        for (auto v : e[u]) {
            if (sg[v] <= int(e[u].size())) {
                ++cnt[sg[v]];
            }
        }
        while (cnt[sg[u]] > 0) {
            ++sg[u];
        }
        while (sg[u] >= k) {
            k *= 2;
        }
    }
    
    std::vector<int> f(k);
    f[0] = n + 1;
    for (int i = 0; i < n; ++i) {
        f[sg[i]] = (f[sg[i]] - 1 + P) % P;
    }
    
    for (int i = 1; i < k; i *= 2) {
        for (int j = 0; j < k; j += 2 * i) {
            for (int l = 0; l < i; ++l) {
                int u = f[j + l], v = f[i + j + l];
                f[j + l] = (u + v) % P;
                f[i + j + l] = (u - v + P) % P;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans = (ans + power(f[i], P - 2)) % P;
    }
    
    ans = i64(ans) * power(k, P - 2) % P;
    ans = (1 - ans + P) % P;
    
    std::cout << ans << "\n";
    
    return 0;
}