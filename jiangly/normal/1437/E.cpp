#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= i;
    }
    std::vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> b[i];
        --b[i];
    }
    int ans = n - k;
    auto work = [&](int l, int r, int vl, int vr) {
        std::vector<int> f;
        for (int i = l; i < r; ++i) {
            if (vl <= a[i] && a[i] <= vr) {
                auto it = std::upper_bound(f.begin(), f.end(), a[i]);
                if (it == f.end()) f.push_back(a[i]);
                else *it = a[i];
            }
        }
        return int(f.size());
    };
    if (k == 0) ans -= work(0, n, -1e9, 1e9);
    else {
        ans -= work(0, b[0], -1e9, a[b[0]]);
        ans -= work(b[k - 1] + 1, n, a[b[k - 1]], 1e9);
        for (int i = 0; i + 1 < k; ++i) {
            if (a[b[i]] > a[b[i + 1]]) {
                std::cout << -1 << "\n";
                return 0;
            }
            ans -= work(b[i] + 1, b[i + 1], a[b[i]], a[b[i + 1]]);
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}