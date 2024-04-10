#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::string S, T;
        std::cin >> S >> T;
        int c1 = 0, c2 = 0, cc = 0;
        for (int i = 0; i < n; ++i) {
            c1 += S[i] == '1';
            c2 += T[i] == '1';
            cc += S[i] == '1' && T[i] == '1';
        }
        int ans = n << 1 | 1;
        if (c1 == c2) ans = std::min(ans, c1 - cc << 1);
        if (c1 && n - c1 + 1 == c2) ans = std::min(ans, cc - bool(cc) << 1 | 1);
        std::cout << (ans == (n << 1 | 1) ? -1 : ans) << '\n';
    }
    return 0;
}