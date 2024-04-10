#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int j = std::find(a.begin(), a.end(), i + 1) - a.begin();
        b[i] = (j + 1) % (i + 1);
        std::rotate(a.begin(), a.begin() + j + 1, a.begin() + i + 1);
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
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