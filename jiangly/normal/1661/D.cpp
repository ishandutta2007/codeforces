#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<i64> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    i64 ans = 0;
    i64 u = 0, a = 0;
    std::vector<i64> c(n), d(n);
    for (int i = n - 1; i >= 0; i--) {
        u += c[i];
        a += d[i];
        b[i] += u * i + a;
        i64 v = std::min(i + 1, k);
        if (b[i] > 0) {
            i64 t = (b[i] + v - 1) / v;
            u -= t;
            a -= t * (v - i);
            ans += t;
            if (i - v >= 0) {
                c[i - v] += t;
                d[i - v] += t * (v - i);
            }
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}