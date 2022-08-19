#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    
    int ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int mn = a[0], mx = a[0];
    for (int i = 0; i < n; i++) {
        mn = std::min(a[i], mn);
        mx = std::max(a[i], mx);
        if (mx - mn > 2 * x) {
            ans++;
            mn = mx = a[i];
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