#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 4e5 + 11;
const int mod = 998244353;
const int g = 3;
int rev[N], len, w[N], inv_w[N];
int qpow(int a, int b) {
    int ans = 1;
    for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
        if(b & 1) ans = (ll) ans * a % mod;
    return ans;
}
void InitNTT(int n) {
    int k = 0;
    for(len = 1; len <= n; len <<= 1) k ++;
    for(int i = 1; i < len; i ++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    w[0] = inv_w[0] = 1;
    ll v = qpow(g, (mod - 1) / len);
    for(int i = 1; i < len; i ++)
        inv_w[len - i] = w[i] = w[i - 1] * v % mod;
}
void NTT(int *a, const int *w) {
    for(int i = 1; i < len; i ++)
        if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int i = 1; i < len; i <<= 1) {
        for(int j = 0, t = len / (i << 1); j < len; j += i << 1) {
            const int *wn = w;
            for(int k = j; k < j + i; k ++, wn += t) {
                int t1 = a[k], t2 = (ll) *wn * a[k + i] % mod;
                a[k] = (t1 + t2) % mod;
                a[k + i] = (t1 - t2 + mod) % mod;
            }
        }
    }
    if(w == inv_w) {
        ll v = - (mod - 1) / len;
        v = (v + mod) % mod;
        for(int i = 0; i < len; i ++)
            a[i] = a[i] * v % mod;
    }
}
inline void cpyto(const int *from, int *to, int n) {
    for(int i = 0; i < n; i ++) to[i] = from[i];
    for(int i = n; i < len; i ++) to[i] = 0;
}
//AB = 1 (mod x^n), b[n], b[n + 1], ... will not be modified
void Inv(const int *a, int n, int *b) {
    if(n == 1) { b[0] = qpow(a[0], mod - 2); return ; }
    int m = (n + 1) >> 1; Inv(a, m, b);
    static int ta[N], tb[N]; InitNTT(n * 2);
    cpyto(a, ta, n); cpyto(b, tb, m);
    NTT(ta, w); NTT(tb, w);
    for(int i = 0; i < len; i ++)
        tb[i] = tb[i] * (2 - (ll) tb[i] * ta[i] % mod + mod) % mod;
    NTT(tb, inv_w);
    for(int i = 0; i < n; i ++) b[i] = tb[i];
}
//B^2 = A (mod x^n)
void Sqrt(const int *a, int n, int *b) {
    if(n == 1) { b[0] = 1; return ; }
    int m = (n + 1) >> 1; Sqrt(a, m, b);
    static int ti[N], ta[N], tb[N];
    for(int i = m; i < n; i ++) b[i] = 0;
    Inv(b, n, ti); InitNTT(n * 2);
    for(int i = n; i < len; i ++) ti[i] = 0;
    cpyto(a, ta, n); cpyto(b, tb, m);
    NTT(ta, w); NTT(tb, w); NTT(ti, w);
    for(int i = 0, v = (mod + 1) >> 1; i < len; i ++)
        ti[i] = (ll) ti[i] * ((ll) tb[i] * tb[i] % mod + ta[i]) % mod * v % mod;
    NTT(ti, inv_w);
    for(int i = 0; i < n; i ++) b[i] = ti[i];
}
int main() {
    static int G[N], tG[N], t1[N], t2[N];
    int n, m, pw = 1;
    scanf("%d%d", &n, &m); m ++;
    for(int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        if(x >= m) continue ;
        G[x] = 1; pw = max(pw, x + 1);
    }
    for(int i = 0; i < pw; i ++) tG[i] = (i == 0) - (G[i] ? 4 : 0);
    Sqrt(tG, m, G); G[0] ++; Inv(G, m, tG);
    for(int i = 1; i < m; i ++)
        printf("%d\n", (tG[i] + tG[i]) % mod);
    return 0;
}