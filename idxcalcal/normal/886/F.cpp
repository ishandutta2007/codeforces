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
  const int mod = 998244353;//= 1e9 + 7;
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
const int N = 2005;
const db eps = 1e-6, pi = acos(-1.0);
inline int sgn(db x) { return (x > eps) - (x < -eps); }
struct pt {
  db x, y;
  pt(db x = 0, db y = 0) : x(x), y(y) {}
  inline pt operator + (pt a) { return pt(x + a.x, y + a.y); }
  inline void operator += (pt a) { x += a.x, y += a.y; }
  inline pt operator - (pt a) { return pt(x - a.x, y - a.y); }
  inline void operator /= (db a) { x /= a, y /=a; }
  inline bool operator == (pt a) { return !sgn(x - a.x) && !sgn(y - a.y); }
} a[N], G, ptt[N];
int n;
db X[N], _X;
bool ban[N];
inline db slp(pt a) { return sgn(a.x) ? a.y / a.x : Inf; }
inline int check(db x) {
  db ang, c1, c2;
  if (x == Inf) ang = 0;
  else ang = pi / 2 - atan(x);
  c1 = cos(ang), c2 = sin(ang);
  for (ri i = 1; i <= n; ++i) X[i] = ptt[i].x * c1 - ptt[i].y * c2;
  _X = G.x * c1 - G.y * c2;
  _X += _X;
  sort(X + 1, X + n + 1);
  for (ri i = 1; i + i <= n + 1; ++i) if (sgn((X[i] + X[n + 1 - i]) - _X)) return 0;
  return 1;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 1; i <= n; ++i) a[i].x = read(), a[i].y = read(), G += a[i], ptt[i] = a[i];
  G /= n;
  int sig = 0;
  for (ri i = 1; i <= n; ++i) if (!ban[i]) {
    if (a[i] == G) {
      ban[i] = 1;
      continue;
    }
    for (ri j = 1; j <= n; ++j) if (!ban[j]) {
      if (a[i] + a[j] == G + G) {
        ban[i] = ban[j] = 1;
        break;
      }
    }
    if (ban[i]) continue;
    a[++sig] = a[i];
  }
  if (!sig) return cout << -1, 0;
  vector <db> dir;
  for (ri i = 1; i <= sig; ++i) for (ri j = i + 1; j <= sig; ++j) {
    pt cur = (a[i] + a[j]);
    cur /= 2;
    dir.pb(slp(cur - G));
  }
  sort(dir.begin(), dir.end());
  int ct = 1, res = 0;
  if (1 == sig / 2) res += check(dir[0]);
  for (ri i = 1; i < dir.size(); ++i) {
    if (!sgn(dir[i] - dir[i - 1])) ++ct;
    else ct = 1;
    if (ct == sig / 2) res += check(dir[i]);
  }
  cout << res;
  return 0;
}