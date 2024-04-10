#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    double res = 0;
    
    std::sort(a.begin(), a.end());
    
    for (int i = 0; i < n - 1; i++) {
        res += 1.0 * a[i] / (n - 1);
    }
    res += a[n - 1];
    
    std::cout << std::fixed << std::setprecision(10) << res << "\n";
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