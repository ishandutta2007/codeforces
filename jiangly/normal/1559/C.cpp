#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int a[n + 2];
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 1;
    
    int x = 0;
    
    while (a[x] != 0 || a[x + 1] != 1) {
        x++;
    }
    
    std::vector<int> res;
    for (int i = 1; i <= x; i++) {
        res.push_back(i);
    }
    res.push_back(n + 1);
    for (int i = x + 1; i <= n; i++) {
        res.push_back(i);
    }
    
    for (int i = 0; i <= n; i++) {
        std::cout << res[i] << " \n"[i == n];
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