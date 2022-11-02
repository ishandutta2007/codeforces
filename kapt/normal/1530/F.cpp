#include <bits/stdc++.h>
using namespace std;

const int MAXN = 23, MOD = 31607;
int a[MAXN][MAXN];

int inv(int x) {
    int res = 1;
    int n = MOD - 2;
    while (n) {
        if (n % 2 == 0) {
            x *= x;
            x %= MOD;
            n /= 2;
        } else {
            res *= x;
            res %= MOD;
            n--;
        }
    }
    return res;
}

int mlt[1 << MAXN], sz[1 << MAXN];
int16_t hor[1 << MAXN][MAXN - 2];

int id[1 << MAXN];

array<int, 4> ln[MAXN];

int rinv[MOD];

main() {
    for (int i = 1; i < MOD; ++i) {
        rinv[i] = inv(i);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j] *= inv(10000);
            a[i][j] %= MOD;
        }
    }
    for (int i = 0; i <= n; ++i) {
        a[i][n] = a[n][i] = 1;
    }
    for (int i = 0; i < n + 2; ++i) {
        id[1 << i] = i;
    }
    for (int i = 0; i < n; ++i) {
        ln[i] = {0, i, 1, 0};
    }
    ln[n] = {0, 0, 1, 1};
    ln[n + 1] = {0, n - 1, 1, -1};
    int ans = 1;
    for (int m = 0; m < (1 << (n + 2)); ++m) {
        if (m == 0) {
            mlt[m] = 1;
            sz[m] = 0;
            for (int i = 0; i < n; ++i) {
                hor[m][i] = 1;
                for (int j = 0; j < n; ++j) {
                    hor[m][i] = (a[i][j] * (int)hor[m][i]) % MOD;
                }
            }
        } else {
            int m1 = (m & (m - 1));
            sz[m] = sz[m1] + 1;
            mlt[m] = mlt[m1];
            int ind = id[(m & (m ^ (m - 1)))];
            for (int i = 0; i <= n; ++i) {
                hor[m][i] = hor[m1][i];
            }
            for (int x = ln[ind][0], y = ln[ind][1]; x < n && y < n; x += ln[ind][2], y += ln[ind][3]) {
                if (m1 & (1 << y)) continue;
                if (x == y && (m1 & (1 << n))) continue;
                if (x + y == n - 1 && (m1 & (1 << (n + 1)))) continue;
                mlt[m] *= a[x][y];
                mlt[m] %= MOD;
                hor[m][x] = (rinv[a[x][y]] * hor[m][x]) % MOD;
            }
        }
        vector<int> dp(n + 1);
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            int k;
            if (i == n) {
                k = 1;
            } else {
                k = hor[m][i];
            }
            dp[i] = k * (1 - sum);
            dp[i] = (dp[i] % MOD + MOD) % MOD;
            sum = (sum + dp[i]) % MOD;
        }
        dp[n] = (dp[n] * mlt[m]) % MOD;
        if (sz[m] % 2 == 0) {
            ans -= dp[n];
        } else {
            ans += dp[n];
        }
        ans = (ans % MOD + MOD) % MOD;
    }
    cout << ans;
    return 0;
}