#include <bits/stdc++.h>
#define ri register int
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
const ll Inf = 1e18;
const int rlen = 1 << 20, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() getchar()//(((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin)), ib == ob) ? -1 : *ib++)
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
  const int mod = 998244353;
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
  if (a == 1) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
const int N = 900;
bool vs[N];
int n, a[N], ps[N];
vector <vector <int> > mod3, mod5, mod7;
vector <int> coe3, coe5, coe7, dt3, dt5, dt7;
inline void prt() {
  for (ri i = 1; i <= n; ++i) a[ps[i]] = i;
  if (a[1] > n / 2) for (ri i = 1; i <= n; ++i) a[i] = n + 1 - a[i];
  cout << "! ";
  for (ri i = 1; i <= n; ++i) {
    cout << a[i];
    if (i == n) cout << endl;
    else cout << ' ';
  }
  exit(0);
}
inline int getinv(int vl, int md) {
  int x, y;
  exgcd(vl, md, x, y);
  return (x % md + md) % md;
}
inline void init() {
  vector <int> tmp;
  // mod 3;
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2);
  mod3.pb(tmp), coe3.pb(0), dt3.pb(0);
  tmp.rez(0);
  tmp.pb(2), tmp.pb(3);
  mod3.pb(tmp), coe3.pb(0), dt3.pb(1);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(3);
  mod3.pb(tmp), coe3.pb(0), dt3.pb(2);
  // mod 5;
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(n - 1), tmp.pb(n);
  mod5.pb(tmp), coe5.pb(3), dt5.pb(3);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(3), tmp.pb(n - 1), tmp.pb(n);
  mod5.pb(tmp), coe5.pb(3), dt5.pb(2);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(4), tmp.pb(n - 1), tmp.pb(n);
  mod5.pb(tmp), coe5.pb(3), dt5.pb(1);
  tmp.rez(0);
  tmp.pb(2), tmp.pb(4), tmp.pb(n - 1), tmp.pb(n);
  mod5.pb(tmp), coe5.pb(3), dt5.pb(0);
  tmp.rez(0);
  tmp.pb(3), tmp.pb(4), tmp.pb(n - 1), tmp.pb(n);
  mod5.pb(tmp), coe5.pb(3), dt5.pb(4);
  //mod 7;
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(3), tmp.pb(n - 2), tmp.pb(n - 1), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(4);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(3), tmp.pb(n - 3), tmp.pb(n - 1), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(5);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(3), tmp.pb(n - 3), tmp.pb(n - 2), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(6);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(3), tmp.pb(n - 3), tmp.pb(n - 2), tmp.pb(n - 1);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(0);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(2), tmp.pb(4), tmp.pb(n - 2), tmp.pb(n - 1), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(3);
  tmp.rez(0);
  tmp.pb(1), tmp.pb(3), tmp.pb(4), tmp.pb(n - 2), tmp.pb(n - 1), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(2);
  tmp.rez(0);
  tmp.pb(2), tmp.pb(3), tmp.pb(4), tmp.pb(n - 2), tmp.pb(n - 1), tmp.pb(n);
  mod7.pb(tmp), coe7.pb(4), dt7.pb(1);
}
inline int get2(int pos) {
  cout << "? " << "2 " << ps[1] << ' ' << pos << endl;
  return read();
}
namespace Math {
  int a1, a2, a3, a4;
  int M;
  int c1, c2, c3, c4;
  inline void init() {
    a1 = 3, a2 = 5, a3 = 7, a4 = 8;
    M = 840;
    c1 = getinv(M / a1, a1) * M / a1;
    c2 = getinv(M / a2, a2) * M / a2;
    c3 = getinv(M / a3, a3) * M / a3;
    c4 = getinv(M / a4, a4) * M / a4;
  }
  inline int CRT(int b1, int b2, int b3, int b4) {
    int res = (c1 * b1 + c2 * b2 + c3 * b3 + c4 * b4) % M;
    return res ? res : M;
  }
};
inline void getvl(int pos) {
  cout << "? " << "2 " << ps[1] << ' ' << pos << endl;
  int m3, m5, m7, m8;
  if (read()) {// = 2x + 1;
    cout << "? " << "4 " << ps[1] << ' ' << ps[2] << ' ' << ps[4] << ' ' << pos << endl;
    if (read()) { // = 4x + 1;
      cout << "? " << "8 " << ps[2] << ' ' << ps[3] << ' ' << ps[4] << ' ' << ps[n - 3] << ' ' << ps[n - 2] << ' ' << ps[n - 1] << ' ' << ps[n] << ' ' << pos << endl;
      if (read()) m8 = 5;
      else m8 = 1;
    }
    else { // = 4x + 3;
      cout << "? " << "8 " << ps[1] << ' ' << ps[2] << ' ' << ps[4] << ' ' << ps[n - 3] << ' ' << ps[n - 2] << ' ' << ps[n - 1] << ' ' << ps[n] << ' ' << pos << endl;
      if (read()) m8 = 7;
      else m8 = 3;
    }
  }
  else {// = 2x;
    cout << "? " << "4 " << ps[1] << ' ' << ps[3] << ' ' << ps[4] << ' ' << pos << endl;
    if (read()) { // = 4x;
      cout << "? " << "8 " << ps[1] << ' ' << ps[2] << ' ' << ps[3] << ' ' << ps[n - 3] << ' ' << ps[n - 2] << ' ' << ps[n - 1] << ' ' << ps[n] << ' ' << pos << endl;
      if (read()) m8 = 0;
      else m8 = 4;
    }
    else { // = 4x + 2;
      cout << "? " << "8 " << ps[1] << ' ' << ps[3] << ' ' << ps[4] << ' ' << ps[n - 3] << ' ' << ps[n - 2] << ' ' << ps[n - 1] << ' ' << ps[n] << ' ' << pos << endl;
      if (read()) m8 = 6;
      else m8 = 2;
    }
  }
  for (ri i = 0; i < mod3.size(); ++i) {
    cout << "? " << "3 ";
    cout << ps[mod3[i][0]] << ' ' << ps[mod3[i][1]] << ' ' << pos << endl;
    if (read()) {
      m3 = (coe3[i] * n + dt3[i]) % 3;
      break;
    }
  }
  for (ri i = 0; i < mod5.size(); ++i) {
    cout << "? " << "5 ";
    cout << ps[mod5[i][0]] << ' ' << ps[mod5[i][1]] << ' ' << ps[mod5[i][2]] << ' ' << ps[mod5[i][3]] << ' ' << pos << endl;
    if (read()) {
      m5 = (coe5[i] * n + dt5[i]) % 5;
      break;
    }
  }
  for (ri i = 0; i < mod7.size(); ++i) {
    cout << "? " << "7 ";
    for (ri j = 0; j < 6; ++j) cout << ps[mod7[i][j]] << ' ';
    cout << pos << endl;
    if (read()) {
      m7 = (coe7[i] * n + dt7[i]) % 7;
      break;
    }
  }
  ps[Math:: CRT(m3, m5, m7, m8)] = pos;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  bool ff = 1;
  for (ri i = 1; i <= n; ++i) {
    cout << "? " << n - 1 << ' ';
    int ct = 0;
    for (ri j = 1; j <= n; ++j) if (i ^ j) {
      ++ct;
      cout << j;
      if (ct == n - 1) cout << endl;
      else cout << ' '; 
    }
    if (read()) {
      if (ff) {
        ps[1] = i;
        ff = 0;
      }
      else {
        ps[n] = i;
        break;
      }
    }
  }
  vs[ps[1]] = vs[ps[n]] = 1;
  if (n == 2) prt();
  ff = 1;
  for (ri i = 1; i <= n; ++i) if (!vs[i]) {
    cout << "? " << n - 3 << ' ';
    int ct = 0;
    for (ri j = 1; j <= n; ++j) if (i != j && !vs[j]) {
      ++ct;
      cout << j;
      if (ct == n - 3) cout << endl;
      else cout << ' '; 
    }
    if (read()) {
      if (ff) {
        ps[2] = i;
        ff = 0;
      }
      else {
        ps[n - 1] = i;
        break;
      }
    }
  }
  vs[ps[2]] = vs[ps[n - 1]] = 1;
  cout << "? " << 2 << ' ' << ps[1] << ' ' << ps[2] << endl;
  if (read()) swap(ps[n - 1], ps[2]);
  if (n == 4) prt();
  ff = 1;
  for (ri i = 1; i <= n; ++i) if (!vs[i]) {
    cout << "? " << n - 5 << ' ';
    int ct = 0;
    for (ri j = 1; j <= n; ++j) if (i != j && !vs[j]) {
      ++ct;
      cout << j;
      if (ct == n - 5) cout << endl;
      else cout << ' '; 
    }
    if (read()) {
      if (ff) {
        ps[3] = i;
        ff = 0;
      }
      else {
        ps[n - 2] = i;
        break;
      }
    }
  }
  vs[ps[3]] = vs[ps[n - 2]] = 1;
  cout << "? " << 2 << ' ' << ps[2] << ' ' << ps[3] << endl;
  if (read()) swap(ps[n - 2], ps[3]);
  if (n == 6) prt();
  ff = 1;
  for (ri i = 1; i <= n; ++i) if (!vs[i]) {
    cout << "? " << n - 7 << ' ';
    int ct = 0;
    for (ri j = 1; j <= n; ++j) if (i != j && !vs[j]) {
      ++ct;
      cout << j;
      if (ct == n - 7) cout << endl;
      else cout << ' '; 
    }
    if (read()) {
      if (ff) {
        ps[4] = i;
        ff = 0;
      }
      else {
        ps[n - 3] = i;
        break;
      }
    }
  }
  vs[ps[4]] = vs[ps[n - 3]] = 1;
  cout << "? " << 2 << ' ' << ps[3] << ' ' << ps[4] << endl;
  if (read()) swap(ps[n - 3], ps[4]);
  if (n == 8) prt();
  Math:: init();
  init();
  for (ri i = 1; i <= n; ++i) if (!vs[i]) getvl(i);
  prt();
  return 0;
}