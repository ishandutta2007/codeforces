#include <bits/stdc++.h>

void fwt(std::vector<int64_t> &a) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                int64_t u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

void ifwt(std::vector<int64_t> &a) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                int64_t u = a[j + k], v = a[i + j + k];
                a[j + k] = (u + v) / 2;
                a[i + j + k] = (u - v) / 2;
            }
        }
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int64_t> a(1 << n), b(1 << n);
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    
    for (int i = 0; i < m; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) x = 2 * x + s[j][i] - '0';
        ++a[x];
    }
    
    for (int i = 0; i < (1 << n); ++i) {
        int c = __builtin_popcount(i);
        b[i] = std::min(c, n - c);
    }
    
    fwt(a);
    fwt(b);
    for (int i = 0; i < (1 << n); ++i) a[i] *= b[i];
    ifwt(a);
    
    int ans = n * m;
    for (int i = 0; i < (1 << n); ++i) ans = std::min<int>(ans, a[i]);
    
    std::cout << ans << "\n";
    
    return 0;
}