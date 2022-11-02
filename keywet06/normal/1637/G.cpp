#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        if (n == 2) {
            std::cout << -1 << '\n';
            continue;
        }
        int m = 32 - __builtin_clz(n - 1);
        std::vector<int> Num(m + 1);
        std::vector<std::pair<int, int> > Ans;
        std::function<void(int, int)> Solve = [&](int n, int d) -> void {
            if (n <= 2) {
                if (n >= 1) ++Num[d];
                if (n >= 2) ++Num[d + 1];
                return;
            }
            int k = 31 - __builtin_clz(n);
            for (int i = 1; (1 << k) + i <= n; ++i) Ans.emplace_back((1 << k) - i << d, (1 << k) + i << d);
            Num[d + k + 1] += n - (1 << k);
            ++Num[d + k];
            Solve((1 << k + 1) - n - 1, d);
            Solve(n - (1 << k), d + 1);
        };
        Solve(n, 0);
        for (int i = 0; i <= m; ++i) {
            if (Num[i] > 1) {
                ----Num[i], ++Num[i + 1];
                Ans.emplace_back(1 << i, 1 << i);
                break;
            }
        }
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < Num[i]; ++j) {
                for (int k = i; k < m; ++k) {
                    Ans.emplace_back(0, 1 << k);
                    Ans.emplace_back(1 << k, 1 << k);
                }
            }
        }
        Ans.emplace_back(0, 1 << m);
        std::cout << Ans.size() << '\n';
        for (auto [x, y] : Ans) std::cout << x << ' ' << y << '\n';
    }
    return 0;
}