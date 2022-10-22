#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[1005];
int nex[1005][1005][8];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i], -- a[i];
    rep(i, n + 1) rep(j, 8) nex[i][0][j] = i;
    rep(i, 8) nex[n][1][i] = n;
    for (int i = n - 1; ~i; -- i) {
        rep(j, 8) nex[i][1][j] = nex[i + 1][1][j];
        nex[i][1][a[i]] = i;
    }
    rep(j, n + 1) if (j > 1) rep(i, n) rep(k, 8) {
        nex[i][j][k] = nex[i][1][k] < n - 1 ? nex[nex[i][1][k] + 1][j - 1][k] : n;
    }
    int ans = 0;
    rep(c, n / 8 + 1) {
        rep(inc, 1 << 8) {
            static int dp[1 << 8];
            memset(dp, 0x3f, sizeof(dp));
            dp[0] = 0;
            for (int msk = 1; msk < (1 << 8); ++ msk) {
                rep(x, 8) if (msk >> x & 1) if (dp[msk ^ 1 << x] < n) {
                    dp[msk] = min(dp[msk], nex[dp[msk ^ 1 << x]][c + (inc >> x & 1)][x]);
                }
            }
            if (dp[(1 << 8) - 1] < n) {
                int cur = 0;
                rep(i, 8) cur += c + (inc >> i & 1);
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
    return 0;
}