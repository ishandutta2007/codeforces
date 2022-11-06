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

const int N = 205, inf = 0x3f3f3f3f;
int n, m;
pii a[N];
bool vs[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    m = read();
    for (ri i = 1; i <= 2 * n; ++i) {
      vs[i] = 0;
    }
    for (ri i = 1; i <= m; ++i) {
      a[i] = pii(read(), read());
      if (a[i].se < a[i].fi) {
        swap(a[i].fi, a[i].se);
      }
      vs[a[i].fi] = vs[a[i].se] = 1;
    }
    int sz = m, ct = 0;
    for (ri i = 1; i <= n * 2; ++i) {
      if (!vs[i]) {
        ++ct;
        if (ct <= n - m) {
          a[ct + m].fi = i;
        } else {
          a[ct + m - (n - m)].se = i;
        }
      }
    }
    ct /= 2;
    sz += ct;
    sort(a + 1, a + sz + 1);
    int ans = 0;
    for (ri i = 1; i <= sz; ++i) {
      for (ri j = 1; j < i; ++j) {
        if (a[j].se > a[i].fi && a[i].se > a[j].se) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}