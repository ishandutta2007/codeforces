#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    
    i64 m;
    std::cin >> m;
    
    auto getCost = [&](auto l, auto k) {
        i64 v = l / (k + 1);
        i64 c = l % (k + 1);
        return v * v * (k + 1 - c) + (v + 1) * (v + 1) * c;
    };
    
    auto get = [&](auto x) {
        i64 cnt = 0, val = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = a[i + 1] - a[i] - 1;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (getCost(a[i + 1] - a[i], m - 1) - getCost(a[i + 1] - a[i], m) >= x) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            cnt += l;
            val += getCost(a[i + 1] - a[i], l);
        }
        return std::pair(cnt, val);
    };
    
    i64 vl = 0, vr = 1E18;
    while (vr - vl > 1) {
        i64 x = (vl + vr) / 2;
        auto [cnt, val] = get(x);
        if (val > m) {
            vr = x;
        } else {
            vl = x;
        }
    }
    
    auto [cnt, val] = get(vr);
    std::cout << cnt + (val - m + vl - 1) / vl << "\n";
    
    return 0;
}