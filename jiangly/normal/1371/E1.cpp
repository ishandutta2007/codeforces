#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, p;
    std::cin >> n >> p;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int low = 0;
    for (int i = 0; i < n; ++i)
        low = std::max(low, a[i] - i);
    int l = low - 1, r = 1e9;
    auto check = [&](int x) {
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[j] <= x + i)
                ++j;
            if (j - i >= p || j - i <= 0)
                return false;
        }
        return true;
    };
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if (l == low - 1) {
        std::cout << 0 << "\n";
    } else {
        std::cout << l - low + 1 << "\n";
        for (int i = low; i <= l; ++i)
            std::cout << i << " \n"[i == l];
    }
    return 0;
}