#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        std::cout << "? " << (1 << i) - ans << " " << (3 << i) - ans << std::endl;
        int res;
        std::cin >> res;
        if (res == (2 << i)) {
            ans += 1 << i;
        }
    }
    std::cout << "! " << ans << std::endl;
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