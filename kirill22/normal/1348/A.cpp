#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int res = 2;
    n /= 2;
    for (int i = 2; i <= n; i++) {
        res += (1 << (i));
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) solve();
}