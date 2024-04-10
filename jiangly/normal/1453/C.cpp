#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int ans[10] {};
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        auto work = [&]() {
            int u[10];
            std::fill(u, u + 10, -1);
            for (int i = 0; i < n; ++i) {
                int f[10];
                std::fill(f, f + 10, -1);
                for (int j = 0; j < n; ++j) {
                    int x = s[i][j] - '0';
                    if (f[x] == -1) {
                        f[x] = j;
                    } else {
                        ans[x] = std::max(ans[x], (j - f[x]) * std::max(i, n - 1 - i));
                    }
                    if (u[x] == -1) {
                        u[x] = i;
                    } else {
                        ans[x] = std::max(ans[x], (i - u[x]) * std::max(j, n - 1 - j));
                    }
                }
            }
        };
        work();
        std::reverse(s.begin(), s.end());
        work();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(s[i][j], s[j][i]);
            }
        }
        work();
        std::reverse(s.begin(), s.end());
        work();
        for (int i = 0; i <= 9; ++i) {
            std::cout << ans[i] << " \n"[i == 9];
        }
    }
    
    return 0;
}