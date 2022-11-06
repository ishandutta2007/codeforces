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
  const int mod = 1e9 + 7;
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
const int N = 1005;
int n, m, fac[N], ifac[N];
inline void init_fac() {
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (ri i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = Inv(fac[n]);
  for (ri i = n - 1; i > 1; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}
inline int C(int n, int m) { return n < m || m < 0 ? 0 : mul(fac[n], mul(ifac[m], ifac[n - m])); }
int f[N][N][2][2];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), m = read();
  init_fac();
  f[1][1][0][1] = f[1][0][0][0] = 1;
  for (ri i = 2; i <= n; ++i) {
    for (ri j = 0; j <= i; ++j) {
      if (j) {
        //ii-1 
        Add(f[i][j][1][0], f[i - 1][j - 1][0][1]);
        Add(f[i][j][0][0], f[i - 1][j - 1][0][0]);
        //ii+1
        if (i < n) {
          Add(f[i][j][1][1], f[i - 1][j - 1][0][1]);
          Add(f[i][j][1][1], f[i - 1][j - 1][1][1]);
          Add(f[i][j][0][1], f[i - 1][j - 1][0][0]);
          Add(f[i][j][0][1], f[i - 1][j - 1][1][0]);
        } 
      }
      //i 
      Add(f[i][j][1][0], f[i - 1][j][0][1]);
      Add(f[i][j][1][0], f[i - 1][j][1][1]);
      Add(f[i][j][0][0], f[i - 1][j][0][0]);
      Add(f[i][j][0][0], f[i - 1][j][1][0]);
    }
  }
  int res = 0;
  for (ri i = m; i <= n; ++i) {
    int t = mul(fac[n - i], mul(add(f[n][i][0][0], f[n][i][1][0]), C(i, m)));
    if ((i ^ m) & 1) Dec(res, t);
    else Add(res, t);
  }
  cout << res;
  return 0;
}