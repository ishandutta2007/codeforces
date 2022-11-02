#include <bits/stdc++.h>

using int64 = long long;

const int P = int(1e9) + 7;
const int I2 = P + 1 >> 1;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? (x -= P) : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? (x += P) : x; }
inline int &Muls(int &x, int y) { return x = int64(x) * y % P; }

const int N = 2005;

int f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    for (int i = 1; i < N; ++i) {
        f[i][i] = i;
        for (int j = 1; j < i; ++j) {
            f[i][j] = Mul(Add(f[i - 1][j - 1], f[i - 1][j]), I2);
        }
    }
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::cout << Mul(f[n][m], k) << std::endl;
    }
    return 0;
}