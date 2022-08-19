#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a.push_back(std::max(i, n - i - 1) + std::max(j, m - j - 1));
        }
    }
    
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n * m; i++) {
        std::cout << a[i] << " \n"[i == n * m - 1];
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