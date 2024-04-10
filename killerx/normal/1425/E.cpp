#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
int n, k, a[mxn], d[mxn];
ll sum[mxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> d[i];
    rep(i, n) sum[i + 1] = sum[i] + a[i];
    ll ans = 0;
    if (k >= 2) {
        rep(i, n - 1) ans = max(ans, sum[n] - d[i]);
        ans = max(ans, 0LL + a[n - 1] - d[n - 1]);
    } else if (k == 0) {
        rep(i, n) ans = max(ans, sum[n] - sum[i] - d[i]);
    } else {
        rep(i, n - 1) if (i) ans = max(ans, sum[n] - sum[i] - d[i]);
        rep(i, n - 1) if (i) ans = max(ans, sum[n] - a[i] - d[0]);
        rep(i, n - 1) ans = max(ans, sum[n - 1] - d[i]);
        rep(i, n - 1) ans = max(ans, sum[n - 1] - d[i] + a[n - 1] - d[n - 1]);
        int mn = 0x3f3f3f3f;
        rep(i, n - 1) {
            if (i) ans = max(ans, sum[n] - mn - d[i]);
            mn = min(mn, d[i]);
        }
    }
    cout << ans << endl;
    return 0;
}