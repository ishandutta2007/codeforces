#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    for (int i = 1; i <= n; i++) {
        std::cout << i;
        for (int j = n; j > 0; j--) {
            if (i != j) {
                std::cout << " " << j;
            }
        }
        std::cout << "\n";
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