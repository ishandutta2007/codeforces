#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = min(m, n / k);
    m -= ans;
    if (m % (k - 1) == 0) ans -= (m / (k - 1));
    else ans -= (m / (k - 1)) + 1;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}