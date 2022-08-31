#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), l(n, n), r(n, -1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        l[a[i]] = std::min(l[a[i]], i);
        r[a[i]] = std::max(r[a[i]], i);
    }
    
    std::vector<std::pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        if (l[i] < r[i]) {
            b.emplace_back(l[i], r[i]);
        }
    }
    
    std::sort(b.begin(), b.end());
    std::vector<std::pair<int, int>> c;
    for (auto [l, r] : b) {
        if (c.empty() || r > c.back().second) {
            c.emplace_back(l, r);
        }
    }
    
    int x = -1;
    int m = c.size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (c[i].first > x) {
            ans += c[i].second - c[i].first - 1;
            x = c[i].second;
        } else if (i == m - 1 || c[i + 1].first > x) {
            ans += c[i].second - x - 1;
            x = c[i].second;
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}