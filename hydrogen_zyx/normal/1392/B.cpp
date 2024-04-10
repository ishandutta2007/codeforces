#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        bool f = 0;
        ll mmin = 0x3f3f3f3f;
        ll mmax = -mmin;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mmin = min(mmin, a[i]);
            mmax = max(mmax, a[i]);
        }
        if (k == 0) {
            for (int i = 1; i <= n; i++) cout << a[i] << ' ';
            cout << endl;

        } else if (k & 1) {
            for (int i = 1; i <= n; i++) cout << mmax - a[i] << ' ';
            cout << endl;
        } else {
            for (int i = 1; i <= n; i++) cout << a[i] - mmin << ' ';

            cout << endl;
        }
    }
}