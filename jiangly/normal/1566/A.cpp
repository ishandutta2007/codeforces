#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, s;
    std::cin >> n >> s;
    std::cout << s / (n / 2 + 1) << "\n";
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