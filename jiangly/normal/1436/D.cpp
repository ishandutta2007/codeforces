#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> p(n, -1), siz(n, 1);
    std::vector<int64_t> a(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> p[i];
        siz[--p[i]] = 0;
    }
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int64_t ans = 0;
    for (int i = n - 1; ; --i) {
        ans = std::max(ans, (a[i] + siz[i] - 1) / siz[i]);
        if (i == 0) break;
        a[p[i]] += a[i];
        siz[p[i]] += siz[i];
    }
    std::cout << ans << "\n";
    
    return 0;
}