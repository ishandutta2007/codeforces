#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int b;
        std::cin >> b;
        a[i] = b - a[i];
    }
    
    i64 s[n + 1];
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    i64 mx[n][20], mn[n][20];
    for (int i = 0; i < n; i++) {
        mx[i][0] = mn[i][0] = s[i];
    }
    for (int j = 0; (1 << (j + 1)) <= n; j++) {
        for (int i = 0; i + (1 << (j + 1)) <= n; i++) {
            mx[i][j + 1] = std::max(mx[i][j], mx[i + (1 << j)][j]);
            mn[i][j + 1] = std::min(mn[i][j], mn[i + (1 << j)][j]);
        }
    }
    
    auto queryMax = [&](int l, int r) {
        int k = std::__lg(r - l);
        return std::max(mx[l][k], mx[r - (1 << k)][k]);
    };
    auto queryMin = [&](int l, int r) {
        int k = std::__lg(r - l);
        return std::min(mn[l][k], mn[r - (1 << k)][k]);
    };
    
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        if (s[l] != s[r] || queryMin(l, r) < s[l]) {
            std::cout << "-1\n";
        } else {
            std::cout << queryMax(l, r) - s[l] << "\n";
        }
    }
    
    return 0;
}