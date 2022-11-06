#include <bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
#define pb push_back
#define rez resize
#define ppp pop_back
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans, f;
  static char ch;
  for (ans = 0, f = 1, ch = gc(); !isdigit(ch); ch = gc()) f ^= ch == '-';
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return f ? ans : -ans;
}
namespace modular {
  const int mod = 1e9 + 7;
  int ret;
  inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
  inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) { for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1); return ret; }
  inline int Inv(int a) { return ksm(a, mod - 2); }
}  using namespace modular;
const int N = 3005;
int n, m, f[N][N], C[N][N], ifac[N];
vector <int> e[N];
void dfs(int p) {
  for (ri i = 1; i <= n; ++i) f[p][i] = 1;
  for (ri i = 0, v; i < e[p].size(); ++i) {
    dfs(v = e[p][i]);
    for (ri j = 1; j <= n; ++j) Mul(f[p][j], f[v][j]);
  }
  for (ri i = 1; i <= n; ++i) Add(f[p][i], f[p][i - 1]);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), m = read();
  for (ri i = 2, u, v; i <= n; ++i) e[read()].pb(i);
  dfs(1);
  for (ri i = n; i; --i) Dec(f[1][i], f[1][i - 1]);
  for (ri i = 0; i <= n; ++i) for (ri j = C[i][0] = 1; j <= i; ++j) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
  int fac = 1;
  for(ri i = 1; i <= n; ++i) Mul(fac, i);
  ifac[n] = Inv(fac), ifac[0] = ifac[1] = 1;
  for (ri i = n - 1; i > 1; --i) ifac[i] = mul(ifac[i + 1], i + 1);
  int res = 0;
  for (ri i = 1; i <= n && i <= m; ++i) {
    int mt = ifac[i], &g = f[1][i];
    for (ri j = m - i + 1; j <= m; ++j) Mul(mt, j);
    for (ri j = 1; j < i; ++j) Dec(g, mul(C[i - 1][j - 1], f[1][j]));
    Add(res, mul(mt, g));
  }
  cout << res;
  return 0;
}