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
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
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
typedef pair <int, int> pii;
typedef vector <int> poly;
typedef double db;
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
namespace modular {
  const int mod = 1e9 + 7;
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
}  using namespace modular;
const int N = 305;
int n, m, a[N], b[N];
ll K;
inline poly operator * (poly a, poly b) {
  int n = a.size(), m = b.size(), t = n + m - 1;
  poly c(t);
  for (ri i = 0; i < n; ++i) {
    if (a[i]) {
      for (ri j = 0; j < m; ++j) {
        Add(c[i + j], mul(a[i], b[j]));
      }
    }
  }
  return c;
}
poly md;
inline poly operator % (poly a, poly b) {
  if (a.size() < b.size()) {
    return a;
  }
  int n = a.size(), m = b.size();
  for (ri t, i = n - 1; i >= m - 1; --i) {
    t = a[i];
    for (ri x = i, y = m - 1; ~y; --x, --y) {
      Dec(a[x], mul(b[y], t));
    }
  }
  a.rez(b.size() - 1);
  return a;
}
inline poly getpw(poly a, ll K) {
  poly res(1, 1);
  for (; K; K >>= 1, a = a * a % md) {
    if (K & 1) {
      res = res * a % md;
    }
  }
  return res;
}
inline void operator += (poly &a, poly b) {
  int n = b.size();
  if (a.size() < n) {
    a.rez(n);
  }
  for (ri i = 0; i < n; ++i) {
    Add(a[i], b[i]);
  }
}
int f[N];
inline void init_DP() {
  f[0] = 1;
  for (ri i = 1; i <= b[m]; ++i) {
    for (ri j = 1; j <= m && i >= b[j]; ++j) {
      Add(f[i], f[i - b[j]]);
    }
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  m = read();
  K = readl();
  for (ri i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (ri i = 1; i <= m; ++i) {
    b[i] = read();
  }
  sort(b + 1, b + m + 1);
  init_DP();
  md.rez(b[m] + 1);
  md[b[m]] = 1;
  for (ri i = 1; i <= m; ++i) {
    Dec(md[b[m] - b[i]], 1);
  }
  poly ss, tp(2, 1);
  tp[0] = 0;
  for (ri i = 1; i <= n; ++i) {
    ss += getpw(tp, a[i]);
  }
  ss = getpw(ss, K);
  int res = 0;
  for (ri i = 0; i < b[m]; ++i) {
    Add(res, mul(f[i], ss[i]));
  }
  cout << res;
  return 0;
}