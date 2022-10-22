#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 14;
const lint MOD = 1e9 + 7;

int n, A[M];
lint Dp[M][1 << M], X[M][1 << M];

lint _pow(lint a, lint x = MOD - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) if (~j >> i & 1) {
            X[i][j] = 1;
            for (int k = 0; k < n; k++) if (j >> k & 1) {
                X[i][j] = X[i][j] * A[i] % MOD * _pow(A[i] + A[k]) % MOD;
            }
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) == 1) {
            int x = __builtin_ctz(i);
            Dp[x][i] = 1; continue;
        }
        for (int j = i; j > 0; j &= (j - 1)) {
            int jb = j & -j;
            int jj = __builtin_ctz(jb);
            int x = (i ^ jb) & -(i ^ jb);
            for (int k = i ^ jb ^ x; k >= 0; k--) {
                k &= i ^ jb ^ x; // k is a subset of i ^ jb ^ x
                int kk = k ^ jb;
                lint s = 1;
                for (int l = i ^ kk; l > 0; l &= (l - 1)) {
                    int lb = l & -l;
                    int xx = __builtin_ctz(lb);
                    if (lb == x) s = s * (1 + MOD - X[xx][kk]) % MOD;
                    else s = s * X[xx][kk] % MOD;
                }
                int xx = __builtin_ctz(x);

                Dp[jj][i] = (Dp[jj][i] + s * Dp[xx][i ^ kk] % MOD * Dp[jj][kk] % MOD) % MOD;
            }
        }
    }
    
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + Dp[i][(1 << n) - 1]) % MOD;
    }
    cout << ans;
}