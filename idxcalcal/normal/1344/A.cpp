#include <bits/stdc++.h>
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
const ll Inf = 1e18;
const int rlen = 1 << 20, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin)), ib == ob) ? -1 : *ib++)
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
const int N = 1e6 + 5;
vector <int> pt[N];
int n, cnt[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  int tt = 1;
  tt = read();
  for (; tt; --tt) {
    n = read();
    for (ri i = 0; i < n; ++i) {
      int t = ((i + read()) % n + n) % n;
      ++cnt[t];
    }
    bool ff =  1;
    for (ri i = 0; i < n; ++i) {
      if (cnt[i] != 1) ff = 0;
      cnt[i] = 0;
    }
    puts(ff ? "YES" : "NO");
  }
  return 0;
}