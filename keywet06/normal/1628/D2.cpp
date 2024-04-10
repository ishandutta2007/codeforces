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

const int N = 1000005;

int Fac[N], Inv[N], IFac[N], PI2[N];

inline int C(int n, int m) { return Mul(Fac[n], Mul(IFac[m], IFac[n - m])); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    Fac[0] = Inv[0] = Inv[1] = IFac[0] = PI2[0] = 1;
    for (int i = 1; i < N; ++i) Fac[i] = Mul(Fac[i - 1], i);
    for (int i = 2; i < N; ++i) Inv[i] = Mul(P - P / i, Inv[P % i]);
    for (int i = 1; i < N; ++i) IFac[i] = Mul(IFac[i - 1], Inv[i]);
    for (int i = 1; i < N; ++i) PI2[i] = Mul(PI2[i - 1], I2);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        int Ans = 0;
        if (n == m) {
            Ans = n;
        } else {
            for (int i = 1; i <= m; ++i) {
                Adds(Ans, Mul(PI2[n - i], Mul(i, C(n - i - 1, m - i))));
            }
        }
        std::cout << Mul(Ans, k) << '\n';
    }
    return 0;
}