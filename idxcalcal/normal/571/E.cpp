#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
typedef long long ll;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
#define fi first
#define se second
#define pb push_back
#define rez resize
namespace modular {
  const int mod = 1e9 + 7;
  inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
  inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) { int ret = 1; for (; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1); return ret; } 
}  using namespace modular;
template <typename T> inline T gcd(T a, T b) { T t; while (b) t = a, a = b, b = t - t / a * a; return a; }
template <typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) { x = 1, y = 0; return; }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
}
template <typename T> inline T Abs(T x) { return x < 0 ? -x : x; } 
const int N = 105;
const ll Inf = 1e18;
int n, vl[N * N], sig = 0;
vector <pil> vl1, vl2, Vl1, Vl2;
inline void init(int x, vector <pil> &vl) {
  vl.rez(0);
  int X = x;
  for (ri ct, i = 2; i * i <= X; ++i) if (x % i == 0) {
    for (ct = 0; x == x / i * i; x /= i) ++ct;
    vl.pb(pil(i, ct));
  }
  if (x ^ 1) vl.pb(pil(x, 1ll));
}
inline ll qry(int x, vector <pil> &vl) {
  if (!vl.size() || vl[0].fi > x || vl.back().fi < x) return 0ll;
  int ps = lower_bound(vl.begin(), vl.end(), pil(x, 0ll)) - vl.begin();
  if (vl[ps].fi > x) return 0ll;
  return vl[ps].se;
}
inline pll Merge(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) {
  static ll t;
  while (a1) {
    t = a2 / a1;
    a2 -= t * a1, b2 -= t * b1, c2 -= t * c1;
    swap(a1, a2), swap(b1, b2), swap(c1, c2);
  }
  if (c1 % b1) cout << -1, exit(0);
  t = c2 - b2 * (c1 / b1);
  if (t % a2) cout << -1, exit(0);
  return pll(t / a2, c1 / b1); 
}
inline void merge(vector <pil> &a1, vector <pil> &b1, vector <pil> &a2, vector <pil> &b2) {
  vector <pil> tp;
  sig = 0;
  for (ri i = 0; i < a1.size(); ++i) vl[++sig] = a1[i].fi;
  for (ri i = 0; i < a2.size(); ++i) vl[++sig] = a2[i].fi;
  for (ri i = 0; i < b1.size(); ++i) vl[++sig] = b1[i].fi;
  for (ri i = 0; i < b2.size(); ++i) vl[++sig] = b2[i].fi;
  sort(vl + 1, vl + sig + 1), sig = unique(vl + 1, vl + sig + 1) - vl - 1;
  tp.rez(0);
  for (ri i = 1; i <= sig; ++i) tp.pb(pil(vl[i], qry(vl[i], a1)));
  a1 = tp;
  tp.rez(0);
  for (ri i = 1; i <= sig; ++i) tp.pb(pil(vl[i], qry(vl[i], a2)));
  a2 = tp;
  tp.rez(0);
  for (ri i = 1; i <= sig; ++i) tp.pb(pil(vl[i], qry(vl[i], b1)));
  b1 = tp;
  tp.rez(0);
  for (ri i = 1; i <= sig; ++i) tp.pb(pil(vl[i], qry(vl[i], b2)));
  b2 = tp;
  bool ff = 0;
  ll _a = -Inf, _b = -Inf, _c = -Inf;
  pll X;
  for (ri i = 0; i < sig && !ff; ++i) {
    ll a = b1[i].se, b = b2[i].se, c = a2[i].se - a1[i].se;
    if (!a && !b) { if (c) cout << -1, exit(0); continue; }
    ll g = gcd(gcd(Abs(a), Abs(b)), Abs(c));
    a /= g, b /= g, c /= g;
    if (!b) { if (Abs(c) % Abs(a) || c / a < 0) cout << -1, exit(0); }
    if (_a ==-Inf && _b == -Inf && _c == -Inf) { _a = a, _b = b, _c = c; continue; }
    if (!_b) {
      if (b) { X = Merge(_a, _b, _c, a, b, c), ff = 1; continue; }
      if (_a * c != _c * a) cout << -1, exit(0);
      continue;
    }
    if (_a * b == _b * a) { if (_a * c != _c * a) cout << -1, exit(0); continue; }
    X = Merge(_a, _b, _c, a, b, c), ff = 1;
  }
  if (ff) {
    for (ri i = 0; i < sig; ++i) {
      ll a = b1[i].se, b = b2[i].se, c = a2[i].se - a1[i].se;
      if (a * X.fi + b * X.se != c) cout << -1, exit(0);
    }
    for (ri i = 0; i < sig; ++i) a1[i].se += b1[i].se * X.fi;
    b1.rez(0);
  }
  else {
    ll g = gcd(Abs(_a), Abs(_b));
    if (Abs(_c) % g) cout << -1, exit(0);
    exgcd(_a, _b, X.fi, X.se);
    X.fi *= _c / g, X.se *= _c / g;
    ll r1 = Abs(_a / g), r2 = Abs(_b / g);
    if (r2 && _c <= 0) {
      X.fi = (X.fi % r2 + r2) % r2; 
      X.se = (_c - _a * X.fi) / _b;
    }
    else {
      X.se = (X.se % r1 + r1) % r1;
      if (X.se) X.se -= r1;
      X.fi = (_c - _b * X.se) / _a;
    }
    for (ri i = 0; i < sig; ++i) a1[i].se += b1[i].se * X.fi, b1[i].se *= r2;
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  init(read(), vl1), init(read(), vl2);
  for (--n; n; --n) init(read(), Vl1), init(read(), Vl2), merge(vl1, vl2, Vl1, Vl2);
  int res = 1;
  for (ri i = 0; i < vl1.size(); ++i) Mul(res, ksm(vl1[i].fi, vl1[i].se % (mod - 1)));
  cout << res;
  return 0;
}