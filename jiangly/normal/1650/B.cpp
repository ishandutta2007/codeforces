#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r, a;
    std::cin >> l >> r >> a;
    
    int ans = r / a + r % a;
    int v = (r + 1) / a * a - 1;
    if (v >= l) {
        ans = std::max(ans, v / a + v % a);
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