#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[400000][15];
ll a[400000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) dp[0][i] = -0x3f3f3f3f3f3f3f3f;
    dp[0][0] = 0;
    ll mmax = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 1 && m != 1)
                dp[i][j] = dp[i - 1][(j - 1 + m) % m] + a[i];
            else
                dp[i][j] = max(a[i] - k, dp[i - 1][0] + a[i] - k);
            mmax = max(mmax, dp[i][j]);
        }
    }
    cout << mmax;
}