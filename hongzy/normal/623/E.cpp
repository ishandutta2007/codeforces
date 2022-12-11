#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;

const db pi = 2 * acos(-1);
const int N = 262144 + 5;
const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}

ll n;
int k;

struct comp {
   db x, y;
   comp() {}
   comp(db a, db b) : x(a), y(b) {}
   comp operator + (const comp &b) const { return comp(x + b.x, y + b.y); }
   comp operator - (const comp &b) const { return comp(x - b.x, y - b.y); }
   comp operator * (const comp &b) const { return comp(x * b.x - y * b.y, b.x * y + x * b.y); }
   comp conj() { return comp(x, -y); }
} W[N];

int rev[N], len;
void init(int n) {
   int k = 0;
   for(len = 1; len <= n; len <<= 1) k ++;
   for(int i = 1; i < len; i ++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
   for(int i = 0; i < len; i ++)
      W[i] = comp(cos(pi * i / len), sin(pi * i / len));
}
void fft(comp *a, int ty) {
   for(int i = 1; i < len; i ++)
      if(i < rev[i]) swap(a[i], a[rev[i]]);
   static comp t1, t2;
   for(int i = 1; i < len; i <<= 1) {
      for(int j = 0; j < len; j += i << 1) {
         for(int k = j; k < j + i; k ++) {
            t1 = a[k], t2 = W[len / (i << 1) * (k - j)] * a[k + i];
            a[k] = t1 + t2; a[k + i] = t1 - t2;
         }
      }
   }
   if(ty == -1) {
      reverse(a + 1, a + len);
      for(int i = 0; i < len; i ++)
         a[i].x /= len, a[i].y /= len;
   }
}
void conv(int *x, int *y, int *z) {
   static comp a[N], b[N], f1, f0, g1, g0, dfta[N], dftb[N], dftc[N], dftd[N];
   for(int i = 0; i < len; i ++) a[i] = comp(x[i] & 32767, x[i] >> 15);
   for(int i = 0; i < len; i ++) b[i] = comp(y[i] & 32767, y[i] >> 15);
   fft(a, 1); fft(b, 1);
   for(int i = 0; i < len; i ++) {
      int j = (len - i) & (len - 1);
      f1 = (a[i] + a[j].conj()) * comp(0.5, 0);
      f0 = (a[i] - a[j].conj()) * comp(0, -0.5);
      g1 = (b[i] + b[j].conj()) * comp(0.5, 0);
      g0 = (b[i] - b[j].conj()) * comp(0, -0.5);
      dfta[i] = f0 * g0; dftb[i] = f0 * g1;
      dftc[i] = g0 * f1; dftd[i] = f1 * g1;
   }
   for(int i = 0; i < len; i ++) {
      a[i] = dfta[i] + dftb[i] * comp(0, 1);
      b[i] = dftc[i] + dftd[i] * comp(0, 1);
   }
   fft(a, -1); fft(b, -1);
   for(int i = 0; i < len; i ++) {
      ll xa = (ll) (a[i].x + 0.5) % mod;
      ll xb = (ll) (a[i].y + 0.5) % mod;
      ll xc = (ll) (b[i].x + 0.5) % mod;
      ll xd = (ll) (b[i].y + 0.5) % mod;
      z[i] = ((xa << 30) + ((xb + xc) << 15) + xd) % mod;
   }
}
int fav[N], fac[N], pw[N], pww[N];
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
   pw[0] = 1;
   rep(i, 1, n) pw[i] = add(pw[i - 1], pw[i - 1]);
   pww[0] = 1;
   rep(i, 1, n) pww[i] = 1ll * pww[i - 1] * pw[n] % mod;
}
int Pw(ll x) {
   return 1ll * pww[x / k] * pw[x % k] % mod;
}
int C(int n, int m) {
   return n < m ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
#define poly vector<int>
poly Lim(int n, poly a) { a.resize(n); return a; }
poly operator * (const poly &a, const poly &b) {
   int deg = (int) a.size() + b.size() - 2; init(deg);
   static int ntta[N], nttb[N], nttc[N];
   for(int i = 0; i < len; i ++) ntta[i] = i < a.size() ? a[i] : 0;
   for(int i = 0; i < len; i ++) nttb[i] = i < b.size() ? b[i] : 0;
   conv(ntta, nttb, nttc);
   poly ans(deg + 1);
   for(int i = 0; i <= deg; i ++) ans[i] = nttc[i];
   return ans;
}
poly g;
poly gpoly(poly g, int y) { //g(2^y x)
   rep(i, 1, k) g[i] = 1ll * Pw(i * y) * g[i] % mod;
   return g;
}
poly solve(int n) { //\prod_{i = 1}^n g(2^i x)
   if(n == 1) return gpoly(g, n);
   poly z = solve(n >> 1);
   z = Lim(k + 1, z * gpoly(z, n >> 1));
   if(n & 1) z = Lim(k + 1, z * gpoly(g, n));
   return z;
}
int main() {
   scanf("%lld%d", &n, &k);
   if(n > k) return 0 * puts("0");
   binom(k); g.resize(k + 1);
   rep(i, 1, k) g[i] = fav[i];
   poly f = solve(n);
   // rep(i, 0, k) printf("f[%d] = %d\n", i, f[i]);
   int res = 0;
   rep(i, n, k) res = add(res, 1ll * C(k, i) * f[i] % mod * fac[i] % mod * qpow((mod + 1) / 2, i) % mod);
   printf("%d\n", res); 
   return 0;
}