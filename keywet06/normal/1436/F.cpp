#include <bits/stdc++.h>

const int P = 998244353;
const int N = 100005;

int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = int64_t(a) * a % P)
        if (b & 1) res = int64_t(res) * a % P;
    return res;
}

const int I2 = power(2, P - 2);
const int I4 = power(4, P - 2);
const int I8 = power(8, P - 2);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int mu[N + 1] = {};
    mu[1] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 2 * i; j <= N; j += i) mu[j] -= mu[i];
    int f[N + 1][8] = {};
    for (int i = 1; i <= N; ++i) f[i][0] = 1;
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        int p = power(2, b);
        f[a][0] = p;
        f[a][1] = f[a][2] = int64_t(a) * b % P * p % P * I2 % P;
        f[a][3] = (int64_t(b) * I2 + int64_t(b) * (b - 1) % P * I4) % P * a %
                  P * a % P * p % P;
        f[a][4] = int64_t(b) * p % P * I2 % P;
        f[a][5] = f[a][6] = (int64_t(b) * I2 + int64_t(b) * (b - 1) % P * I4) %
                            P * a % P * p % P;
        f[a][7] = (int64_t(b) * I2 + 3ll * b % P * (b - 1) % P * I4 +
                   int64_t(b) * (b - 1) % P * (b - 2) % P * I8) %
                  P * a % P * a % P * p % P;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 2 * i; j <= N; j += i) {
            for (int s = 7; s >= 0; --s) {
                int res = 0;
                for (int t = s;; t = (t - 1) & s) {
                    res = (res + int64_t(f[i][t]) * f[j][t ^ s]) % P;
                    if (t == 0) break;
                }
                f[i][s] = res;
            }
        }
        ans = (ans + mu[i] * (f[i][7] - f[i][3])) % P;
    }
    ans = (ans + P) % P;
    std::cout << ans << "\n";

    return 0;
}