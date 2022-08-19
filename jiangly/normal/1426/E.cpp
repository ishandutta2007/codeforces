#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;
    int b1, b2, b3;
    std::cin >> b1 >> b2 >> b3;
    
    int ans1 = std::max({0, a1 - b1 - b3, a2 - b2 - b1, a3 - b3 - b2});
    int ans2 = std::min(a1, b2) + std::min(a2, b3) + std::min(a3, b1);
    std::cout << ans1 << " " << ans2 << "\n";
    
    return 0;
}