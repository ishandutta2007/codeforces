#include <bits/stdc++.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#define ri register int
#define ptf printf
using namespace std;
typedef double db;
typedef long double ld;
typedef long long ll;
typedef vector <int> poly;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef unsigned long long ulll;
typedef unsigned int uii;
typedef string strr;
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
const ll Inf = 2e18;
const int rlen = 1 << 20, inf = 1e9;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() getchar()//(((ib == ob) && (ob = (ib =  buf) + fread(buf, 1, rlen, stdin)), ib == ob) ? -1 : *ib++)
inline int read() {
  static int ans, f;
  static char ch;
  ans = 0, ch = gc(), f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) ans = (ans << 3) + (ans << 1) + (ch ^ 48), ch = gc();
  return f ? ans: -ans;
}
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
inline int Read(char *s) {
  static int top;
  static char ch;
  top = 0, ch = gc();
  while (!isalpha(ch) && !isdigit(ch)) ch = gc();
  while (isalpha(ch) || isdigit(ch)) s[++top] = ch, ch = gc();
  return top;
}
namespace modular {
  const int mod = 1e9 + 7;// = 998244353;
  //int mod;
  int ret;
  inline int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
  inline void Dec(int &a, int b) { a = a < b? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) {
    for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
    return ret;
  }
  inline int Inv(int a) { return ksm(a, mod - 2); }
  inline int sqr(int a) { return (ll) a * a % mod; }
  inline int cub(int a) { return (ll) a * a % mod * a % mod; }
} using namespace modular;
template <typename T> inline void ckmax(T &a, T b) { a < b ? a = b : 0; }
template <typename T> inline void ckmin(T &a, T b) { a > b ? a = b : 0; }
template <typename T> inline T Abs(T a) { return a < 0 ? -a : a; }
template <typename T> inline T gcd(T a, T b) {
  T t;
  while (b) t = a, a = b, b = t - t / a * a;
  return a;
}
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
}
const int N = 20, M = 1 << 20 | 5;
bool trs[N][N];
int n, pw[N], cnt[M];
ll res[M], f[N][M], g[M][N];
char s[N];
inline void fwt(ll *a, int n) {
  for (ri i = 1; i < n; i <<= 1) for (ri j = 0; j < n; j += i << 1)
  for (ri k = 0; k < i; ++k) a[j + k + i] += a[j + k];
}
inline void ifwt(ll *a, int n) {
  for (ri i = 1; i < n; i <<= 1) for (ri j = 0; j < n; j += i << 1)
  for (ri k = 0; k < i; ++k) a[j + k] -= a[j + k + i];
}
map <vector <int>, ll> F;
inline ll solve(vector <int> sz) {
  ll res = 0, coe;
  for (ri s = 0; s < (1 << n); ++s) {
    coe = (n - cnt[s]) & 1 ? -1 : 1;
    for (ri i = 0; i < sz.size(); ++i) coe *= f[sz[i]][s];
    res += coe;
  }
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 0; i < n; ++i) {
    Read(s);
    for (ri j = 0; j < n; ++j) trs[i][j] = s[j + 1] ^ 48;
  }
  for (ri i = f[0][0] = pw[0] = 1; i <= n; ++i) pw[i] = pw[i - 1] << 1;
  for (ri i = 1; i < pw[n]; ++i) cnt[i] = cnt[i >> 1] + (i & 1);
  for (ri s = 0, t; s < pw[n]; ++s) for (ri i = 0; i < n; ++i) if (s >> i & 1) {
    t = s ^ pw[i];
    if (!t) g[s][i] = 1;
    else for (ri j = 0; j < n; ++j) if (trs[j][i]) g[s][i] += g[t][j];
    f[cnt[s]][s] += g[s][i];
  }
  for (ri i = 0; i <= n; ++i) fwt(f[i], pw[n]);
  for (ri s = 0; s < pw[n - 1]; ++s) {
    vector <int> sz(1, 1);
    for (ri i = 0; i < n - 1; ++i) if (s >> i & 1) ++sz.back(); else sz.pb(1);
    bool ff = 1;
    for (ri i = 1; i < sz.size(); ++i) ff &= sz[i - 1] >= sz[i];
    if (ff) res[s] = solve(sz), reverse(sz.begin(), sz.end()), F[sz] = res[s];
    else sort(sz.begin(), sz.end()), res[s] = F[sz];
  }
  ifwt(res, pw[n - 1]);
  for (ri i = 0; i < pw[n - 1]; ++i) cout << res[i] << ' ';
  return 0;
}