#include <bits/stdc++.h>

const int C = 105;

inline int Sqr(int x) { return x * x; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        int Ans = 0;
        for (int i = 0; i < n; ++i) std::cin >> a[i], Ans += (n - 2) * Sqr(a[i]);
        for (int i = 0; i < n; ++i) std::cin >> b[i], Ans += (n - 2) * Sqr(b[i]);
        int m = n * C * 2;
        std::vector<std::vector<int> > f(n + 1);
        f[0].resize(1), f[0][0] = 1;
        int Sum = 0;
        for (int i = 0, I = 1; i < n; ++i, ++I) {
            int Num = Sum;
            Sum += a[i] + b[i];
            f[I].resize(Sum + 1);
            for (int j = 0; j <= Num; ++j) f[I][j + a[i]] |= f[i][j], f[I][j + b[i]] |= f[i][j];
        }
        int Min = INT_MAX;
        for (int i = 0; i <= Sum; ++i) {
            if (f[n][i]) Min = std::min(Min, Sqr(i) + Sqr(Sum - i));
        }
        std::cout << (Ans += Min) << std::endl;
    }
    return 0;
}