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
 
const int N = 2e5 +5, inf = 0x3f3f3f3f;
int n, m, cal[N], ss[N], ps[N];
pii a[N];
bool sta[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = 1; tt; --tt) {
    n = read();
    int res = 0;
    for (ri i = 1; i <= n; ++i) {
      a[i].fi = ps[i] = read();
      a[i].se = read();
      sta[i] = read();
      int t = lower_bound(ps + 1, ps + i, a[i].se) - ps - 1;
      cal[i] = a[i].fi - a[i].se;
      while (t < i && ps[t] < a[i].se) {
        ++t;
      }
      if (t < i) {
        Add(cal[i], dec(ss[i - 1], ss[t - 1]));
      }
      ss[i] = add(ss[i - 1], cal[i]);
      Add(res, a[i].fi - a[i - 1].fi);
      if (sta[i]) {
        Add(res, cal[i]);
      }
    }
    Add(res, 1);
    cout << res << '\n';
  }
  return 0;
}