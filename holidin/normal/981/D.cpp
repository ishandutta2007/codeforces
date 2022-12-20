#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

long long t[61];

long long a[70], pr[70];

bool dp[100][100];

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    pr[0] = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    t[0] = 1;
    for (i = 1; i <= 60; ++i)
        t[i] = t[i - 1] * 2;
    long long ans = 0;
    for (int ii = 60; ii >= 0; --ii) {
        long long ans1 = ans + t[ii];
        for (i = 0; i <= n; ++i)
        for (j = 0; j <= k; ++j)
            dp[i][j] = false;
        dp[0][0] = true;
        for (i = 0; i < n; ++i)
        for (j = 0; j < k; ++j)
        if (dp[i][j]) {
            for (int i1 = 1; i1 <= n - i; ++i1)
            if (((pr[i + i1] - pr[i]) & ans1) == ans1)
                dp[i + i1][j + 1] = true;
        }
        if (dp[n][k])
            ans = ans1;
    }
    cout << ans;
}