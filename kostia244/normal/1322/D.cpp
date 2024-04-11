#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int N = 5050;
int n, m, nxt[N][N], dp[N][N], val[N][N], l[N], s[N], c[N+N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> l[n-1-i];
    for(int i = 0; i < n; i++) cin >> s[n-1-i];
    for(int i = 1; i <= n+m; i++) cin >> c[i];
    for(int i = 0; i < n; i++) s[i] -= c[l[i]];
    for(int i = 0; i <= n+m; i++) {
        for(int msk = 0; msk <= n; msk++) {
            int nw = msk^(msk+1);
            for(int x = 1; (nw>>x)&1; x++)
                val[i][msk] += c[i+x];
        }
    }
    for(int i = 0; i <= m; i++) nxt[n][i] = n;
    for(int i = n; i--;) {
        for(int j = 0; j <= m; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][l[i]] = i;
    }
    memset(dp, -0x3f, sizeof dp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i][0] = max(dp[i][0], 0);
        for(int j = n; j--;)
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]-s[i]+val[l[i]][j]);
        for(int j = 0; j <= n; j++) {
            for(int tm = j, k = l[i]; k < min(m+1, l[i]+14); k++, tm /= 2) {
                if(nxt[i+1][k] != n) {
                    dp[nxt[i+1][k]][tm] = max(dp[nxt[i+1][k]][tm], dp[i][j]);
                }
            }
        }
        int v = *max_element(dp[i], dp[i]+n+1);
        ans = max(ans, v);
        for(int j = i+1; j < n; j++) if(l[j] >= l[i]+14)
            dp[j][0] = max(dp[j][0], v);
    }
    cout << ans << '\n';
}