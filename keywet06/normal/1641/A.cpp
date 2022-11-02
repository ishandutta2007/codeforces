#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::map<int, int> Map;
        for (int x, i = 0; i < n; ++i) std::cin >> x, ++Map[x];
        int Ans = 0;
        for (auto &[x, c] : Map) {
            if (!c || int64(x) * k > INT_MAX || !Map.count(x * k)) continue;
            int &v = Map[x * k], t = std::min(c, v);
            c -= t, v -= t, Ans += t;
        }
        std::cout << n - 2 * Ans << '\n';
    }
    return 0;
}