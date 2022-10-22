#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int M = 110;
int n, m, q, p;
int Dp[M][M][M];
int C[M][M], F[M];

int main() {
    cin >> n >> m >> q >> p;
    C[0][0] = 1 % p; F[0] = 1 % p;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1 % p;
        F[i] = 1LL * F[i - 1] * i % p;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
        }
    }
    for (int i = 0; i <= n; i++) {
        Dp[i][0][0] = 1 % p;
    }
    for (int i = 1; i <= n; i++) {
        Dp[0][i][1] = F[i];
        for (int j = max(1, m - 1 - (n - i)); j < m; j++) {
            for (int k = max(0, q - (n - i)); k <= min(n - j, q); k++) {
                for (int l = 0; l < i; l++) {
                    int s = 0;
                    for (int m = 0; m <= k - m; m++) {
                        if (m != k - m) {
                            s = (s + 2LL * Dp[j - 1][l][m] * Dp[j - 1][i - l - 1][k - m] % p);
                            if (s >= p) {
                                s -= p;
                            }
                        }
                        else {
                            s = (s + 1LL * Dp[j - 1][l][m] * Dp[j - 1][i - l - 1][k - m] % p);
                            if (s >= p) {
                                s -= p;
                            }
                        }
                    }
                    Dp[j][i][k] = (Dp[j][i][k] + 1LL * s * C[i - 1][l] % p);
                    if (Dp[j][i][k] >= p) {
                        Dp[j][i][k] -= p;
                    }
                }
            }
        }
    }
    cout << Dp[m - 1][n][q];
}