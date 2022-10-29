
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[200000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cin >> s;
        for (ll i = 0; i < s.length(); i++) a[i + 1] = s[i] - '0' - 1;
        partial_sum(a, a + n + 1, a);
        unordered_map<ll, ll> m;
        ll ans = 0;
        for (ll i = 0; i <= n; i++) {
            if (!m.empty()) ans += m[a[i]];
            m[a[i]]++;
        }
        cout << ans << endl;
    }
}