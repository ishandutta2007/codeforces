#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 52;
const int P = int64(1e9) + 7;

int n, tvn2[N];
int C[N][N];
int dp[N][N][N][N];
int ans;
bool p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    tvn2[0] = 1;
    for (int i = 1; i < N; ++i) tvn2[i] = tvn2[i - 1] * 2 % P;
    for (int i = 0; i < N; ++i) C[i][i] = C[i][0] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int w0 = 0; w0 < i; ++w0) {
            for (int w1 = 0; w1 < i - w0; ++w1) {
                for (int b0 = 0; b0 < i - w0 - w1; ++b0) {
                    int b1 = i - 1 - w0 - w1 - b0;
                    if (x == 0 || x == -1) {
                        for (int j = 0; j <= w1; ++j) {
                            dp[i][w0][w1][b0 + (j % 2 == 1)] +=
                                1LL * C[w1][j] * tvn2[i - 1 - w1] % P *
                                dp[i - 1][w0][w1][b0] % P,
                                dp[i][w0][w1][b0 + (j % 2 == 1)] %= P;
                        }
                    }
                    if (x == 1 || x == -1) {
                        for (int j = 0; j <= b1; ++j) {
                            dp[i][w0 + (j % 2 == 1)][w1 + (j % 2 == 0)][b0] +=
                                1LL * C[b1][j] * tvn2[i - 1 - b1] % P *
                                dp[i - 1][w0][w1][b0] % P,
                                dp[i][w0 + (j % 2 == 1)][w1 + (j % 2 == 0)]
                                  [b0] %= P;
                        }
                    }
                }
            }
        }
    }
    for (int w0 = 0; w0 <= n; ++w0) {
        for (int w1 = 0; w1 <= n - w0; ++w1) {
            for (int b0 = 0; b0 <= n - w0 - w1; ++b0) {
                int b1 = n - w0 - w1 - b0;
                if ((w1 + b1) % 2 == p) ans += dp[n][w0][w1][b0], ans %= P;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}