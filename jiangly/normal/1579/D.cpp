#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::priority_queue<std::pair<int, int>> h;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            h.emplace(a[i], i);
        }
    }
    
    std::vector<std::pair<int, int>> res;
    while (h.size() > 1) {
        auto [a1, i] = h.top();
        h.pop();
        auto [a2, j] = h.top();
        h.pop();
        res.emplace_back(i, j);
        if (a1 > 1) {
            h.emplace(a1 - 1, i);
        }
        if (a2 > 1) {
            h.emplace(a2 - 1, j);
        }
    }
    
    std::cout << res.size() << "\n";
    for (auto [u, v] : res) {
        std::cout << u + 1 << " " << v + 1 << "\n";
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