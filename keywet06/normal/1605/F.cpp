#include <bits/stdc++.h>

const int N = 85;
const int M = N * N;

using int64 = long long;

int n, m, P, Ans;
int Pw[M];
int C[N][N], Tot[N][N], Bad[N][N], F[N][N];

inline int Down(int a, int b) {
    int ret = 1;
    for (int i = a; i >= a - b + 1; --i) ret = (int64)ret * i % P;
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    Pw[0] = C[0][0] = 1;
    for (int i = 1; i < M; ++i) (Pw[i] = Pw[i - 1] << 1) %= P;
    for (int i = 0; i < N; C[i + (i != N - 1)][0] = 1, ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= j; ++k) {
                int Add = (int64)C[j][k] * Pw[i * k] % P;
                (Tot[i][j] += ((j - k) & 1 ? P - Add : Add)) %= P;
                Add = int64(C[j][k]) * Down(Pw[k] - 1, i) % P;
                (F[i][j] += ((j - k) & 1 ? P - Add : Add)) %= P;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int a = 0; a < i; ++a) {
                for (int b = 0; b < j; ++b) {
                    if ((n & 1) && i == n && a == n - 1) continue;
                    (Bad[i][j] +=
                     int64(C[i][a]) * C[j][b] % P * F[i - a][j - b] % P *
                     (Tot[a][b] - Bad[a][b] + P) % P * Pw[(i - a) * b] % P) %=
                        P;
                }
            }
        }
    }
    for (int i = 0; i <= m; ++i) {
        (Ans += (int64)C[m][i] * (Tot[n][i] - Bad[n][i] + P) % P) %= P;
    }
    printf("%d\n", Ans);
    return 0;
}