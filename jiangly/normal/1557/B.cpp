#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto values = a;
    std::sort(values.begin(), values.end());
    
    int need = 1;
    
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(values.begin(), values.end(), a[i]) - values.begin();
        
        if (i > 0 && a[i] != a[i - 1] + 1) {
            need++;
        }
    }
    
    std::cout << (need <= k ? "Yes" : "No") << "\n";
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