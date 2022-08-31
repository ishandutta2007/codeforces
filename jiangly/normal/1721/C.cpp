#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    for (int i = 0, j = 0; i < n; i++) {
        while (b[j] < a[i]) {
            j++;
        }
        std::cout << b[j] - a[i] << " \n"[i == n - 1];
    }
    
    for (int i = 0, j = 0; i < n; i++) {
        j = std::max(j, i);
        while (j + 1 < n && a[j + 1] <= b[j]) {
            j++;
        }
        std::cout << b[j] - a[i] << " \n"[i == n - 1];
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