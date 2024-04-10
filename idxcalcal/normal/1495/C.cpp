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
#define gc() getchar()//(((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
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
const int N = 505;
int n, m;
char s[N][N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read(), m = read();
    for (ri i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for (ri i = 1; i <= n; i += 3) {
      for (ri j = 1; j <= m; ++j) s[i][j] = 'X';
      if (i + 2 < n) {
        int ps1 = 0, ps2 = 0;
        for (ri j = 1; j <= m; ++j) {
          if (s[i + 1][j] == 'X') {
            ps1 = j;
            break;
          }
        }
        for (ri j = 1; j <= m; ++j) {
          if (s[i + 2][j] == 'X') {
            ps2 = j;
            break;
          }
        }
        if (!ps1 && !ps2) {
          s[i + 1][1] = s[i + 2][1] = 'X';
          continue;
        }
        if (ps1) {
          s[i + 2][ps1] = 'X';
          continue;
        }
        s[i + 1][ps2] = 'X';
      }
        if (i + 2 == n) {
        int ps1 = 0, ps2 = 0;
        for (ri j = 1; j <= m; ++j) {
          if (s[i + 1][j] == 'X') {
            ps1 = j;
            break;
          }
        }
        for (ri j = 1; j <= m; ++j) {
          if (s[i + 2][j] == 'X') {
            ps2 = j;
            break;
          }
        }
        if (!ps1) {
          for (ri j = 1; j <= m; ++j) {
            s[i + 2][j] = 'X';
          }
          s[i + 1][1] = 'X';
          continue;
        }
        if (!ps2) continue;
        for (ri j = 1; j <= ps1; ++j) s[i + 2][j] = 'X';
        for (ri j = ps1 + 1, pre = ps1; j <= m; ++j) {
          if (s[i + 2][j] == 'X') {
            for (ri k = pre; k <= j; ++k) s[i + 2][k] = 'X';
            pre = j;
          }
          if (s[i + 1][j] == 'X') pre = j;
        }
      }
    }
    for (ri i = 1; i <= n; ++i) {
      for (ri j = 1; j <= m; ++j) cout << s[i][j];
      puts("");
    }
  }
  return 0;
}