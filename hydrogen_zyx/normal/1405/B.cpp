#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 0)
                res += a[i];
            else {
                ll sub = min(res, -a[i]);
                res -= sub;
                a[i] += sub;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] < 0) ans -= a[i];
        cout << ans << endl;
    }
}