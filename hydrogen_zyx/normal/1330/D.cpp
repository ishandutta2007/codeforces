#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
ll dp[100];
int main() {
    ll t;
    cin >> t;
    while (t--) {
        dp[0] = 1;
        cin >> n >> m;
        for (int i = 1; i <= 30; i++) {
            dp[i] = ((dp[i - 1] + 1) * (qpow(2, i)) + dp[i - 1]) % m;
        }
        ll cnt = 0;
        ll k = n;
        while (k) {
            cnt++;
            k >>= 1;
        }
        ll last = n - (1 << (cnt - 1)) + 1;
        ll ans = ((dp[cnt - 2] + 1) * last + dp[cnt - 2]) % m;
        cout << ans << endl;
    }
}