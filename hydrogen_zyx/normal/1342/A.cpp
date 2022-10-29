#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, x, y;
        cin >> x >> y;
        cin >> a >> b;
        ll ans = (abs(x) + abs(y)) * a;
        if (x * y > 0) {
            ans = min(ans, min(abs(x), abs(y)) * b + abs(x - y) * a);
        }
        cout << ans << endl;
    }
}