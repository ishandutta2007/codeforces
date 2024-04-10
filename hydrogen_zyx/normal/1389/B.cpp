#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
ll amax[1000000];
ll tu[1000000];
ll zhui[1000000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, z;
        cin >> n >> k >> z;
        for (int i = 1; i <= 2 * k + n; i++) zhui[i] = tu[i] = 0;
        ll ans = 0, mmax = 0;
        ll kkk = 2;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1) {
                if (a[i] + a[i - 1] > mmax) kkk = i;
                mmax = max(mmax, a[i] + a[i - 1]);
                amax[i] = mmax;
                zhui[i] = kkk;
            }
            if (i <= k + 1) ans += a[i];
        }
        for (ll i = n + 1; i <= 2 * k + n; i++) {
            a[i] = 0;
            amax[i] = amax[n];
        }
        ll p = 1 + k;
        ll maxans = ans;
        for (ll i = 1; i <= z; i++) {
            if (p <= 2) break;
            ans -= tu[p] * amax[p] + tu[p + 1] * amax[p + 1];
            ans += (tu[p] + tu[p + 1]) * amax[p - 1];
            tu[zhui[p - 1]] += tu[p] + tu[p + 1];
            ans -= a[p] + a[p - 1];
            ans += amax[p - 1];
            tu[zhui[p - 1]]++;
            p -= 2;
            maxans = max(maxans, ans);
        }
        cout << maxans << endl;
    }
}