#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    
    int n = a + b;
    
    bool can[n + 1];
    std::memset(can, 0, sizeof(can));
    
    for (int i = std::abs(a - (n + 1) / 2); i <= n - std::abs(b - (n + 1) / 2); i += 2) {
        can[i] = true;
    }
    for (int i = std::abs(a - n / 2); i <= n - std::abs(b - n / 2); i += 2) {
        can[i] = true;
    }
    
    int cnt = std::count(can, can + n + 1, true);
    
    std::cout << cnt << "\n";
    for (int i = 0; i <= n; i++) {
        if (can[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
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