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
const int N = 211111;
const ll mod = 1'000'000'009;

ll ipow(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return b * ipow(b, e - 1) % mod;
    return ipow(b * b % mod, e >> 1);
}
ll inv(ll a) {
    return ipow(a, mod - 2);
}
ll pseq(ll b, ll e) {
    if (e == 0) return 0;
    if (e == 1) return 1;
    if (e & 1) return (1 + b * pseq(b, e - 1)) % mod;
    return (1 + b) * pseq(b * b % mod, e >> 1) % mod;
}
char s[N];
ll pba[N];
int main() {
    ll n, a, b;
    int k;
    scanf("%lld%lld%lld%d%s", &n, &a, &b, &k, s);
    ll ba = b * inv(a) % mod;
    ll ans = 0;
    pba[0] = 1;
    for (int i = 0; i < k; i++) {
        pba[i + 1] = pba[i] * ba % mod;
        ans += pba[i] * (s[i] == '+' ? 1 : -1);
        ans %= mod;
    }
    ans = ipow(a, n) * ans % mod * pseq(pba[k], (n + 1) / k);
    if ((ans %= mod) < 0) ans += mod;
    pf("%lld\n", ans);
}