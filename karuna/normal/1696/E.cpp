#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll _pow(ll a, ll x = MOD - 2) {
    ll ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x /= 2;
    }
    return ret;
}
ll F[404040], IF[404040];

ll comb(ll a, ll b) {
    if (a < b) return 0;
    return F[a] * IF[b] % MOD * IF[a - b] % MOD;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    F[0] = 1;
    for (int i = 1; i < 404040; i++) {
        F[i] = F[i - 1] * i % MOD;
    }
    IF[404040 - 1] = _pow(F[404040 - 1]);
    for (int i = 404040 - 1; i > 0; i--) {
        IF[i - 1] = IF[i] * i % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        int x; cin >> x;
        ans = (ans + comb(x + i - 1, i)) % MOD;
    }
    cout << ans;
}