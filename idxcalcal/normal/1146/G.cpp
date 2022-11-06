#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define rez resize
#define pb push_back
#define ppp pop_back
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() getchar()//(((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
typedef long long ll;
typedef vector <int> poly;
typedef pair <ll, int> pli;
typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
inline int read() {
  static int ans, f;
  static char ch;
  for (ch = gc(), f = 1; !isdigit(ch); ch = gc(), f ^= ch == '-');
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return f ? ans : -ans;
}
namespace modular {
  const int mod = 998244353;
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
    static int ret;
    for (ret = 1; p; p >>= 1, Mul(a, a)) {
      (p & 1) && (Mul(ret, a), 1);
    }
    return ret;
  }
}  using namespace modular;
const int N = 55;
int f[N][N][N], n, m, h, L[N], R[N], X[N], C[N];
inline int dp(int l, int r, int vl) {
  if (~f[l][r][vl]) {
    return f[l][r][vl];
  }
  if (l > r || !vl) {
    return f[l][r][vl] = 0;
  }
  if (l == r) {
    int res = vl * vl;
    for (ri i = 1; i <= m; ++i) {
      if (L[i] == l && R[i] == l && X[i] < vl) {
        res -= C[i];
      }
    }
    return f[l][r][vl] = max(res, dp(l, r, vl - 1));
  }
  int res = 0, cal;
  for (ri p = l; p <= r; ++p) {
    cal = dp(l, p - 1, vl - 1) + dp(p + 1, r, vl) + vl * vl;
    for (ri i = 1; i <= m; ++i) {
      if (l <= L[i] && R[i] <= r && L[i] <= p && p <= R[i] && vl > X[i]) {
        cal -= C[i];
      }
    }
    res = max(res, cal);
  }
  return f[l][r][vl] = max(res, dp(l, r, vl - 1));
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  h = read();
  m = read();
  for (ri i = 1; i <= m; ++i) {
    L[i] = read();
    R[i] = read();
    X[i] = read();
    C[i] = read();
  }
  memset(f, -1, sizeof(f));
  cout << dp(1, n, h);
  return 0;
}