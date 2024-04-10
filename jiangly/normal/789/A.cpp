#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ans += (x + k - 1) / k;
    }
    std::cout << (ans + 1) / 2 << "\n";
    
    return 0;
}