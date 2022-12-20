#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;

int a[N], t[N], pr[N];

void solve() {
    int i, j, k, n, l, r, z;
    cin >> n >> k >> z;
    pr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
        if (i != n)
            t[i] = max(t[i - 1], a[i] + a[i + 1]);
    t[n] = t[n - 1];
    int ans = 0;
    for (int i = 0; 2 * i <= k && i <= z; ++i) {
        int sum = pr[k - 2 * i + 1] - pr[1];
        //cout << i << ' ' << sum << ' ' << t[k - 2 * i] << endl;
        sum += t[k - 2 * i + 1] * i;
        ans = max(ans, sum);
    }
    cout << ans + a[1] << "\n";

}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}