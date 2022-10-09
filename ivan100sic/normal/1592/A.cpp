// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;
        sort(begin(a), end(a), greater<ll>());

        ll fc = h / (a[0] + a[1]);
        ll sol = 2 * fc;
        h -= fc * (a[0] + a[1]);
        if (h > 0) {
            h -= a[0];
            sol++;
            if (h > 0) {
                h -= a[1];
                sol++;
            }
        }

        cout << sol << '\n';
    }
}