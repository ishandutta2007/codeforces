#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    
    std::vector<int> cnta(n), cntb(n);
    for (int i = 0; i < n; i++) {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }
    
    i64 ans = 1LL * n * (n - 1) * (n - 2) / 6;
    
    for (int i = 0; i < n; i++) {
        ans -= 1LL * (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
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