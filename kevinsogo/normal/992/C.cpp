#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1'000'000'007;

ll ipow2(ll e) {
    if (e == 0) return 1;
    if (e == 1) return 2;
    if (e & 1) return ipow2(e - 1) * 2 % mod;
    ll res = ipow2(e >> 1);
    return res * res % mod;
}
int main() {
    ll x, k;
    scanf("%lld%lld", &x, &k);
    ll ans = x == 0 ? 0 : (2*(x % mod) - 1) * ipow2(k) + 1;
    if ((ans %= mod) < 0) ans += mod;
    printf("%lld\n", ans);
}