#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    std::vector<int> a(n, 1);
    
    for (int i = 0; i < n; i++) {
        if (c[i] == n) {
            break;
        }
        c[i] = std::max(c[i], i);
        if (a[c[i]]) {
            a[c[i]] = 0;
            c[c[i]] += c[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
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