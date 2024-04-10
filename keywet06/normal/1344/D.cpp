#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int64 k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    std::vector<bool> can(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    auto check = [&](int64 x) {
        int64 cnt = 0;
        for (int i = 0; i < n; ++i) {
            can[i] = false;
            int l = 0, r = a[i];
            while (l < r) {
                int m = (l + r) / 2;
                if (-3ll * m * m - 3ll * m - 1 + a[i] <= x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            b[i] = l;
            cnt += l;
            if (l < a[i] && -3ll * l * l - 3ll * l - 1 + a[i] == x) {
                can[i] = true;
                ++cnt;
            }
        }
        return cnt >= k;
    };
    int64 l = -4e18, r = 1e9;
    while (l < r) {
        int64 m = (l + r + 1) >> 1;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    check(l);
    k -= std::accumulate(b.begin(), b.end(), 0ll);
    for (int i = 0; i < n; ++i) {
        if (can[i] && k > 0) {
            ++b[i];
            --k;
        }
    }
    for (int i = 0; i < n; ++i) std::cout << b[i] << " \n"[i == n - 1];
    return 0;
}