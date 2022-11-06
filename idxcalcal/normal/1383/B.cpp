#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() getchar()
#define rez resize
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
typedef long long ll;
typedef vector <int> poly;
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) { x = 1, y = 0; return; }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
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
  inline int fix(int x) {
    x <= -mod || x >= mod ? x %= mod : 0;
    return x < 0 ? x + mod : x;
  }
  inline int Inv(int a) {
    static int x, y;
    return exgcd(a, mod, x, y), fix(x);
  }
}  using namespace modular;
const int N = 1e5 + 5;
int n, a[N], cnt[32];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    for (ri i = 0; i <= 30; ++i) cnt[i] = 0;
    int S = 0;
    for (ri i = 1; i <= n; ++i) {
      a[i] = read();
      S ^= a[i];
      for (ri j = 0; j <= 30; ++j) if (a[i] >> j & 1) ++cnt[j];
    }
    int ff = -1;
    for (ri i = 30; ~i; --i) {
      if (cnt[i] & 1) {
        int rev = ((cnt[i] + 1) / 2) & 1;
        if (rev || !(n & 1)) {
          ff = 1;
          break;
        }
        else {
          ff = 0;
          break;
        }
      }
    }
    if (ff < 0) puts("DRAW");
    else if (ff == 1) puts("WIN");
    else puts("LOSE");
  }
  return 0;
}