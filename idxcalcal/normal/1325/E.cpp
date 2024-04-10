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
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
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
  const int mod = 1e9 + 7;
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
const int N = 1e6 + 5, B = 1000;
int n, a[N];
int cnt[N], ct[N], tim, dep[N], fa[N];
vector <int> e[N];
int mn = 0x3f3f3f3f;
void bfs(int s) {
  queue <int> q;
  q.push(s);
  ct[s] = tim;
  dep[s] = 0;
  fa[s] = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (ri i = 0, v; i < e[p].size(); ++i) {
      v = e[p][i];
      if (ct[v] == ct[p]) {
        if (v != fa[p]) {
          mn = min(dep[p] + dep[v] + 1, mn);
        }
        continue;
      }
      fa[v] = p;
      ct[v] = tim;
      dep[v] = dep[p] + 1;
      q.push(v);
    }
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  bool f1 = 0, f2 = 0;
  for (ri i = 1; i <= n; ++i) {
    a[i] = read();
    vector <int> ps;
    ps.rez(0);
    for (ri j = 2; j * j <= a[i]; ++j) {
      while (a[i] == a[i] / (j * j) * (j * j)) {
        a[i] /= j * j;
      }
      if (a[i] == a[i] / j * j) {
        ps.pb(j);
        a[i] /= j;
      }
    }
    if (a[i] > 1) {
      ps.pb(a[i]);
    }
    if (!ps.size()) {
      f1 = 1;
      break;
    }
    if (ps.size() == 1) {
      if (cnt[ps.back()]) {
        f2 = 1;
      }
      ++cnt[ps.back()];
      e[1].pb(ps[0]);
      e[ps[0]].pb(1);
      continue;
    }
    if (cnt[ps[0] * ps[1]]) {
      f2 = 1;
    }
    ++cnt[ps[0] * ps[1]];
    e[ps[0]].pb(ps[1]);
    e[ps[1]].pb(ps[0]);
  }
  if (f1) {
    cout << "1";
    return 0;
  }
  if (f2) {
    cout << "2";
    return 0;
  }
  dep[0] = -1;
  for (ri i = 1; i <= B; ++i) {
    tim = i;
    bfs(i);
  }
  if (mn == 0x3f3f3f3f) {
    cout << "-1";
  } else {
    cout << mn;
  }
  return 0;
}