#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    ll ma = -1, mi = 1e9 + 7;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ma = max(ma, x);
        mi = min(mi, x);
        if(ma - mi > 2 * k) {
            ma = mi = x;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}