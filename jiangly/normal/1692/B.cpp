#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.insert(x);
    }
    
    int m = a.size();
    
    if ((n - m) % 2 != 0) {
        m--;
    }
    
    std::cout << m << "\n";
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