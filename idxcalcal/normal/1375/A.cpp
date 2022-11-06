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
  const int mod  = 998244353;// = 1e9 + 7;
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
const int N = 2e5 + 5;
int n, a[N], f[105][205][2];
pii g[105][205][2];
void dfs(int p, int dt, int x) {
  if (!p) return;
  dfs(p - 1, g[p][dt][x].fi, g[p][dt][x].se);
  cout << (x ? a[p] : -a[p]) << ' ';
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    memset(f, 0, sizeof(f));
    for (ri i = 1; i <= n; ++i) {
      a[i] = read();
      if (a[i] < 0) a[i] = -a[i];
    }
    f[1][n][0] = f[1][n][1] = 1;
    for (ri i = 2; i <= n; ++i) {
      for (ri j = n - i + 1; j <= n + i - 1; ++j) {
        for (ri x = 0; x < 2; ++x) if (f[i - 1][j][x]) {
          int v1 = x ? a[i - 1] : -a[i - 1];
          for (ri y = 0; y < 2; ++y) {
            int v2 = y ? a[i] : -a[i];
            if (v1 == v2) f[i][j][y] = 1, g[i][j][y] = pii(j, x);
            else if (v1 < v2) f[i][j - 1][y] = 1, g[i][j - 1][y] = pii(j, x);
            else f[i][j + 1][y] = 1, g[i][j + 1][y] = pii(j, x);
          }
        }
      }
    }
    for (ri dt = 0, ff = 0; !ff; ++dt) {
      ff = 0;
      for (ri x = 0; x < 2; ++x) {
        if (f[n][n + dt][x]) {
          dfs(n, n + dt, x);
          ff = 1;
          break;
        }
        if (f[n][n - dt][x]) {
          dfs(n, n - dt, x);
          ff = 1;
          break;
        }
      }
    }
    cout <<'\n';
  }
  return 0;
}