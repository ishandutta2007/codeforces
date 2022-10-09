// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, k, p;
int dp[105][105][105];
int fact[105];
int bk[105][105];

int solve(int n, int m, int k) {
    if (n == 0) return k == 0;
    if (m == 1) return k == 1 ? fact[n] : 0;

    if (n < 2*k-1) return 0;

    int z = dp[n][m][k];
    if (z != -1) return z;
    z = 0;

    for (int a=0; a<n; a++) {
        int b = n-1-a;
        int t = 0;
        for (int i=0; i<=k; i++) {
            int j = k-i;
            int q = solve(a, m-1, i) * 1ll * solve(b, m-1, j) % p;
            t += q;
            if (t >= p) t -= p;
        }
        t = t * 1ll * bk[a][b] % p;
        z += t;
        if (z >= p) z -= p;
    }

    return dp[n][m][k] = z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> k >> p;
    memset(dp, 255, sizeof(dp));

    fact[0] = 1;
    bk[0][0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = fact[i-1] * 1ll * i % p;
        bk[0][i] = bk[i][0] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int z = bk[i-1][j] + bk[i][j-1];
            if (z >= p) z-= p;
            bk[i][j] = z;
        }
    }

    cout << solve(n, m, k) << '\n';
}