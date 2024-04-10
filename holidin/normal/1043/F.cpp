#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
const int N = 3e5 + 1;
long long us[N], dp[N], cnt[N];
long long c[10][N];

int main() {
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> j;
        ++us[j];
    }
    for (i = 1; i < N; ++i)
        for (j = 1; i * j < N; ++j)
            cnt[i] += us[i * j];
    for (i = 0; i < N; ++i)
        c[0][i] = 1;
    for (i = 1; i < 10; ++i)
        c[i][0] = 0;
    for (i = 1; i < 10; ++i)
    for (j = 1; j < N; ++j)
        c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
    for (i = 1; i < 10; ++i) {
        for (j = N - 1; j > 0; --j) {
            dp[j] = c[i][cnt[j]];
            for (l = 2; l * j < N; ++l)
                dp[j] -= dp[l * j];
        }
        if ((dp[1] + mod * mod) % mod != 0) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}