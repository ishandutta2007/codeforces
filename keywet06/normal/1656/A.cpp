#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int x, Max = 0, MaI, Min = 1e9 + 1, MiI;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x;
            if (x > Max) Max = x, MaI = i;
            if (x < Min) Min = x, MiI = i;
        }
        std::cout << MaI << ' ' << MiI << '\n';
    }
    return 0;
}