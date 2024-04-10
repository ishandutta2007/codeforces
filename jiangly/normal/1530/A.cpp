#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        
        auto s = std::to_string(n);
        
        std::cout << (*std::max_element(s.begin(), s.end()) - '0') << "\n";
    }
    
    return 0;
}