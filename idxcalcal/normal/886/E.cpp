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
#define hhh cout << '\n';
#define dhhh cerr << '\n';
#define jhhh cout << endl;
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
  const int mod = 1e9 + 7;
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
int n, K, fac[N], ifac[N], inv[N], ss[N], f[N];
inline void init_fac() {
  fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
  for (ri i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = Inv(fac[n]), inv[n] = mul(ifac[n], fac[n - 1]);
  for (ri i = n - 1; i > 1; --i) {
    ifac[i] = mul(ifac[i + 1], i + 1);
    inv[i] = mul(ifac[i], fac[i - 1]);
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), K = read();
  init_fac();
  int res = fac[n];
  f[0] = ss[0] = 1;
  for (ri i = 1; i <= n; ++i) {
    f[i] = mul(fac[i - 1], dec(ss[i - 1], i >= K + 1 ? ss[i - K - 1] : 0));
    ss[i] = add(ss[i - 1], mul(f[i], ifac[i]));
  }
  cout << dec(res, mul(fac[n - 1], ss[n - 1]));
  return 0;
}