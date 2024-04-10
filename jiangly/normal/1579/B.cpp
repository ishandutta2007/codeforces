#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::tuple<int, int, int>> res;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        int j = std::min_element(a + i, a + n) - a;
        if (i == j) {
            continue;
        }
        std::rotate(a + i, a + j, a + n);
        res.emplace_back(i, n, j - i);
    }
    
    std::cout << res.size() << "\n";
    for (auto [l, r, d] : res) {
        std::cout << l + 1 << " " << r << " " << d << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}