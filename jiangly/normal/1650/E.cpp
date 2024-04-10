#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, d;
    std::cin >> n >> d;
    
    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        t[i] = a[i] - (i == 0 ? 0 : a[i - 1] + 1);
    }
    
    int j = std::min_element(t.begin(), t.end()) - t.begin();
    int ans = 0;
    for (auto x : {j - 1, j}) {
        if (x < 0) {
            continue;
        }
        
        int last = -1, mx = 0, mn = d;
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            mx = std::max(mx, a[i] - last - 1);
            mn = std::min(mn, a[i] - last - 1);
            last = a[i];
        }
        
        ans = std::max(ans, std::min(mn, std::max(d - 2 - last, (mx - 1) / 2)));
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