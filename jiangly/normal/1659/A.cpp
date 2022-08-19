#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, r, b;
    std::cin >> n >> r >> b;
    
    int v = r;
    for (int i = 0; i <= b; i++) {
        for (int j = 0; j < v / (b + 1 - i); j++) {
            std::cout << "R";
        }
        v -= v / (b + 1 - i);
        if (i < b) {
            std::cout << "B";
        }
    }
    std::cout << "\n";
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