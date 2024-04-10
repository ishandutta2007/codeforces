#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int rating;
    std::cin >> rating;
    
    int div = -1;
    if (rating >= 1900) {
        div = 1;
    } else if (rating >= 1600) {
        div = 2;
    } else if (rating >= 1400) {
        div = 3;
    } else {
        div = 4;
    }
    
    std::cout << "Division " << div << "\n";
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