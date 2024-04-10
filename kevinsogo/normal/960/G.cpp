#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
const ll r1 = 363395222LL;
const ll rt = 19;
const ll sh = 19;
const ll i2 = mod + 1 >> 1;
const ll SH = 1 << sh;

ll ipow(ll b, ll e) {
    if (!e) return 1;
    if (e == 1) return b % mod;
    if (e & 1) return ipow(b, e - 1) * b % mod;
    return ipow(b * b % mod, e >> 1);
}

// arrays
ll prs[rt+1];
ll irs[rt+1];
ll fac[SH << 1];
ll ifc[SH << 1];
ll A[SH << 1];
ll B[SH << 1];
ll C[SH << 1];

void fft(ll *A, int m, int ms, ll *rs) {
    if (!ms) return;
    for (int k = 0; k < m; k++) C[k] = A[k];
    int cc = 0;
    for (int k = 0; k < m; k += 2) A[cc++] = C[k];
    for (int k = 1; k < m; k += 2) A[cc++] = C[k];
    m >>= 1;
    ll r = rs[ms--];
    fft(A  ,m,ms,rs);
    fft(A+m,m,ms,rs);
    ll pr = 1;
    for (int k = 0, km = m; k < m; k++, km++) {
        ll fE = A[k], fO = A[km]*pr;
        A[k ] = (fE + fO) % mod;
        A[km] = (fE - fO) % mod;
        pr = pr * r % mod;
    }  
}

void mul(ll *a, int m, ll *b, int n, ll *t) {
    int k = 0;
    while (1 << k <= m + n + 1) k++;
    for (int i = 0; i <= m; i++) A[i] = a[i];
    for (int i = 0; i <= n; i++) B[i] = b[i];
    while (m < 1 << k) A[++m] = 0;
    while (n < 1 << k) B[++n] = 0;
    fft(A, 1 << k, k, prs);
    fft(B, 1 << k, k, prs);
    for (int i = 0; i < 1 << k; i++) A[i] = A[i] * B[i] % mod;
    fft(A, 1 << k, k, irs);
    ll sc = ipow(1 << k, mod - 2);
    for (int i = 0; i < 1 << k; i++) {
        t[i] = A[i] * sc % mod;
    }
}

void muls(ll *t, ll *e, int i, int j) {
    if (j - i == 0) {
        t[0] = 1;
    } else if (j - i == 1) {
        t[0] = i;
        t[1] = 1;
    } else {
        int k = i + j >> 1;
        ll *f = e + (k - i + 1);
        muls(e, t, i, k);
        muls(f, t, k, j);
        mul(e, k - i, f, j - k, t);
    }
}

ll T[SH << 1];
ll E[SH << 1];
int main() {
    prs[rt] = r1;
    irs[rt] = ipow(r1,mod-2);
    for (int i = rt; i > 0; i--) {
        prs[i-1] = prs[i] * prs[i] % mod;
        irs[i-1] = irs[i] * irs[i] % mod;
    }

    fac[0] = fac[1] = ifc[0] = ifc[1] = 1;
    for (int i = 2; i < SH << 1; i++) {
        ifc[i] = -(mod/i) * ifc[mod % i] % mod;
    }
    for (int i = 2; i < SH << 1; i++) {
        fac[i] =     i  * fac[i-1] % mod;
        ifc[i] = ifc[i] * ifc[i-1] % mod;
    }

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    n--, a--, b--;
    ll ans = 0;
    if (a >= 0 && b >= 0 && a + b <= n) {
        muls(T, E, 0, n);
        ans = T[a + b] * fac[a + b] % mod * ifc[a] % mod * ifc[b] % mod;
    }
    if ((ans %= mod) < 0) ans += mod;
    printf("%lld\n", ans);
}