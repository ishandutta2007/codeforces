#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, H, M;
    std::cin >> n >> H >> M;
    
    const int cur = H * 60 + M;
    int ans = 1440;
    
    for (int i = 0; i < n; i++) {
        int h, m;
        std::cin >> h >> m;
        
        const int x = h * 60 + m;
        
        const int res = (x - cur + 1440) % 1440;
        ans = std::min(ans, res);
    }
    
    std::cout << ans / 60 << " " << ans % 60 << "\n";
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