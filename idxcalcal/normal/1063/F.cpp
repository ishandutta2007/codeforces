#include <bits/stdc++.h>
#include <tr1/unordered_map>
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
const int rlen = 1 << 20, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib =  buf) + fread(buf, 1, rlen, stdin)), ib == ob) ? -1 : *ib++)
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
const int N = 1e6 + 5;
int n;
char s[N];
namespace SA {
  int sa[N], sa2[N], rk[N], m, ht[N], st[N][20], Lg[N];
  inline void Sort() {
    static int cnt[N];
    for (ri i = 1; i <= m; ++i) cnt[i] = 0;
    for (ri i = 1; i <= n; ++i) ++cnt[rk[i]];
    for (ri i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (ri i = n; i; --i) sa[cnt[rk[sa2[i]]]--] = sa2[i];
  }
  inline void getSA() {
    for (ri i = 1; i <= n; ++i) rk[i] = s[i], sa2[i] = i;
    for (ri i = 2; i <= n; ++i) Lg[i] = Lg[i >> 1] + 1;
    m = 128, Sort();
    for (ri w = 1, p = 0; m ^ n; m = p, p = 0, w <<= 1) {
      for (ri i = n - w + 1; i <= n; ++i) sa2[++p] = i;
      for (ri i = 1; i <= n; ++i) if (sa[i] > w) sa2[++p] = sa[i] - w;
      Sort(), swap(rk, sa2);
      rk[sa[1]] = p = 1;
      for (ri i = 2; i <= n; ++i)
      rk[sa[i]] = (sa2[sa[i]] == sa2[sa[i - 1]] && sa2[sa[i] + w] == sa2[sa[i - 1] + w]) ? p : ++p;
    }
    for (ri i = 1, j, k = 0; i <= n; ht[rk[i++]] = k) for (k ? --k : k, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; ++k);
    for (ri i = 1; i <= n; ++i) st[i][0] = ht[i];
    for (ri j = 1; j < 20; ++j) for (ri i = 1; i + (1 << j) - 1 <= n; ++i) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
  inline int qry(int l, int r) {
    if (l > r) return inf;
    int k = Lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
  }
}
namespace sgt {
  #define lc (son[p][0])
  #define rc (son[p][1])
  #define mid ((l + r) >> 1)
  #define qll lc, l, mid
  #define qrr rc, mid + 1, r
  const int N = ::N << 5;
  int mx[N], son[N][2], tot = 0, ql, qr;
  inline int cpy(int x) {
    int p = ++tot;
    mx[p] = mx[x], lc = son[x][0], rc = son[x][1];
    return p;
  }
  inline void upd(int &p, int l, int r, int k, int v) {
    p = cpy(p), ckmax(mx[p], v);
    if (l == r) return;
    k <= mid ? upd(qll, k, v) : upd(qrr, k, v);
  }
  inline int qry(int p, int l, int r) {
    if (!p) return 0;
    if (ql <= l && r <= qr) return mx[p];
    if (qr <= mid) return qry(qll);
    if (ql > mid) return qry(qrr);
    return max(qry(qll), qry(qrr));
  }
  inline int Qry(int p, int l, int r) { return ql = l, qr = r, qry(p, 1, n); }
  #undef mid  
}
int f[N], rt[N];
inline bool check(int p, int ps, int lm) {
  if (ps > n) return 0;
  int l, r, ql, qr, ed = SA:: rk[ps];
  l = 1, r = ed;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (SA:: qry(mid + 1, ed) >= lm - 1) r = mid - 1, ql = mid;
    else l = mid + 1;
  }
  l = ed, r = n;
  while (l <= r) {
    int mid = (l + r + 1) >> 1;
    if (SA:: qry(ed + 1, mid) >= lm - 1) l = mid + 1, qr = mid;
    else r = mid - 1;
  }
  return sgt:: Qry(p, ql, qr) >= lm - 1;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), Read(s);
  SA:: getSA();
  for (ri i = n; i; --i) {
    f[i] = f[i + 1] + 1;
    while (!check(rt[i + f[i]], i, f[i]) && !check(rt[i + f[i]], i + 1, f[i])) --f[i];
    rt[i] = rt[i + 1];
    sgt:: upd(rt[i], 1, n, SA:: rk[i], f[i]);
  }
  cout << sgt:: mx[rt[1]];
  return 0;
}