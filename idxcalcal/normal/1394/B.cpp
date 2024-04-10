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
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
typedef vector <int> poly;
typedef pair <int, int> pii;
#define fi first
#define se second
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
  const int mod = 998244353;
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
template <typename T> inline void ckmin(T &a, T b) {
  a > b ? a = b : 0;
}
template <typename T> inline void ckmax(T &a, T b) {
  a < b ? a = b : 0;
}
template <typename T> inline T gcd(T a, T b) {
  T t;
  while (b) {
    t = a;
    a = b;
    b = t - t / a * a;
  }
  return a;
}
template <typename T> inline T Abs(T x) {
  return x < 0 ? -x : x;
}
const int N = 2e5 + 5;
int n, m, K, Noo[15][15], res = 0, ban[15][15][15][15], cnt[N][15][15], a[15];
vector <pii> e[N];
void dfs(int p) {
  if (p > K) {
    for (ri i = 1; i <= K; ++i) {
      for (ri j = i + 1; j <= K; ++j) {
        if (ban[i][a[i]][j][a[j]]) {
          return;
        }
      }
    }
    ++res;
  } else {
    for (ri i = 1; i <= p; ++i) {
      if (!Noo[p][i]) {
        bool ff = 1;
        for (ri j = 1; j < p; ++j) {
          if (ban[p][i][j][a[j]]) {
            ff = 0;
            break;
          }
        }
        if (ff) {
          a[p] = i;
          dfs(p + 1);
        }
      }
    }
  }
}
int main() {
  #ifdef JSLover
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  m = read();
  K = read();
  for (ri i = 1, u, v, w; i <= m; ++i) {
    u = read();
    v = read();
    w = read();
    e[u].pb(pii(w, v));
  }
  for (ri i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
    for (ri j = 0; j < e[i].size(); ++j) {
      int v = e[i][j].se;
      ++cnt[v][e[i].size()][j + 1];
    }
  }
  for (ri p = 1; p <= n; ++p) {
    vector <pii> tp;
    for (ri i = 1; i <= K; ++i) {
      for (ri j = 1; j <= i; ++j) {
        if (cnt[p][i][j] >= 2) {
          Noo[i][j] = 1;
          continue;
        }
        if (cnt[p][i][j] == 1) {
          tp.pb(pii(i, j));
        }
      }
    }
    sort(tp.begin(), tp.end());
    tp.erase(unique(tp.begin(), tp.end()), tp.end());
    for (ri i = 0; i < tp.size(); ++i) {
      for (ri j = i + 1; j < tp.size(); ++j) {
        ban[tp[i].fi][tp[i].se][tp[j].fi][tp[j].se] = 1;
        ban[tp[j].fi][tp[j].se][tp[i].fi][tp[i].se] = 1;
      }
    }
  }
  dfs(1);
  cout << res;
  return 0;
}