#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;

int a[N], t[N], pr[N];

void solve() {
    int i, j, k, n, l, r, z, l1, l2, r1, r2;
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    int sl = min(l1, l2);
    int sr = max(r1, r2);
    bool intes = 0;
    int com = 0;
    int dist = 0;
    if (l1 <= r2 && l2 <= r1) {
        intes = 1;
        com = min(r1, r2) - max(l1, l2);
        dist = 0;
    } else {
        dist = max(l1, l2) - min(r1, r2);
    }
    int ans = 40000000000ll;
    for (int i = 1; i <= n; ++i) {
        int sum = dist * i;
        if (com == 0) {
            if ((sr - sl) * i >= k) {
                sum += k;
            } else
                sum += (sr - sl) * i + 2 * (k - (sr - sl) * i);
        } else {
            int k1 = k - com * i;
            if (k1 <= 0)
                ans = 0;
            else {
                int rf = (sr - sl - com) * i;
                if (rf >= k1)
                    sum += k1;
                else
                    sum += rf + 2 * (k1 - rf);
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";

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