#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    
    int ans = b - a;
    
    for (int i = a; i < b; i++) {
        int x = b;
        for (int j = 20; j >= 0; j--) {
            if (i >> j & 1) {
                if (~x >> j & 1) {
                    x |= 1 << j;
                    x &= ~((1 << j) - 1);
                }
            }
        }
        ans = std::min(ans, i - a + 1 + x - b);
    }
    
    std::cout << ans << "\n";
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