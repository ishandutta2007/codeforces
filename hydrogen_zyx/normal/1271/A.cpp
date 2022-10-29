#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll x, y;
    x = a;
    y = min(b, c);
    ll ans = 0;

    if (e >= f) {
        ans += e * min(a, d);
        d -= min(a, d);
        ans += min(d, y) * f;
        cout << ans;
        return 0;
    } else {
        ans += f * min(y, d);
        d -= min(y, d);
        ans += min(d, x) * e;
        cout << ans;
        return 0;
    }
}