#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll aa = a, bb = b, nn = n;
        aa = max(x, aa - nn);
        nn -= a - aa;
        bb = max(y, bb - nn);
        ll ans = aa * bb;
        aa = a, bb = b, nn = n;
        bb = max(y, bb - nn);
        nn -= b - bb;
        aa = max(x, aa - nn);
        ans = min(ans, aa * bb);
        cout << ans << endl;
    }
}