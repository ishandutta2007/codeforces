#include <bits/stdc++.h>

void solve() {
    std::vector<int> b(7);
    for (int i = 0; i < 7; i++) {
        std::cin >> b[i];
    }
    
    std::cout << b[0] << " " << b[1] << " " << b[5] - b[1] << "\n";
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