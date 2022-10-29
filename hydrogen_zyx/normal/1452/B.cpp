#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum = 0;
        ll mmax = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            mmax = max(mmax, a[i]);
        }
        ll k = mmax * (n - 1) - sum;
        if (k > 0) {
            cout << k << endl;
        } else {
            k = -k;
            k %= (n - 1);
            cout << (n - 1 - k) % (n - 1) << endl;
        }
    }
}