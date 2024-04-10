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
const int N = 1e6 + 5;
inline void cl() {
  ;
}
int n, a[N], L[N], R[N], top = 0, stk[N], vl[N], sig;
inline int solve(int l, int r, int v) {
  static int pre[N], suf[N];
  pre[l - 1] = suf[r + 1] = 0;
  for (ri i = l; i <= r; ++i) pre[i] = max(0, pre[i - 1] + a[i]);
  for (ri i = r; i >= l; --i) suf[i] = max(0, suf[i + 1] + a[i]);
  int res = 0;
  for (ri i = l; i <= r; ++i) if (a[i] == v) ckmax(res, pre[i - 1] + suf[i + 1]);
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = 1, x, y; tt; --tt) {
    cl();
    n = read();
    for (ri i = 1; i <= n; ++i) a[i] = read(), vl[i] = a[i];
    sort(vl + 1, vl + n + 1), sig = unique(vl + 1, vl + n + 1) - vl - 1;
    top = 0, stk[top] = 0;
    for (ri i = 1; i <= n; ++i) {
      while (top && a[stk[top]] < a[i]) --top;
      stk[++top] = i;
      L[i] = stk[top] + 1;
    }
    top = 0, stk[top] = n + 1;
    for (ri i = n; i; --i) {
      while (top && a[stk[top]] <= a[i]) --top;
      stk[++top] = i;
      R[i] = stk[top] - 1;
    }
    int ans = 0;
    for (ri vll = 1; vll <= sig; ++vll) {
      for (ri l = 1, r; l <= n; l = r + 1) {
        bool ff = 0;
        r = l;
        if (a[l] > vl[vll]) continue;
        if (a[l] == vl[vll]) ff = 1;
        while (r < n && a[r + 1] <= vl[vll]) {
          ++r;
          if (a[r] ==vl[vll]) ff = 1;
        }
        if (ff) ckmax(ans, solve(l, r, vl[vll]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}