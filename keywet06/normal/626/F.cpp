#include <bits/stdc++.h>

template <typename Type>
inline auto Vector(size_t n) {
    return std::vector<Type>(n);
}

template <typename Type, typename... Args>
inline auto Vector(size_t n, Args... args) {
    return std::vector<decltype(Vector<Type>(args...))>(n, Vector<Type>(args...));
}

using int64 = long long;

const int P = 1000000007;

inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? x -= P : x; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, K;
    std::cin >> n >> K;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) a[i] = a[i + 1] - a[i];
    int m = n / 2;
    auto f = Vector<int>(n + 1, m + 1, K + 1);
    f[0][0][0] = 1;
    for (int i = 0, I = 1; i < n; ++i, ++I) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= K; ++k) {
                if (!f[i][j][k]) continue;
                int l = k + a[i] * j, x = f[i][j][k];
                if (l > K) continue;
                Adds(f[I][j][l], x);
                if (j < m) Adds(f[I][j + 1][l], x);
                Adds(f[I][j][l], Mul(x, j));
                if (j) Adds(f[I][j - 1][l], Mul(x, j));
            }
        }
    }
    int Ans = 0;
    for (int i = 0; i <= K; ++i) Adds(Ans, f[n][0][i]);
    std::cout << Ans << std::endl;
    return 0;
}