#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;
const int N = 800111;
const ll mod1 = 2013265921;
const ll rt1 = 195061667;
const ll mod2 = 919601153;
const ll rt2 = 611244703;
const int sh = 20;

ll ipow(ll b, ll e, ll mod) {
    if (e == 0) return 1;
    if ( e== 1) return b;
    if (e & 1) return ipow(b, e - 1, mod) * b % mod;
    return ipow(b * b % mod, e >> 1, mod);
}

ll x, y;
void egcd(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        egcd(b, a % b);
        ll t = x - (a / b) * y;
        x = y;
        y = t;
    }
}

ll inv(ll a, ll n) {
    egcd(a, n);
    return x % n;
}

// pow(rt, (1 << sh), mod) == 1


ll rtpows1[sh+1];
ll irtpows1[sh+1];
ll rtpows2[sh+1];
ll irtpows2[sh+1];
void init() {
    ll irt1 = inv(rt1, mod1);
    assert(ipow(rt1, 1 << sh, mod1) == 1);
    assert(ipow(irt1, 1 << sh, mod1) == 1);
    assert(ipow(rt1, 1 << sh - 1, mod1) == mod1 - 1);
    assert(ipow(irt1, 1 << sh - 1, mod1) == mod1 - 1);
    rtpows1[sh] = rt1;
    irtpows1[sh] = irt1;
    for (int i = sh; i--;) {
        rtpows1[i] = rtpows1[i + 1] * rtpows1[i + 1] % mod1;
        irtpows1[i] = irtpows1[i + 1] * irtpows1[i + 1] % mod1;
    }
    assert(rtpows1[0] == 1);
    assert(irtpows1[0] == 1);

    ll irt2 = inv(rt2, mod2);
    assert(ipow(rt2, 1 << sh, mod2) == 1);
    assert(ipow(irt2, 1 << sh, mod2) == 1);
    assert(ipow(rt2, 1 << sh - 1, mod2) == mod2 - 1);
    assert(ipow(irt2, 1 << sh - 1, mod2) == mod2 - 1);
    rtpows2[sh] = rt2;
    irtpows2[sh] = irt2;
    for (int i = sh; i--;) {
        rtpows2[i] = rtpows2[i + 1] * rtpows2[i + 1] % mod2;
        irtpows2[i] = irtpows2[i + 1] * irtpows2[i + 1] % mod2;
    }
    assert(rtpows2[0] == 1);
    assert(irtpows2[0] == 1);
}

void fft(ll *a, ll *t, int k, int n, ll mod, ll *rtpows) {
    if (!k) return;
    int j = 0;
    for (int i = 0; i < n; i += 2) t[j++] = a[i];
    for (int i = 1; i < n; i += 2) t[j++] = a[i];
    ll rt = rtpows[k--];
    n >>= 1;
    fft(t,   a,   k, n, mod, rtpows);
    fft(t+n, a+n, k, n, mod, rtpows);
    ll pw = 1;
    for (int i = 0, j = n; i < n; i++, j++) {
        ll pd = pw * t[j];
        a[i] = (t[i] + pd) % mod;
        a[j] = (t[i] - pd) % mod;
        pw = pw * rt % mod;
    }
}

int mulx(int n, ll *a, ll *b, ll *c, ll *rtpows, ll *irtpows, ll mod) {
    int m  = n;
    int r = m + n + 5;
    while ((r & -r) != r) r++;
    while (m < r) a[m++] = 0;
    while (n < r) b[n++] = 0;

    int k = 0;
    while (1 << k < r) k++;
    assert((1 << k) == r);

    fft(a, c, k, r, mod, rtpows);
    fft(b, c, k, r, mod, rtpows);

    for (int i = 0; i < r; i++) {
        c[i] = a[i] * b[i] % mod;
    }

    fft(c, a, k, r, mod, irtpows);

    ll sc = inv(r, mod);
    for (int i = 0; i < r; i++) {
        c[i] = c[i] * sc % mod;
        if (c[i] < 0) c[i] += mod;
    }
    // while (r && c[r - 1] == 0) r--;
    return r;
    // fr(i,n) fr(j,n) {
    //     c[i+j] += a[i] * b[j];
    // }
}

ll a[N], b[N], at[N], bt[N], c1[N], c2[N], c[N];
int mul(int n) {
    fr(i,n) at[i] = a[i], bt[i] = b[i];
    int r1 = mulx(n, at, bt, c1, rtpows1, irtpows1, mod1);
    fr(i,n) at[i] = a[i], bt[i] = b[i];
    int r2 = mulx(n, at, bt, c2, rtpows2, irtpows2, mod2);
    assert(r1 == r2);
    int r = r1;
    ll mod = mod1 * mod2;
    ll i21 = inv(mod2, mod1);
    ll i12 = inv(mod1, mod2);
    // pf("%lld\n", mod);
    for (int i = 0; i < r; i++) {
        c[i] = (c1[i] * i21 % mod1 * mod2 + c2[i] * i12 % mod2 * mod1) % mod;
        // pf("%lld %lld %lld\n", c1[i], c2[i],c [i]);
        if (c[i] < 0) c[i] += mod;
    }
    // while (r && c[r - 1] == 0) r--;
    return r;
    // fr(i,n) fr(j,n) {
    //     c[i+j] += a[i] * b[j];
    // }
}


int v[N];
int main() {
    init();
    int n, x;
    sf("%d%d", &n, &x);
    v[0] = v[n+1] = -1;
    fq(i,n) {
        int vl;
        sf("%d", &vl);
        v[i] = vl < x ? -1 : 1;
    }
    int gc = 0;
    ll a0 = 0;
    for (int i = 0; i <= n;) {
        assert(v[i] == -1);
        int j = i + 1;
        while (v[j] != -1) j++;
        ll gr = j - i;
        a[gc++] = gr;
        a0 += gr * (gr - 1) / 2;
        i = j;
    }
    // fr(i,gc) pf("%lld ", a[i]); puts("");
    fr(i,gc) b[gc-1-i] = a[i];
    mul(gc);
    pf("%lld", a0);
    ffo(i,1,gc) {
        pf(" %lld", c[i-1]);
    }
    fe(i,gc,n) {
        pf(" 0");
    }
    pf("\n");
}