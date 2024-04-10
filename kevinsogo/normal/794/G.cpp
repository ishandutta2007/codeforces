#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define N 311111

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

char c[N];
char d[N];
ll fac[N<<3];
ll ifc[N<<3];
ll pw[N<<3];
ll sm[N<<3];

ll choose(int n, int r) {
    return 0 <= r && r <= n ? fac[n] * ifc[n - r] % mod * ifc[r] % mod : 0;
}

ll tr[N<<3];
int main() {
    fac[0] = fac[1] = ifc[0] = ifc[1] = 1;
    for (int i = 2; i < N<<3; i++) {
        ifc[i] = (mod - mod/i) * ifc[mod%i] % mod;
    }
    for (int i = 2; i < N<<3; i++) {
        fac[i] = i * fac[i - 1] % mod;
        ifc[i] = ifc[i] * ifc[i - 1] % mod;
    }
    pw[0] = 1, sm[0] = 0;
    for (int i = 1; i < N<<3; i++) {
        pw[i] = (pw[i - 1] << 1) % mod;
        sm[i] = ((sm[i - 1] << 1) + 2) % mod;
    }
    int n;
    scanf("%s%s%d", c, d, &n);
    int ca = 0, cb = 0, cq = 0;
    int da = 0, db = 0, dq = 0;
    for (char *s = c; *s; s++) (*s == 'A' ? ca : *s == 'B' ? cb : cq)++;
    for (char *s = d; *s; s++) (*s == 'A' ? da : *s == 'B' ? db : dq)++;
    ll ans = 0;

    // equal
    int l = ca + cb + cq;
    if (l == da + db + dq) {
        int pa = 0, pb = 0, pq = 0;
        ll eq = 1;
        for (int i = 0; i < l; i++) {
            if (c[i] == '?' || d[i] == '?' || c[i] == d[i]) {
                if (c[i] == '?' && d[i] == '?') eq <<= 1;
                (c[i] == 'A' || d[i] == 'A' ? pa : c[i] == 'B' || d[i] == 'B' ? pb : pq)++;
                eq %= mod;
            } else {
                eq = 0;
                break;
            }
        }
        ans += sm[n] * sm[n] % mod * eq;
        ans %= mod;

        int w = da - ca;
        ll ct = choose(cq + dq, cq - w) - eq;
        ct %= mod;
        ll r = 0;
        for (ll g = n; g; g--) {
            int i = n / g;
            if (!tr[i]) {
                tr[i] = (ll)i * i;
                for (ll h = 2; h <= i; h++) {
                    tr[i] -= tr[i / h];
                }
            }
        }

        for (int g = 1; g <= n; g++) {
            r += pw[g] * tr[n / g];
        }
        r %= mod;
        ans += r * ct;
        ans %= mod;
    }

    for (int w = -dq; w <= cq; w++) {
        int la = w + dq + db - (cq + cb);
        int lb = w + ca - da;
        if (la < 0 || lb < 0) la = -la, lb = -lb;
        if (la > 0 && lb > 0) {
            int g = gcd(la, lb);
            la /= g, lb /= g;
            ans += sm[n / max(la, lb)] * choose(cq + dq, cq - w);
            ans %= mod;
        }
    }
    if ((ans %= mod) < 0) ans += mod;
    printf("%lld\n", ans);
}