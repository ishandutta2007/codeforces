#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> h(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> h[i];
    }
    std::sort(h.begin(), h.end());
    
    for (int i = 0; i < n; i++) {
        if (h[i] + x > h[i + n]) {
            std::cout << "NO\n";
            return;
        }
    }
    
    std::cout << "YES\n";
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