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
const int N = 405;
int n, m, d[N][N];
pii E[N << 1];
vector <int> e[N];
inline void init(int s) {
  static int que[N], hd, tl;
  que[hd = tl = 1] = s;
  d[s][s] = 0;
  while (hd <= tl) {
    int x = que[hd++];
    for (ri i = 0, v; i < e[x].size(); ++i) {
      v = e[x][i];
      if (d[s][v] > d[s][x] + 1) {
        d[s][v] = d[s][x] + 1;
        que[++tl] = v;
      }
    }
  }
}
bool vs[N];
int res[N][N], du[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), m = read();
  memset(d, 0x3f, sizeof(d));
  for (ri i = 1; i <= m; ++i) {
    E[i].fi = read();
    E[i].se = read();
    e[E[i].fi].pb(E[i].se);
    e[E[i].se].pb(E[i].fi);
  }
  for (ri i = 1; i <= n; ++i) init(i);
  for (ri a = 1; a <= n; ++a) for (ri b = 1; b <= n; ++b) {
    for (ri i = 0; i <= n; ++i) vs[i] = du[i] = 0;
    int ct = 0;
    bool ff = 1;
    for (ri c = 1; c <= n; ++c) {
      if (d[a][c] + d[c][b] == d[a][b]) {
        if (!vs[d[a][c]]) vs[d[a][c]] = 1;
        else {
          ff = 0;
          break;
        }
      }
    }
    if (!ff) continue;
    for (ri i = 1, u, v; i <= m; ++i) {
      u = E[i].fi, v = E[i].se;
      if (d[u][a] == d[v][a] + 1 && d[u][b] == d[v][b] + 1) ++du[u];
      if (d[v][a] == d[u][a] + 1 && d[v][b] == d[u][b] + 1) ++du[v];
    }
    res[a][b] = 1;
    for (ri i = 1; i <= n; ++i) if (d[i][a] + d[i][b] != d[a][b]) Mul(res[a][b], du[i]);
  }
  for (ri i = 1; i <= n; ++i) {
    for (ri j = 1; j <= n; ++j) cout << res[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}