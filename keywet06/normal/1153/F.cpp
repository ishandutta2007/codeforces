// ihdignite

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 2e3;
const int M = N + 1 << 1;
const int P = 998244353;

int n, k, l;

int64 Inv[M], Fac[M], IFac[M], Pow2[M], Dp[N + 1];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> k >> l;
    Inv[1] = 1;
    for (int i = 2; i < M; ++i) Inv[i] = P - P / i * Inv[P % i] % P;
    Fac[0] = IFac[0] = Pow2[0] = 1;
    for (int i = 1; i < M; ++i) {
        Fac[i] = Fac[i - 1] * i % P;
        IFac[i] = IFac[i - 1] * Inv[i] % P;
        Pow2[i] = Pow2[i - 1] * 2 % P;
    }
    for (int i = n; i >= k; --i) {
        Dp[i] = Fac[i] * Fac[i] % P * Pow2[i] % P * IFac[2 * i + 1] % P;
        Dp[i] = Dp[i] * Fac[n] % P * IFac[i] % P * IFac[n - i] % P;
        for (int j = i + 1; j <= n; ++j) {
            Dp[i] = (Dp[i] -
                     Fac[j] * IFac[i] % P * IFac[j - i] % P * Dp[j] % P + P) %
                    P;
        }
    }
    int64 ans = 0;
    for (int i = k; i <= n; ++i) ans = (ans + Dp[i]) % P;
    std::cout << ans * l % P << std::endl;
    return 0;
}