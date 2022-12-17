#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define double long double
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;
int a[N];

void solve() {
    int i, j, k, n, m, q;
    cin >> n >> m >> k;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    int ans1 = 0, ans2 = 0;
    --m;
    for (i = 0; i <= min(m, k); ++i) {
        ans2 = 2e9 + 9;
        for (j = i; j <= m - (min(m, k) - i); ++j) {
            ans2 = min(ans2, max(a[j], a[n - (m - j) - 1]));
        }
        ans1 = max(ans1, ans2);
    }

    cout << ans1 << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        solve();
}