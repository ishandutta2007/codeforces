#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> r(n);
    std::vector<int> g(n);
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (i == j) {
            g[i] = std::gcd(a[i], i == k ? 0 : g[i - 1]);
            j++;
        }
        
        while (j < n && std::gcd(g[i], g[j - 1]) > j - i) {
            g[j] = std::gcd(a[j], j == k ? 0 : g[j - 1]);
            j++;
        }
        
        if (std::gcd(g[i], g[j - 1]) == j - i) {
            r[i] = j;
        } else {
            r[i] = n + 1;
        }
        
        if (i == k) {
            k = j;
            for (int x = k - 1; x >= i; x--) {
                g[x] = std::gcd(a[x], x == k - 1 ? 0 : g[x + 1]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0, m = n + 1; i < n; i++) {
        m = std::min(m, r[i]);
        
        if (i == m - 1) {
            ans++;
            m = n + 1;
        }
        
        std::cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}