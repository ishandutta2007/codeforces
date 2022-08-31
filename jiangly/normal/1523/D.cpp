#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto begin = std::chrono::steady_clock::now();
    std::mt19937 rnd(begin.time_since_epoch().count());
    i64 ans = 0;
    while ((std::chrono::steady_clock::now() - begin).count() < 2e9) {
        int x = rnd() % n;
        std::vector<int> v;
        for (int i = 0; i < m; i++) {
            if (a[x][i] == '1') {
                v.push_back(i);
            }
        }
        int s = v.size();
        std::vector<int> sum(1 << s);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < s; j++) {
                mask |= (a[i][v[j]] == '1') << j;
            }
            sum[mask]++;
        }
        for (int i = 1; i < (1 << s); i *= 2) {
            for (int j = 0; j < (1 << s); j += 2 * i) {
                for (int k = 0; k < i; k++) {
                    sum[j + k] += sum[i + j + k];
                }
            }
        }
        int cur = 0;
        for (int i = 0; i < (1 << s); i++) {
            if (sum[i] >= (n + 1) / 2 && __builtin_popcount(i) > __builtin_popcount(cur)) {
                cur = i;
            }
        }
        if (__builtin_popcount(cur) > __builtin_popcountll(ans)) {
            ans = 0;
            for (int i = 0; i < s; i++) {
                if (cur >> i & 1) {
                    ans |= 1ll << v[i];
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        std::cout << (ans >> i & 1);
    }
    std::cout << "\n";
    return 0;
}