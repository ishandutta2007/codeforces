#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x;
    std::cin >> x;
    x--;
    
    int a[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    if (a[x] >= 0 && a[a[x]] >= 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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