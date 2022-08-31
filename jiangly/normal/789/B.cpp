#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int b, q, l, m;
    std::cin >> b >> q >> l >> m;
    
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    int ans = 0;
    for (int64_t i = b, t = 0; std::abs(i) <= l && t < 100; i *= q, ++t) {
        if (!std::binary_search(a.begin(), a.end(), i)) {
            ++ans;
        }
    }
    if (ans > 40) {
        std::cout << "inf\n";
    } else {
        std::cout << ans << "\n";
    }
    
    return 0;
}