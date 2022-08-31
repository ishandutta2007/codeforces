#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int h1 = (n + 5) / 3;
    int h2 = std::min(h1 - 1, n - h1 - 1);
    int h3 = n - h1 - h2;
    
    std::cout << h2 << " " << h1 << " " << h3 << "\n";
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