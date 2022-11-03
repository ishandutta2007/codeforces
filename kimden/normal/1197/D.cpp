#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    const ll INF = 1e16;
    vector<ll> cur(m, INF);
    ll ans = 0;
    cur[0] = pref[0] + k;
    for (int i = 1; i <= n; ++i) {
        ll oo = cur[0];
        for (int j = 1; j < m; ++j) {
            oo = min(oo, cur[j]);
        }
        ans = max(ans, pref[i] - oo);
        cur[i % m] += k;
        cur[i % m] = min(cur[i % m], pref[i] + k);
    }
    cout << ans << "\n";
}