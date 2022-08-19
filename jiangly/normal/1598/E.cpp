#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector free(n, std::vector(m, true));
    
    auto get = [&](int d) {
        int ans = 0;
        int cnt = 0;
        for (int y = 0; y < m; y++) {
            for (auto x : { y + d, y + d + 1 }) {
                if (0 <= x && x < n && free[x][y]) {
                    ans += cnt++;
                } else {
                    cnt = 0;
                }
            }
        }
        return ans;
    };
    
    i64 ans = n * m;
    
    for (int d = -m; d < n; d++) {
        ans += get(d);
    }
    
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        
        ans -= get(x - y - 1);
        ans -= get(x - y);
        if (free[x][y]) {
            free[x][y] = false;
            ans--;
        } else {
            free[x][y] = true;
            ans++;
        }
        ans += get(x - y - 1);
        ans += get(x - y);
        
        std::cout << ans << "\n";
    }
    
    return 0;
}