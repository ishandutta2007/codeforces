#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
inline int Read(char *s) {
  static int top;
  static char ch;
  for (top = 0, ch = gc(); !isdigit(ch) && !isalpha(ch); ch = gc());
  while (isdigit(ch) || isalpha(ch)) {
    s[++top] = ch;
    ch = gc();
  }
  return top;
}
typedef long long ll;
typedef vector <int> poly;
#define pb push_back
#define rez resize
#define ppp pop_back
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
}
namespace modular {
  const int mod = 1e9 + 7;
  int ret;
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
    for (ret = 1; p; p >>= 1, Mul(a, a)) {
      (p & 1) && (Mul(ret, a), 1);
    }
    return ret;
  }
  inline int fix(int x) {
    x <= -mod || x >= mod ? x %= mod : 0;
    return x < 0 ? x + mod : x;
  }
  inline int Inv(int a) {
    static int x, y;
    exgcd(a, mod, x, y);
    return fix(x);
  }
}  using namespace modular;
const int N = 1e6 + 5;
int n, son[N][2], nxt[N][2], pos[N], l0[N], f[N];
char s[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = Read(s);
  int l1 = 0, l2 = 0;
  while (s[n] == '0') {
    ++l2;
    --n;
  }
  if (!n) {
    cout << l2;
    return 0;
  }
  int st = 1;
  while (s[st] == '0') {
    ++l1;
    ++st;
  }
  int tot = 0;
  for (ri i = st; i <= n; ++i) {
    s[++tot] = s[i];
  }
  n = tot;
  int lst = n + 1;
  for (ri i = n; ~i; --i) {
    nxt[i][1] = lst;
    if (s[i] == '1') {
      lst = i;
    }
  }
  for (ri i = 1; i <= n; ++i) {
    l0[i] = s[i] == '0' ? l0[i - 1] + 1 : 0;
  }
  for (ri i = 0; i <= n; ++i) {
    pos[i] = n + 1;
  }
  for (ri i = n; ~i; --i) {
    nxt[i][0] = pos[l0[i] + 1];
    pos[l0[i]] = i;
  }
  f[1] = 1;
  for (ri i = 1; i <= n; ++i) {
    for (ri j = 0; j < 2; ++j) {
      Add(f[nxt[i][j]], f[i]);
    }
  }
  int res = 0;
  for (ri i = 1; i <= n; ++i) {
    if (s[i] == '1') {
      Add(res, f[i]);
    }
  }
  cout << mul(res, mul(l1 + 1, l2 + 1));
  return 0;
}