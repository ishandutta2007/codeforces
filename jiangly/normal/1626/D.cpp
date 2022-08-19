#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    int k = std::__lg(n) + 1;
    
    std::vector<int> f(k + 1), g(k + 1);
    for (int i = 0, j = 0; i <= k; i++) {
        while (j < n && ((1 << i) >= n || a[j] < a[1 << i])) {
            j++;
        }
        f[i] = j;
    }
    std::reverse(a.begin(), a.end());
    for (int i = 0, j = 0; i <= k; i++) {
        while (j < n && ((1 << i) >= n || a[j] > a[1 << i])) {
            j++;
        }
        g[i] = j;
    }
    
    int ans = 1E9;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int v = std::max(0, n - f[i] - g[j]);
            int x = 1;
            while (x < v) {
                x *= 2;
            }
            ans = std::min(ans, (1 << i) + (1 << j) + x);
        }
    }
    std::cout << ans - n << "\n";
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