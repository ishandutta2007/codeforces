#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 105;

int mod;
int n, dep, K;
int f[mxn][mxn][mxn];
int comb[mxn][mxn];

int F(int d, int i, int k) {
    if (2 * k - 1 > i) return 0;
    if (d > dep && k > 0) return 0;
    if (i == 0) return 1;
    if (~f[d][i][k]) return f[d][i][k];
    int &ans = f[d][i][k] = 0;
    i -= 1;
    if (d == dep) k -= 1;
    for (int ni = 0; ni <= i; ++ ni) {
        for (int nk = 0; nk <= k; ++ nk) {
            ans = (ans + 1LL * comb[i][ni] * F(d + 1, ni, nk) % mod * F(d + 1, i - ni, k - nk)) % mod;
        }
    }
    return ans;
}

int main() {
    scanf("%d %d %d %d", &n, &dep, &K, &mod);
    if (n - (dep - 1) < K) {
        printf("%d\n", 0);
        return 0;
    }
    if (2 * K - 1 > n) {
        printf("%d\n", 0);
        return 0;
    }
    memset(f, -1, sizeof(f));
    rep(i, mxn) rep(j, i + 1) comb[i][j] = j ? (comb[i - 1][j - 1] + comb[i - 1][j]) % mod : 1;
    printf("%d\n", F(1, n, K));
	return 0;
}