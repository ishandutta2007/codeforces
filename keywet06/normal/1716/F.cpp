#include <bits/stdc++.h>

const int P = 998244353;

inline int Add(int x, int y) { return x + y >= P ? x + y - P : x + y; }
inline int Sub(int x, int y) { return x - y >= 0 ? x - y : x - y + P; }

const int K = 2005;

int n, m, k, x, t, Ans;
int f[K][K];

inline int Pow(int x, int y) {
    int Res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % P) {
        if (y & 1) Res = 1ll * Res * x % P;
    }
    return Res;
}

inline int read() {
    char Tmp, ch;
    int x;
    for (Tmp = ch = getchar(); !isdigit(Tmp); Tmp = getchar()) ch = Tmp;
    for (x = 0; isdigit(Tmp); Tmp = getchar()) x = x * 10 + Tmp - '0';
    return ch == '-' ? -x : x;
}

int main() {
    f[0][0] = 1;
    for (int i = 1; i < K; ++i) {
        for (int j = 1; j < K; ++j) f[i][j] = (1ll * f[i - 1][j] * j + f[i - 1][j - 1]) % P;
    }
    for (int T = read(); T; --T) {
        n = read(), m = read(), k = read(), Ans = 0;
        if (m % 2 == 0) {
            x = m / 2, t = 2;
        } else {
            x = m / 2 + 1, t = Add(1ll * (x - 1) * Pow(x, P - 2) % P, 1);
        }
        if (t) {
            int p = Pow(t, n), inv = Pow(t, P - 2);
            for (int i = 0, now = 1; i <= k; ++i) {
                Ans = (Ans + 1ll * f[k][i] * p % P * now % P) % P;
                if (n - i > 0) {
                    now = 1ll * now * (n - i) % P;
                    p = 1ll * p * inv % P;
                } else {
                    break;
                }
            }
            Ans = 1ll * Ans * Pow(x, n) % P;
        }
        std::cout << Ans << '\n';
    }
    return 0;
}