#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m, mod;
ll u, v;

ll get(ll l, ll r, ll tl, ll tr, ll a, ll d) {
    l = max(l, tl);
    r = min(r, tr);
    if (r < l) return 0;
    ll cnt = tr - tl + 1;
    if (v < a) return 0;
    if (u > a + d*(cnt - 1)) return 0;
    if (l == tl && r == tr) {
        ll ld = (u + 2*d - 1 - a) / d - 1;
        ll rd = (v + d - a) / d;
        rd = min(rd, cnt);
        ld = max(ld, 0LL);
        if (rd <= ld) return 0;
        ll s1 = rd - ld;
        ll s2 = 2*a + d*(rd + ld - 1);
        if (s1 % 2 == 0) s1/=2; else s2/=2;
        return max(0LL, s2 % mod * (s1 % mod) % mod);
    } else {
        return (get(l, r, tl, tr - cnt/2, a, d*2) + get(l, r, tr - cnt/2 + 1, tr, a + d, d*2)) % mod;
    }
}

int main(void) {
    scanf("%I64d%I64d%I64d", &n, &m, &mod);
    for (int i = 0; i < m; i++) {
        ll l, r;
        scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
        printf("%I64d\n", get(l, r, 1, n, 1, 1));
    }
    return 0;
}