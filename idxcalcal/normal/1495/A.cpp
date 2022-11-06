#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define rez resize
#define ppp pop_back
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> poly;
typedef pair <poly, poly> P;
typedef unsigned long long ulll;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans, f;
  static char ch;
  for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return f ? ans : -ans;
}
inline ll readl() {
  static ll ans;
  static int f;
  static char ch;
  for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return f ? ans : -ans;
}
namespace modular {
  const int mod = 998244353;
  inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
  inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) {
    static int ret;
    for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
    return ret;
  }
  inline int Inv(int a) { return ksm(a, mod - 2); }
}  using namespace modular;
const int N = 1e5 + 5;
int a[N], b[N], n;
inline double sqr(ll x) { return x * x; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    int ct1 = 0, ct2 = 0;
    for (ri i = 1, x; i <= n * 2; ++i) {
      x = read();
      if (!x) {
        a[++ct1] = read();
        if (a[ct1] < 0) a[ct1] *= -1;
      } else {
        read();
        b[++ct2] = x;
        if (b[ct2] < 0) b[ct2] *= -1;
      }
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    double ans = 0;
    for (ri i = 1; i <= n; ++i) ans += sqrt(sqr(a[i]) + sqr(b[i]));
    printf("%.10lf\n", ans);
  }
  return 0;
}