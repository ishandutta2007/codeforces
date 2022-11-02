// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int Max = 0, Ans = 0;
        for (int i = 1, x; i <= n; ++i) std::cin >> x, Ans += (Max = std::max(Max, x)) == i;
        std::cout << Ans << '\n';
    }
    return 0;
}