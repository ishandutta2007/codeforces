#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    
    i64 z = c;
    i64 y = b;
    i64 x = a + b * c;
    
    std::cout << x << " " << y << " " << z << "\n";
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