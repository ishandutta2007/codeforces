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
typedef unsigned long long ulll;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans, f;
  static char ch;
  for (ch = gc(), f = 1; !isdigit(ch); ch = gc()) f ^= ch == '-';
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return f ? ans : -ans;
}
inline ll readl() {
  static ll ans;
  static int f;
  static char ch;
  for (ch = gc(), f = 1; !isdigit(ch); ch = gc()) f ^= ch == '-';
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return f ? ans : -ans;
}
inline int read(char *s) {
  static int len;
  static char ch;
  for (ch = gc(); !isalpha(ch); ch = gc());
  for (len = 0; isalpha(ch); s[++len] = ch, ch = gc());
  return len;
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
    for (ret = 1; p; p >>= 1, Mul(a, a)) { (p & 1) && (Mul(ret, a), 1); }
    return ret;
  }
  inline int Inv(int a) { return ksm(a, mod - 2); }
}  using namespace modular;
const int N = 3e5 + 5;
int n, a[N];
vector <int> e[N];
int f[N], du[N], d;
bool ff;
void dfs(int p, int ft) {
  if (!ff) return;
  for (ri i = 0, v; i < e[p].size(); ++i) if ((v = e[p][i]) ^ ft) dfs(v, p);
  if (du[p] % d) {
    if (ft) ++du[p];
    if (du[p] % d) return (void) (ff = 0);
  } else ++du[ft];
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    for (ri i = 1; i <= n; ++i) {
      e[i].clear();
    }
    for (ri i = 1, u, v; i < n; ++i) {
      u = read();
      v = read();
      e[u].pb(v);
      e[v].pb(u);
    }
    for (ri i = 1; i <= n; ++i) f[i] = 0;
    f[1] = ksm(2, n - 1);
    for (d = 2; d < n; ++d) {
      if ((n - 1) % d) continue;
      ff = 1;
      for (ri i = 1; i <= n; ++i) du[i] = 0;
      dfs(1, 0);
      f[d] = ff;
    }
    for (ri i = n; i; --i) for (ri j = (i << 1); j <= n; j += i) Dec(f[i], f[j]);
    for (ri i = 1; i <= n; ++i) cout << f[i] << (i == n ? '\n' : ' ');
  }
  return 0;
}