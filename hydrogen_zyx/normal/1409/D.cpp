#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> s >> n;
        ll ss = stoll(s);
        ll cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt += s[i] - '0';
        }
        if (cnt <= n) {
            cout << 0 << endl;
            continue;
        }
        cnt = 0;
        ll now = 0;
        ll ans = qpow(10, s.length()) - ss;
        for (ll i = 0; i < s.length(); i++) {
            cnt += s[i] - '0';
            now += qpow(10, s.length() - i - 1) * (s[i] - '0');
            if (cnt + 1 <= n)
                ans = min(ans, now + qpow(10LL, s.length() - i - 1LL) - ss);
        }
        cout << ans << endl;
    }
}