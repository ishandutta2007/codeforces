#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; ; ++i) {
            int l = -i, r = -i + i * (i + 3) / 2;
            if (l <= n && n <= r && n != l + 1 && n != r - 1) {
                std::cout << i << "\n";
                break;
            }
        }
    }
    
    return 0;
}