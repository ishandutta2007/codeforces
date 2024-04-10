#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    int mx = *std::max_element(h.begin(), h.end());
    
    i64 ans = 1E18;
    
    for (auto x : {mx, mx + 1}) {
        i64 c2 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            int v = x - h[i];
            c2 += v / 2;
            c1 += v % 2;
        }
        i64 d = c2 - c1;
        if (d > 3) {
            i64 v = (d - 3) / 3;
            c2 -= v;
            c1 += 2 * v;
        }
        for (int i = 0; i < 10; i++) {
            if (c2 >= i) {
                ans = std::min(ans, std::max(2 * (c1 + 2 * i) - 1, 2 * (c2 - i)));
            }
        }
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