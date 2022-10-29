#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        ll w = c / gcd(c, b - 1);
        a = min(a, b);
        ll ans = (a / w) * (a / w - 1) / 2 * (w - a % w) +
                 (a / w + 1) * (a / w) / 2 * (a % w);
        cout << ans << endl;
    }
}