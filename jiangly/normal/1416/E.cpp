#include <bits/stdc++.h>

constexpr int64_t Inf = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int mx = 0;
        int64_t pos = Inf;
        std::set<int64_t> good;
        int64_t l = 1, r = a[0] - 1;
        int k = 1;
        int64_t b = 0;
        auto index = [&](int64_t x) {
            return k * (x - b);
        };
        auto ismax = [&](int x) {
            int64_t i = index(x);
            if (pos == Inf) {
                return good.count(i) || (l <= i && i <= r);
            } else {
                return pos == i;
            }
        };
        if (a[0] % 2 == 0) {
            ++mx;
            good.insert(a[0] / 2);
            l = 1, r = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (pos != Inf) {
                good = {pos};
                l = 1, r = 0;
                pos = Inf;
            }
            if (a[i] % 2 == 0) {
                if (ismax(a[i] / 2)) {
                    mx += 2;
                    pos = index(a[i] / 2);
                } else {
                    ++mx;
                    good.insert(index(a[i] / 2));
                }
            } else {
                ++mx;
            }
            k = -k;
            b = -b + a[i];
            int64_t L = index(1), R = index(a[i] - 1);
            if (L > R) std::swap(L, R);
            if (l < L) l = L;
            if (r > R) r = R;
            while (!good.empty() && *good.begin() < L) good.erase(good.begin());
            while (!good.empty() && *good.rbegin() > R) good.erase(*good.rbegin());
            if (pos == Inf && good.empty() && l > r) {
                l = L, r = R;
                --mx;
            }
        }
        std::cout << 2 * n - mx << "\n";
    }
    
    return 0;
}