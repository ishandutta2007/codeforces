#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, B, x, y;
    std::cin >> n >> B >> x >> y;
    
    i64 ans = 0, v = 0;
    for (int i = 0; i < n; i++) {
        if (v + x <= B) {
            v += x;
        } else {
            v -= y;
        }
        ans += v;
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