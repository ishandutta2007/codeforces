#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n), d(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::adjacent_difference(a.begin(), a.end(), d.begin());
    int64_t sum = 0;
    for (int i = 0; i < n; ++i)
        if (i == 0 || d[i] > 0)
            sum += d[i];
    std::cout << ((sum + 1) >> 1) << "\n";
    auto add = [&](int x, int v) {
        if (x == 0 || d[x] > 0)
            sum -= d[x];
        d[x] += v;
        if (x == 0 || d[x] > 0)
            sum += d[x];
    };
    int q;
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        --l;
        add(l, x);
        if (r < n)
            add(r, -x);
        std::cout << ((sum + 1) >> 1) << "\n";
    }
    return 0;
}