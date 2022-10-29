#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
int main() {
    ll t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 0) sum += a[i];
        }
        ll mmax = 0;
        ll sub = 0;
        for (ll i = 0; i + 1 < n; i += 2) {
            sub += (a[i + 1] - a[i]);
            mmax = max(mmax, sub);
            if (sub < 0) sub = 0;
        }
        sub = 0;
        for (ll i = 1; i + 1 < n; i += 2) {
            sub += (a[i] - a[i + 1]);
            mmax = max(mmax, sub);
            if (sub < 0) sub = 0;
        }
        cout << sum + mmax << endl;
    }
}