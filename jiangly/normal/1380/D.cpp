#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int x, k, y;
    std::cin >> x >> k >> y;
    std::vector<int> a(n + 2), b(m);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];
    std::vector<int> p{0};
    for (int i = 1, j = 0; i <= n; ++i) {
        if (j < m && a[i] == b[j]) {
            p.push_back(i);
            ++j;
        }
    }
    if (int(p.size()) < m + 1) {
        std::cout << -1 << "\n";
        return 0;
    }
    p.push_back(n + 1);
    int64_t ans = 0;
    for (int i = 0; i < m + 1; ++i) {
        int l = p[i], r = p[i + 1];
        int len = r - l - 1;
        if (len == 0)
            continue;
        int mx = *std::max_element(a.begin() + l + 1, a.begin() + r);
        if (len < k) {
            if (std::max(a[l], a[r]) < mx) {
                std::cout << -1 << "\n";
                return 0;
            }
            ans += 1ll * len * y;
        } else if (x < 1ll * k * y) {
            ans += 1ll * (len % k) * y + 1ll * len / k * x;
        } else if (std::max(a[l], a[r]) < mx) {
            ans += x + 1ll * (len - k) * y;
        } else {
            ans += 1ll * len * y;
        }
    }
    std::cout << ans << "\n";
    return 0;
}