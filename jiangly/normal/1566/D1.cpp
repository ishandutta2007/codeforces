#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int a[m];
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    
    int p[m];
    std::iota(p, p + m, 0);
    std::sort(p, p + m, [&](int i, int j) {
        if (a[i] != a[j]) {
            return a[i] < a[j];
        } else {
            return i > j;
        }
    });
    
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (p[i] < p[j]) {
                res++;
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