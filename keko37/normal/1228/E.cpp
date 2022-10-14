#include<bits/stdc++.h>

using namespace std;

const int MAXN = 255;
const int MOD = 1000000007;

int n, k;
int nck[MAXN][MAXN], pot[2][MAXN * MAXN];

int add (int x, int y) {
    x += y;
    if (x >= MOD) return x - MOD; return x;
}

int sub (int x, int y) {
    x -= y;
    if (x < 0) return x + MOD; return x;
}

void precompute () {
    for (int i=1; i<=n; i++) {
        nck[i][0] = nck[i][i] = 1;
        for (int j=1; j<i; j++) {
            nck[i][j] = add(nck[i - 1][j], nck[i - 1][j - 1]);
        }
    }
    pot[0][0] = pot[1][0] = 1;
    for (int i=1; i<=n*n; i++) {
        pot[0][i] = 1LL * k * pot[0][i - 1] % MOD;
        pot[1][i] = 1LL * (k - 1) * pot[1][i - 1] % MOD;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    precompute();
    int sol = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            long long val = 1LL * nck[n][i] * nck[n][j] % MOD;
            val = val * pot[1][n * (i + j) - i * j] % MOD;
            val = val * pot[0][n * n - n * (i + j) + i * j] % MOD;
            if ((i + j) % 2 == 1) val = (MOD - val) % MOD;
            sol = add(sol, val);
        }
    }
    cout << sol;
    return 0;
}