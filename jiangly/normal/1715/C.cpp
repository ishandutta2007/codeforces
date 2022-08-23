#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 1LL * n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        ans += 1LL * (a[i - 1] != a[i]) * i * (n - i);
    }
    
    for (int i = 0; i < m; i++) {
        int p, x;
        std::cin >> p >> x;
        p--;
        
        if (p) {
            ans += 1LL * ((a[p - 1] != x) - (a[p - 1] != a[p])) * p * (n - p);
        }
        if (p < n - 1) {
            ans += 1LL * ((a[p + 1] != x) - (a[p + 1] != a[p])) * (p + 1) * (n - p - 1);
        }
        a[p] = x;
        std::cout << ans << "\n";
    }
    
    return 0;
}