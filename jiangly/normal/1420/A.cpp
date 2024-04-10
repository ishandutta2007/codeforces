#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (auto &x : a)
            std::cin >> x;
        if (std::is_sorted(a.begin(), a.end(), std::greater<>()) && std::unique(a.begin(), a.end()) == a.end()) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    
    return 0;
}