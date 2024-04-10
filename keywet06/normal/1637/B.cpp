#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<std::vector<int> > c(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            std::vector<int> t(n + 1);
            int Mex = 0;
            for (int j = i; j < n; ++j) {
                if (a[j] < n) ++t[a[j]];
                while (t[Mex]) ++Mex;
                c[i][j] = Mex + 1;
            }
        }
        int Ans = 0;
        for (int i = 0; i < n; ++i) {
            Ans += c[i][i];
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k < j; ++k) c[i][j] = std::max(c[i][j], c[i][k] + c[k + 1][j]);
                Ans += c[i][j];
            }
        }
        std::cout << Ans << std::endl;
    }
    return 0;
}