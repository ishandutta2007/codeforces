#include <bits/stdc++.h>
#define fi first
#define second
#define ll long long
using namespace std;
const int N = 1e3 + 1;
const int CS = 1e5 + 1;
const int mod = 998244353;
ll dp[N][N];
ll sum[N], a[N];
vector <ll> v;

int main() {
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    for (j = 1; j <= n; ++j)
        a[j] = v[j - 1];
    long long ans = 0;
    for (i = 1; i <= CS / (k - 1) + 1; ++i) {
        for (j = 1; j <= n; ++j)
        for (l = 1; l <= k; ++l)
            dp[j][l] = 0;
        for (j = 1; j <= k; ++j)
            sum[j] = 0;
        sum[0] = 1;
        int r = 0;
        for (j = 1; j <= n; ++j) {
            while (r < j && a[j] - a[r + 1] >= i) {
                ++r;
                for (l = 1; l <= k; ++l)
                    sum[l] += dp[r][l];
            }
            for (l = 1; l <= k; ++l) {
                sum[l] %= mod;
                dp[j][l] = sum[l - 1];
            }
            ans = (ans + dp[j][k]) % mod;
        }
    }
    cout << ans;
}