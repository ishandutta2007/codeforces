#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <iomanip>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int sz = n;
    std::vector<int> k(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> k[i];
        if (k[i] > 0) {
            ++sz;
        } else {
            --sz;
        }
    }
    if (!sz) {
        std::cout << 0 << "\n";
        return 0;
    }
    auto check = [&](int x) {
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= x) {
                ++l;
            } else {
                ++r;
            }
        }
        for (int i = 0; i < q; ++i) {
            if (k[i] > 0) {
                if (k[i] <= x) {
                    ++l;
                } else {
                    ++r;
                }
            } else {
                if (-k[i] <= l) {
                    --l;
                } else {
                    --r;
                }
            }
        }
        return l > 0;
    };
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    std::cout << l << "\n";
    return 0;
}