#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x[3];
        for (int i = 0; i < 3; ++i)
            std::cin >> x[i];
        std::sort(x, x + 3);
        if (x[1] != x[2]) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << x[0] << " " << x[0] << " " << x[1] << "\n";
        }
    }
    return 0;
}