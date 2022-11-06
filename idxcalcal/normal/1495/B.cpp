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
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int n, a[N], L[N], R[N], l1[N], l2[N], ll1[N], ll2[N], lmx[N], rmx[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  a[0] = a[n + 1] = inf;
  for (ri i = 1; i <= n; ++i) a[i] = read(), L[i] = R[i] = i;
  for (ri i = 2; i <= n; ++i) if (a[i] < a[i - 1]) l1[i] = l1[i - 1] + 1;
  for (ri i = n - 1; i; --i) if (a[i] < a[i + 1]) l2[i] = l2[i + 1] + 1;
  for (ri i = 2; i <= n; ++i) l1[i] = max(l1[i], l1[i - 1]);
  for (ri i = n - 1; i; --i) l2[i] = max(l2[i], l2[i + 1]);
  for (ri i = 2; i <= n; ++i) if (a[i] > a[i - 1])
  ll1[i] = ll1[i - 1] + 1, L[i] = L[i - 1];
  for (ri i = n - 1; i; --i) if (a[i] > a[i + 1])
  ll2[i] = ll2[i + 1] + 1, R[i] = R[i + 1];
  for (ri i = 1; i <= n; ++i) lmx[i] = max(lmx[i - 1], ll1[i]);
  for (ri i = n; i; --i) rmx[i] = max(rmx[i + 1], ll2[i]);
  int res = 0;
  for (ri i = 1; i <= n; ++i) if (ll1[i] && ll2[i]) {
    int mx = max(ll1[i], ll2[i]);
    if (ll1[i] & 1) continue;
    if (ll1[i] != ll2[i]) continue;
    if (lmx[i - 1] >= mx || rmx[i + 1] >= mx) continue;
    if (l1[i - 1] >= mx || l2[i + 1] >= mx) continue;
    ++res;
  }
  cout << res;
  return 0;
}