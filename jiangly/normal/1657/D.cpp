#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, C;
    std::cin >> n >> C;
    
    std::vector<i64> f(C + 1);
    for (int i = 0; i < n; i++) {
        int c, d, h;
        std::cin >> c >> d >> h;
        f[c] = std::max(f[c], 1LL * d * h);
    }
    
    for (int i = 1; i <= C; i++) {
        for (int j = 2 * i; j <= C; j += i) {
            f[j] = std::max(f[j], f[i] * (j / i));
        }
    }
    
    for (int i = 1; i <= C; i++) {
        f[i] = std::max(f[i - 1], f[i]);
    }
    
    int m;
    std::cin >> m;
    
    for (int i = 0; i < m; i++) {
        int d;
        i64 h;
        std::cin >> d >> h;
        
        int j = std::upper_bound(f.begin(), f.end(), d * h) - f.begin();
        if (j > C) {
            j = -1;
        }
        std::cout << j << " \n"[i == m - 1];
    }
    
    return 0;
}