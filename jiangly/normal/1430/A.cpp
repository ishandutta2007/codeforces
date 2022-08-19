#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a = -1, b = -1, c = -1;
        for (int i = 0; 5 * i <= n; ++i) {
            for (int j = 0; 5 * i + 7 * j <= n; ++j) {
                if ((n - 5 * i - 7 * j) % 3 == 0) {
                    a = (n - 5 * i - 7 * j) / 3;
                    b = i;
                    c = j;
                    break;
                }
            }
            if (a != -1) break;
        }
        if (a == -1) std::cout << -1 << "\n";
        else std::cout << a << " " << b << " " << c << "\n";
    }
    
    return 0;
}