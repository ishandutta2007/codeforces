#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const lint MOD = 998244353;

int n, m;
int A[50050][21];
lint Dp[21], C[21][21], F[21], IF[21];
lint inv(lint a, lint x) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < 21; i++) C[i][0] = 1;
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[j][i];
        }
    }
    lint ans = 0;
    F[0] = 1;
    for (int i = 1; i <= n; i++) F[i] = F[i - 1] * i % MOD;
    for (int i = 1; i <= m; i++) {
        sort(&A[i][1], &A[i][1] + n);
        memset(Dp, 0, sizeof Dp);
        Dp[0] = 1;

        for (int j = 1; j <= n; j++) {
            int p = j;
            for (int k = A[i][j] - 1; k >= j; k--) {
                while (p > 1 && A[i][p - 1] > k) --p;
                Dp[j] += F[j - p] * C[k - p][j - p] % MOD * (j - p + 1) % MOD * Dp[p - 1] % MOD;
            }
            Dp[j] %= MOD;
        }
        ans += (F[n] + MOD - Dp[n]) % MOD;
    }

    cout << (ans % MOD * inv(F[n], MOD - 2) % MOD) << '\n';
}