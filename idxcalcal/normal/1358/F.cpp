#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define ri register int
#define ptf printf
using namespace std;
typedef double db;
typedef long double ld;
typedef long long ll;
typedef vector <int> poly;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef unsigned long long ulll;
typedef unsigned int uii;
typedef string strr;
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
const ll Inf = 2e18;
const int rlen = 1 << 20, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib =  buf) + fread(buf, 1, rlen, stdin)), ib == ob) ? -1 : *ib++)
inline int read() {
  static int ans, f;
  static char ch;
  ans = 0, ch = gc(), f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) ans = (ans << 3) + (ans << 1) + (ch ^ 48), ch = gc();
  return f ? ans: -ans;
}
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
inline int Read(char *s) {
  static int top;
  static char ch;
  top = 0, ch = gc();
  while (!isalpha(ch) && !isdigit(ch)) ch = gc();
  while (isalpha(ch) || isdigit(ch)) s[++top] = ch, ch = gc();
  return top;
}
namespace modular {
  const int mod = 998244353;//= 1e9 + 7;
  //int mod;
  int ret;
  inline int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
  inline void Dec(int &a, int b) { a = a < b? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) {
    for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
    return ret;
  }
  inline int Inv(int a) { return ksm(a, mod - 2); }
  inline int sqr(int a) { return (ll) a * a % mod; }
  inline int cub(int a) { return (ll) a * a % mod * a % mod; }
} using namespace modular;
template <typename T> inline void ckmax(T &a, T b) { a < b ? a = b : 0; }
template <typename T> inline void ckmin(T &a, T b) { a > b ? a = b : 0; }
template <typename T> inline T Abs(T a) { return a < 0 ? -a : a; }
template <typename T> inline T gcd(T a, T b) {
  T t;
  while (b) t = a, a = b, b = t - t / a * a;
  return a;
}
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a - a / b * b, y, x);
  y -= a / b * x;
}
const int N = 1e6 + 5;
ll a[N], b[N];
int n;
inline bool ck1() {
  for (ri i = 2; i <= n; ++i) if (a[i] < a[i - 1]) return 0;
  return 1;
}
inline bool ck2() {
  for (ri i = 1; i < n; ++i) if (a[i] < a[i + 1]) return 0;
  return 1;
}
inline bool ck3() {
  for (ri i = 1; i <= n; ++i) if (a[i] != b[i]) return 0;
  return 1;
}
inline bool ck4() {
  for (ri i = 1; i <= n; ++i) if (a[i] != b[n - i + 1]) return 0;
  return 1;
}
stack <char> stk;
inline void check1() {
  if (ck3()) {
    if (stk.size() > 200000) {
      puts("BIG");
      int res = 0;
      while (stk.size()) res += stk.top() == 'P', stk.pop();
      cout << res;
      exit(0);
    }
    puts("SMALL");
    cout << stk.size() << '\n';
    while (stk.size()) cout << stk.top(), stk.pop();
    exit(0);
  }
  if (ck4()) {
    stk.push('R');
    if (stk.size() > 200000) {
      puts("BIG");
      int res = 0;
      while (stk.size()) res += stk.top() == 'P', stk.pop();
      cout << res;
      exit(0);
    }
    puts("SMALL");
    cout << stk.size() << '\n';
    while (stk.size()) cout << stk.top(), stk.pop();
    exit(0);
  }
}
inline void check2() {
  if (!ck1() && !ck2()) {
    puts("IMPOSSIBLE");
    exit(0);
  }
  for (ri i = 1; i <= n; ++i) if (!a[i]) {
    puts("IMPOSSIBLE");
    exit(0);
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 1; i <= n; ++i) b[i] = readl();
  for (ri i = 1; i <= n; ++i) a[i] = readl();
  if (n == 1) {
    if (a[1] == b[1]) {
      puts("SMALL");
      cout << 0 << '\n';
      return 0;
    }
    puts("IMPOSSIBLE");
    return 0;
  }
  if (n == 2) {
    stack <pair<char, ll> > q;
    ll ss = 0, sss = 0;
    while (1) {
      if (a[1] == b[1] && a[2] == b[2]) {
        if (ss > 200000) {
          puts("BIG");
          cout << sss;
          exit(0);
        }
        else {
          puts("SMALL");
          cout << ss << '\n';
          while (q.size()) {
            for (ri i = 1; i <= q.top().se; ++i) cout << q.top().fi;
            q.pop();
          }
          exit(0);
        }
      }
      if (a[1] == b[2] && a[2] == b[1]) {
        q.push(make_pair('R', 1));
        ++ss;
        if (ss > 200000) {
            puts("BIG");
            cout << sss;
            exit(0);
            }
          else {
            puts("SMALL");
            cout << ss << '\n';
            while (q.size()) {
              for (ri i = 1; i <= q.top().se; ++i) cout << q.top().fi;
              q.pop();
            }
            exit(0);
          }
      }
      if (!a[1] || !a[2] ) {
        puts("IMPOSSIBLE");
        exit(0);
      }
      if (a[1] > a[2]) {
        q.push(make_pair('R', 1));
        ++ss;
        swap(a[1], a[2]);
      }
      bool rev = 0;
      if (b[1] > b[2]) rev ^= 1, swap(b[1], b[2]);
      if (a[1] < b[1] || a[2] < b[2]) {
        puts("IMPOSSIBLE");
        exit(0);
      }
      if ((a[2] - b[2]) % a[1] == 0) {
        q.push(make_pair('P', (a[2] - b[2]) / a[1]));
        ss += (a[2] - b[2]) / a[1];
        sss += (a[2] - b[2]) / a[1];
        a[2] = b[2];
      }
      else {
        rev ^= 1, swap(b[1], b[2]);
        if ((a[2] - b[2]) % a[1] == 0) {
          q.push(make_pair('P', (a[2] - b[2]) / a[1]));
          ss += (a[2] - b[2]) / a[1];
          sss += (a[2] - b[2]) / a[1];
          a[2] = b[2];
        }
        else {
          q.push(make_pair('P', a[2] / a[1]));
          ss += a[2] / a[1];
          sss += a[2] / a[1];
          a[2] %= a[1];
        }
      }
      if (rev) swap(b[1], b[2]);
    }
    return 0;
  }
  while (1) {
    check1();
    check2();
    if (ck1()) {
      for (ri i = n; i > 1; --i) a[i] -= a[i - 1];
      stk.push('P');
    }
    else {
      reverse(a + 1, a + n + 1);
      for (ri i = n; i > 1; --i) a[i] -= a[i - 1];
      stk.push('R');
      stk.push('P');
    }
  }
  return 0;
}