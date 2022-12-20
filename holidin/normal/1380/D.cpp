#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1;

int a[N], dp[N], b[N];

void solve() {
    int n, x, m, y, i, j, k;
    cin >> m >> n >> x >> k >> y;
    for (int i = 1; i <= max(n, m); ++i) {
        dp[i] = dp[i - 1] + y;
        if (i >= k && dp[i] > dp[i - k] + x)
            dp[i] = dp[i - k] + x;
    }
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    b[0] = b[++m] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[++n] = -1;
    int l = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        int c = b[l - 1];
        int cnt = 0;
        while (l < m && b[l] != a[i]) {
            mx = max(mx, b[l]);
            ++l;
            ++cnt;
        }
        if (l == m && i != n) {
            cout << "-1\n";
            return;
        }
        if (max(c, b[l]) < mx && cnt < k) {
            cout << "-1\n";
            return;
        }
        if (max(c, b[l]) < mx && cnt >= k)
            sum += dp[cnt - k] + x;
        else
            sum += dp[cnt];
        ++l;
    }
    cout << sum << "\n";
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
        solve();
}