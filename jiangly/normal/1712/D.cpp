#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int l = 0, r = 1E9;
    while (l < r) {
        int x = (l + r + 1) / 2;
        
        int ans = 0;
        auto b = a;
        for (int i = 0; i < n; i++) {
            if (2 * b[i] < x) {
                b[i] = 1E9;
                ans++;
            }
        }
        bool two = false, one = false;
        for (int i = 0; i < n; i++) {
            if (b[i] >= x) {
                one = true;
            }
            if (i < n - 1 && std::min(b[i], b[i + 1]) >= x) {
                two = true;
            }
        }
        
        ans += !two + !one;
        
        if (ans <= k) {
            l = x;
        } else {
            r = x - 1;
        }
    }
    
    std::cout << l << "\n";
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