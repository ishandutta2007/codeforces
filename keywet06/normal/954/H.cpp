#include <bits/stdc++.h>
const int N = 5e3 + 10;
const int P = 1e9 + 7;

int n;
int ar[N * 2];
int dp[N][N * 2];

int main() {
    std::cin >> n;
    for (int a = 0; a < n - 1; ++a) std::cin >> ar[a];
    for (int a = 0; a < n; ++a) {
        dp[a][0] = 0, dp[a][1] = 0;
        if (a != 0) dp[a][1] = 1;
        int q = 1;
        for (int b = 2; b <= 2 * n; ++b) {
            if (a != 0) {
                dp[a][b] = dp[a - 1][b - 1] - q;
                if (dp[a][b] < 0) dp[a][b] += P;
            }
            dp[a][b - 2] = (dp[a][b - 2] + q) % P;
            if (a + b - 2 < n - 1) {
                q = (1ll * q * ar[a + b - 2]) % P;
            } else {
                q = 0;
            }
        }
    }
    for (int a = 1; a <= 2 * n - 2; ++a) {
        int q = 1, Ans = 0;
        for (int b = 0; b < n; ++b) {
            Ans = (Ans + 1ll * q * dp[b][a]) % P;
            if (b != n - 1) q = (1ll * q * ar[b]) % P;
        }
        if (Ans % 2) Ans += P;
        std::cout << Ans / 2 << " ";
    }
    std::cout << std::endl;
    return 0;
}