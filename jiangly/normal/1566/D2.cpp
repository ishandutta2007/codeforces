#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int a[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i * m + j];
        }
    }
    
    int p[n * m];
    std::iota(p, p + n * m, 0);
    std::sort(p, p + n * m, [&](int i, int j) {
        if (a[i] != a[j]) {
            return a[i] < a[j];
        } else {
            return i < j;
        }
    });
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int l = 0, r; l < m; l = r) {
            for (r = l; r < m && a[p[i * m + l]] == a[p[i * m + r]]; r++)
                ;
            std::sort(p + i * m + l, p + i * m + r, std::greater());
        }
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (p[i * m + j] < p[i * m + k]) {
                    res++;
                }
            }
        }
    }
    
    std::cout << res << "\n";
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