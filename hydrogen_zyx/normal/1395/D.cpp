#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
vector<ll> v1, v2;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll d, n, m;
    cin >> n >> d >> m;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll i;
    ll ans = a[n - 1];
    v1.push_back(0);
    for (i = n - 2; i >= 0; i--) {
        if (a[i] <= m) {
            v1.push_back(a[i]);
        } else
            v2.push_back(a[i]);
    }
    for (ll i = 1; i < v1.size(); i++) v1[i] += v1[i - 1];
    ll p1 = 1, p2 = 0;
    for (ll i = 1; i <= n - 1 - (n - 1) / (d + 1) * (d + 1); i++) {
        if (p1 < v1.size()) {
            ans += v1[p1] - v1[p1 - 1];
            p1++;
        }
    }
    for (ll i = 1; i <= (n - 1) / (d + 1); i++) {
        ll l1 =
            (p1 + d < v1.size()
                 ? v1[p1 + d] - v1[p1 - 1]
                 : (p1 <= v1.size() ? v1[(ll)v1.size() - 1] - v1[p1 - 1] : 0));
        ll l2 = (p2 < v2.size() ? v2[p2] : 0);
        if (l1 < l2) {
            p2++;
            ans += l2;
        } else {
            p1 += d + 1;
            ans += l1;
        }
    }
    cout << ans << endl;
}