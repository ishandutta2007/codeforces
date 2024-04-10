#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
inline int Read(char *s) {
  static int top;
  static char ch;
  for (top = 0, ch = gc(); !isdigit(ch) && !isalpha(ch); ch = gc());
  while (isdigit(ch) || isalpha(ch)) {
    s[++top] = ch;
    ch = gc();
  }
  return top;
}
typedef long long ll;
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
typedef vector <int> poly;
#define pb push_back
#define rez resize
#define ppp pop_back
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
}
namespace modular {
  const int mod = 998244353;
  int ret;
  inline int add(int a, int b) {
    return a < mod - b ? a + b : a - mod + b;
  }
  inline int dec(int a, int b) {
    return a < b ? a - b + mod : a - b;
  }
  inline int mul(int a, int b) {
    return (ll) a * b % mod;
  }
  inline void Add(int &a, int b) {
    a = a < mod - b ? a + b : a - mod + b;
  }
  inline void Dec(int &a, int b) {
    a = a < b ? a - b + mod : a - b;
  }
  inline void Mul(int &a, int b) {
    a = (ll) a * b % mod;
  }
  inline int ksm(int a, int p) {
    for (ret = 1; p; p >>= 1, Mul(a, a)) {
      (p & 1) && (Mul(ret, a), 1);
    }
    return ret;
  }
  inline int fix(int x) {
    x <= -mod || x >= mod ? x %= mod : 0;
    return x < 0 ? x + mod : x;
  }
  inline int Inv(int a) {
    static int x, y;
    exgcd(a, mod, x, y);
    return fix(x);
  }
}  using namespace modular;
template <typename T> inline void ckmin(T &a, T b) {
  a > b ? a = b : 0;
}
template <typename T> inline void ckmax(T &a, T b) {
  a < b ? a = b : 0;
}
template <typename T> inline T gcd(T a, T b) {
  T t;
  while (b) {
    t = a;
    a = b;
    b = t - t / a * a;
  }
  return a;
}
template <typename T> inline T Abs(T x) {
  return x < 0 ? -x : x;
}
const int N = 1e5 + 5;
int n, D, m, a[N], b[N], c[N], t1, t2;
ll s1[N], s2[N];
int main() {
  #ifdef JSLover
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  D = read();
  m = read();
  vector <int> q1, q2;
  for (ri i = 1, x; i <= n; ++i) {
    a[i] = read();
  }
  sort(a + 1, a + n + 1);
  t1 = t2 = 0;
  for (ri i = 1; i <= n; ++i) {
    if (a[i] <= m) {
      s1[++t1] = a[i];
    } else {
      s2[++t2] = a[i];
    }
  }
  for (ri i = t1; i; --i) {
    s1[i] += s1[i + 1];
  }
  for (ri i = t2; i; --i) {
    s2[i] += s2[i + 1];
  }
  ll ans = 0;
  for (ri i = 0; i <= t2; ++i) {
    ll tp = max(0ll, (ll) (D + 1) * (i - 1) + 1);
    if (tp > n) {
      break;
    }
    ckmax(ans, s1[max(1ll, t1 - (n - tp) + 1)] + s2[t2 - i + 1]);
  }
  cout << ans;
  return 0;
}