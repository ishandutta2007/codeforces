#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define all(a) a.begin(), a.end()

void solve() {
    int a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    if (a <= b) {
        cout << b << endl;
        return;
    }
    ans = b;
    a -= b;
    int res = c - d;
    if (res <= 0) cout << -1 << endl;
    else {
        int k = a / res;
        if (a % res == 0) cout << ans + k * c + a % res << endl;
        else cout << ans + k * c + c << endl;
    }
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