#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q, mod;
    std::cin >> n >> q >> mod;
    
    std::vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) {
            a[i + 1] = (a[i + 1] - a[i] + mod) % mod;
            b[i + 1] = (b[i + 1] - b[i] + mod) % mod;
        }
        if (i + 2 < n) {
            a[i + 2] = (a[i + 2] - a[i] + mod) % mod;
            b[i + 2] = (b[i + 2] - b[i] + mod) % mod;
        }
    }
    
    std::vector<int> f(n + 1);
    f[0] = 1 % mod;
    f[1] = 1 % mod;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    
    int diff = 0;
    for (int i = 0; i < n; i++) {
        diff += (a[i] != b[i]);
    }
    
    auto add = [&](auto x, auto i, auto v) {
        diff -= (a[i] != b[i]);
        if (x == 'A') {
            a[i] = (a[i] + v) % mod;
        } else {
            b[i] = (b[i] + v) % mod;
        }
        diff += (a[i] != b[i]);
    };
    
    for (int i = 0; i < q; i++) {
        char x;
        int l, r;
        std::cin >> x >> l >> r;
        l--;
        
        add(x, l, 1);
        if (r < n) {
            add(x, r, (mod - f[r - l]) % mod);
        }
        if (r + 1 < n) {
            add(x, r + 1, (mod - f[r - l - 1]) % mod);
        }
        
        if (diff == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}