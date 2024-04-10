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
int n;
char s[N], t[N];
bool trans[26][26];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  for (ri tt = read(); tt; --tt) {
    n = read();
    scanf("%s", s + 1), scanf("%s", t + 1);
    bool ff = 1;
    memset(trans, 0, sizeof(trans));
    for (ri i = 1; i <= n; ++i) if (s[i] != t[i]) {
      if (s[i] > t[i]) ff = 0;
      else trans[s[i] - 'a'][t[i] - 'a'] = 1;
    }
    if (!ff) { puts("-1"); continue; }
    int ct = 0;
    for (ri i = 0; i < 26; ++i) for (ri j = i + 1; j < 26; ++j) if (trans[i][j]) {
      ++ct;
      for (ri k = j; k < 26; ++k) if (trans[i][k]) trans[j][k] = 1, trans[i][k] = 0;
    }
    cout << ct << '\n';
  }
  return 0;
}