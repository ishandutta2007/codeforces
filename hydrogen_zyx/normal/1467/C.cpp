#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const ll inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll a[5][N];
ll mmin[5], sum[5];
ll n[5];

int main() {
    ios::sync_with_stdio(false);
    memset(mmin, 0x3f, sizeof mmin);
    memset(sum, 0, sizeof sum);
    cin >> n[1] >> n[2] >> n[3];
    for (ll i = 1; i <= 3; i++) {
        for (ll j = 1; j <= n[i]; j++) {
            cin >> a[i][j];
            mmin[i] = min(mmin[i], a[i][j]);
            sum[i] += a[i][j];
        }
    }
    ll ans = -linf;
    ans = max(ans, sum[1] + sum[2] - sum[3]);
    ans = max(ans, sum[1] - sum[2] + sum[3]);
    ans = max(ans, sum[2] + sum[1] - sum[3]);
    ans = max(ans, sum[2] - sum[1] + sum[3]);
    ans = max(ans, sum[3] + sum[1] - sum[2]);
    ans = max(ans, sum[3] - sum[1] + sum[2]);
    ans = max(ans, sum[1] + sum[2] + sum[3] - 2 * mmin[2] - 2 * mmin[3]);
    ans = max(ans, sum[1] + sum[2] + sum[3] - 2 * mmin[1] - 2 * mmin[3]);
    ans = max(ans, sum[1] + sum[2] + sum[3] - 2 * mmin[2] - 2 * mmin[3]);
    cout << ans << endl;
}