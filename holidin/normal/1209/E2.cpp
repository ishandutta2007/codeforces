#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 16e3 + 1000;

int t[N], dp[N], dp1[N], dp2[N], a[N];
int m[2001][2001];
int mf[N];

void solve() {
    int i, j, k, n, l, p;
    cin >> n >> k;
    t[0] = 1;
    for (i = 1; i <= n; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 0; i < t[n]; ++i)
        dp[i] = 0;
    for (i = 0; i < n; ++i)
    for (j = 1; j <= k; ++j)
        cin >> m[i][j];
    for (j = 1; j <= k; ++j) {
        mf[j] = 0;
        for (i = 0; i < n; ++i)
            mf[j] = max(mf[j], m[i][j]);
    }
    for (i = n + 1; i <= k; ++i)
    for (j = 1; j <= n; ++j)
    if (mf[i] > mf[j]) {
        swap(mf[i], mf[j]);
        for (l = 0; l < n; ++l)
            swap(m[l][i], m[l][j]);
    }
    for (i = 1; i <= min(n, k); ++i) {
        for (j = 0; j < n; ++j) {
            a[j] = m[j][i];
        }
        for (j = 0; j < t[n]; ++j)
            dp2[j] = 0;
        for (p = 0; p < n; ++p) {
            for (j = 0; j < t[n]; ++j)
                dp1[j] = dp[j];
            for (int it = 0; it < n; ++it)
                for (int h = 0; h < t[n]; ++h)
                    if ((h & t[it]) == 0) {
                        dp1[h + t[it]] = max(dp1[h + t[it]], dp1[h] + a[it]);
                    }
            int x = a[0];
            for (int l = 1; l < n; ++l)
                a[l - 1] = a[l];
            for (j = 0; j < t[n]; ++j)
                dp2[j] = max(dp2[j], dp1[j]);
            a[n - 1] = x;
        }
        for (j = 0; j < t[n]; ++j)
            dp[j] = dp2[j];
    }
    cout << dp[t[n] - 1] << "\n";
}

int main() {
    int i, j, k, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    for (i = 0; i < test; ++i)
        solve();
}