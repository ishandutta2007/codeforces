#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const i64 inf = 1LL << 60;

i64 add(i64 a, i64 b) {
    return a + b < inf ? a + b : inf;
}

const int mxn = 105;
const int sigma = 26;

int n;
i64 K;

char s[mxn];
int go[mxn][sigma];

i64 dp[mxn][mxn];

int main() {
    scanf("%d %lld", &n, &K);
    scanf("%s", s + 1);
    rep(c, sigma) go[n + 1][c] = n + 1;
    for (int i = n; i; -- i) {
        memcpy(go[i], go[i + 1], sizeof(go[i]));
        go[i][s[i] - 'a'] = i;
    }
    memset(dp, 0, sizeof(dp));
    dp[n + 1][0] = 1;
    for (int i = n; i; -- i) {
        dp[i][0] = 1;
        for (int s = 1; s <= n; ++ s) {
            rep(c, sigma) {
                if (go[i][c] <= n) {
                    dp[i][s] = add(dp[i][s], dp[go[i][c] + 1][s - 1]);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = n; ~i; -- i) {
        i64 s = std::min(K, dp[1][i]);
        ans += s * (n - i);
        K -= s;
    }
    if (K > 0) printf("-1\n");
    else printf("%lld\n", ans);
	return 0;
}