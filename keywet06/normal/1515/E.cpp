#include <bits/stdc++.h>

using int64 = long long;

const int N = 405;

int n;

int64 P;
int64 fact[N], inv[N], pow2[N];
int64 dp[N][N], choose[N][N];

int64 fastexp(int64 b, int64 exp) {
    if (exp == 0) return 1;
    int64 temp = fastexp(b, exp / 2);
    temp = (temp * temp) % P;
    if (exp % 2 == 1) temp *= b;
    return temp % P;
}

void precompute() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % P;
        inv[i] = fastexp(fact[i], P - 2);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            choose[i][j] = ((fact[i] * inv[j]) % P * inv[i - j]) % P;
        }
    }
    for (int i = 0; i <= n; i++) pow2[i] = fastexp(2, i);
}

int main() {
    std::cin >> n >> P;
    precompute();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 1; i + k <= n; k++) {
                dp[i + k + 1][j + k] +=
                    ((dp[i][j] * pow2[k - 1]) % P * choose[j + k][k]);
                dp[i + k + 1][j + k] %= P;
            }
        }
    }
    int64 ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[n + 1][i]) % P;
    std::cout << ans << std::endl;
    return 0;
}