#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    n--;
    
    int a = 2;
    while (std::gcd(n, a) > 1) {
        a++;
    }
    
    std::cout << a << " " << n - a << " 1\n";
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