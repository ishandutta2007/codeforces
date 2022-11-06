#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define ri register int
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
  const int mod =  1e9 + 7;// = 998244353;
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
const int N = 1e5 + 5;
int dfn[N], cnt = 0, n, m, ss[N], W, a[5], tot = 0, F[N];
int trs[505][505];
bool vs[505][505];
bool ff;
map <ll, int> Id;
vector <int> mp[N];
vector <int> vl;
vector <pii> e[N];
void dfs(int p, int ft) {
  dfn[p] = ++cnt;
  for (ri i = 0, v; i < e[p].size(); ++i) if ((v = e[p][i].fi) ^ ft) {
    if (!dfn[v]) ss[v] = ss[p] ^ e[p][i].se, dfs(v, p);
    else if (dfn[p] > dfn[v]) {
      if (v == 1) W = ss[p] ^ e[p][i].se;
      else vl.pb(ss[v] ^ ss[p] ^ e[p][i].se);
    }
  }
}
inline void cl() { ff = 1; for (ri i = 0; i <= 4; ++i) a[i] = 0; }
inline void ins(int w) {
  if (!w) ff = 0;
  if (!ff) return;
  for (ri i = 4; ~i; --i) if (w >> i & 1) {
    if (a[i]) w ^= a[i];
    else {
      a[i] = w;
      break;
    }
    if (!w) {
      ff = 0;
      break;
    }
  }
}
inline void fix(int *a) {
  for (ri i = 4; ~i; --i) if (a[i])
  for (ri j = i + 1; j <= 4; ++j) if (a[j] >> i & 1) a[j] ^= a[i];
}
inline ll cal(vector <int> a) {
  ll res = 0;
  for (ri i = 0; i <= 4; ++i) res *= 32, res += a[i];
  return res;
}
vector <pii> curr;
inline int get(int x, int y) {
  if (y > x) swap(x, y);
  if (trs[x][y]) return trs[x][y];
  ff = 1;
  poly cur1 = mp[x], cur2 = mp[y];
  for (ri i = 0; i <= 4; ++i) a[i] = cur1[i];
  for (ri i = 0; i <= 4; ++i) if (cur2[i]) ins(cur2[i]);
  trs[x][y] = -1;
  if (ff) {
    fix(a);
    cur1.rez(0);
    for (ri i = 0; i <= 4; ++i) cur1.pb(a[i]);
    ll tttttt = cal(cur1), ttttt = tttttt;
    if (!Id.count(tttttt)) Id[tttttt] = ++tot, mp[tot] = cur1;
    trs[x][y] = Id[tttttt];
  }
  ff = 1;
  return trs[x][y];
}
inline void trans(int coe, int lm) {
  static int b[5];
  if (!ff) return;
  fix(a);
  poly cur;
  for (ri i = 0; i <= 4; ++i) cur.pb(a[i]);
  ll tttttt = cal(cur), ttttt;
  if (!Id.count(tttttt)) Id[tttttt] = ++tot, mp[tot] = cur;
  ttttt = Id[tttttt];
  for (ri i = 0; i <= 4; ++i) b[i] = a[i];
  for (ri t = 1; t <= lm; ++t) {
    if (~(tttttt = get(t, ttttt))) curr.pb(pii(tttttt, mul(coe, F[t])));
    for (ri i = 0; i <= 4; ++i) a[i] = b[i];
  }
}
inline void cpy() {
  while (curr.size()) Add(F[curr.back().fi], curr.back().se), curr.ppp();
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), m = read();
  for (ri i = 1, u, v, w; i <= m; ++i) {
    u = read(), v = read(), w = read();
    e[u].pb(pii(v, w));
    e[v].pb(pii(u, w));
  }
  Id[0] = ++tot;
  mp[tot] = vector <int> (5);
  dfn[1] = cnt = F[1] = 1;
  for (ri i = 0, v; i < e[1].size(); ++i) {
    v = e[1][i].fi;
    if (!dfn[v]) {
      ss[v] = e[1][i].se;
      vl.rez(0), W = -1;
      dfs(v, 1);
      cl();
      int lm = tot;
      curr.rez(0);
      while (vl.size()) ins(vl.back()), vl.ppp();
      if (~W) trans(2, lm), ins(W), trans(1, lm);
      else trans(1, lm);
      cpy();
    }
  }
  int res = 0;
  for (ri i = 1; i <= tot; ++i) Add(res, F[i]);
  cout << res;
  return 0;
}