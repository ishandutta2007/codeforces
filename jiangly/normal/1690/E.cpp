#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    i64 ans = 0;
    std::vector<int> a(n);
    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ans += a[i] / k;
        a[i] %= k;
        s.insert(a[i]);
    }
    
    while (!s.empty()) {
        int x = *s.begin();
        s.erase(s.begin());
        
        auto it = s.lower_bound(k - x);
        if (it != s.end()) {
            s.erase(it);
            ans++;
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