#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int a[N], cnt[N];
int m[N], f[N];

vector <vector<vector <int> > > dp;

int main() {
    int i, j, n, k, x, top = 0, l1, l2, p, z;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> z;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        ++m[a[i]];
    }
    int xs = 0;
    for (i = 1; i <= z; ++i)
    if (m[i] > 0) {
        ++top;
        if (m[i] >= 8) {
            if (m[i] % 3 <= 1) {
                cnt[top] = m[i] % 3 + 6;
                xs += m[i] / 3 - 2;
            } else {
                cnt[top] = m[i] % 3 + 3;
                xs += m[i] / 3 - 1;
            }
        } else
            cnt[top] = m[i];
        f[top] = i;
    }
    dp.resize(top + 1);
    for (i = 0; i <= top; ++i) {
        dp[i].resize(cnt[i] + 1);
        for (j = 0; j <= cnt[i]; ++j)
            dp[i][j].resize(cnt[i + 1] + 1);
    }
    dp[0][0][cnt[1]] = xs;
    for (i = 0; i <= top - 2; ++i)
    for (l1 = 0; l1 <= cnt[i]; ++l1)
    for (l2 = 0; l2 <= cnt[i + 1]; ++l2) {
        dp[i + 1][l2][cnt[i + 2]] = max(dp[i][l1][l2] + l1 / 3, dp[i + 1][l2][cnt[i + 2]]);
        if (f[i] == f[i + 1] - 1 && f[i + 1] + 1 == f[i + 2])
        for (p = 0; p <= min(min(l1, l2), cnt[i + 2]); ++p)
            dp[i + 1][l2 - p][cnt[i + 2] - p] = max(dp[i][l1][l2] + p + (l1 - p) / 3, dp[i + 1][l2 - p][cnt[i + 2] - p]);
    }
    int ans = 0;
    for (l1 = 0; l1 <= cnt[i]; ++l1)
    for (l2 = 0; l2 <= cnt[i + 1]; ++l2)
        ans = max(ans, dp[top - 1][l1][l2] + l1 / 3 + l2 / 3);
    cout << ans;
}