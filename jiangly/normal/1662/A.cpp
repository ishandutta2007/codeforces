#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> f(10);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        y--;
        f[y] = std::max(f[y], x);
    }
    
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (f[i] == 0) {
            std::cout << "MOREPROBLEMS\n";
            return;
        }
        ans += f[i];
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