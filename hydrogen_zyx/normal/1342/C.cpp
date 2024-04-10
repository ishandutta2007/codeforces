#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, q;
        cin >> a >> b >> q;
        ll ta = 0, tb = 0;
        ll k = 0;
        ta = max(a, b);
        tb = a * b / gcd(a, b) - ta;
        for (int i = 1; i <= q; i++) {
            ll l, r;
            cin >> l >> r;
            r++;
            if (a == b) {
                cout << 0 << ' ';
                continue;
            }
            ll ansl, ansr;
            ansl = l / (ta + tb) * tb + (max(0LL, l % (ta + tb) - ta));
            ansr = r / (ta + tb) * tb + (max(0LL, r % (ta + tb) - ta));
            cout << ansr - ansl << ' ';
        }
        cout << endl;
    }
}