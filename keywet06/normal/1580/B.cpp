#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, K, P;
int Bi[N][N], f[N][N][N], fac[N];

inline int solve(int n, int m, int K) {
    if (K > n) return 0;
    if (m < 0 || m > n) return !K ? fac[n] : 0;
    if (!n) return !K;
    if (~f[n][m][K]) return f[n][m][K];
    int ans = 0;
    for (int i = 1; i + i <= n + 1; ++i) {
        int t = m == 1;
        for (int j = 0; j <= K - t; ++j) {
            ans = (ans + 1LL * (1 + (i + i <= n)) * Bi[n - 1][i - 1] *
                solve(i - 1, m - 1, j) % P * solve(n - i, m - 1, K - t - j)) % P;
        }
    }
    return f[n][m][K] = ans;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &P);
    for (int i = 0; i <= n; ++i) {
        for (int j = Bi[i][0] = 1; j <= i; ++j) {
            Bi[i][j] = (Bi[i - 1][j - 1] + Bi[i - 1][j]) % P;
        }
    }
    for (int i = fac[0] = 1; i <= n; ++i) {
        fac[i] = 1LL * i * fac[i - 1] % P;
    }
    memset(f, -1, sizeof(f));
    printf("%d\n", solve(n, m, K));
    return 0;
}