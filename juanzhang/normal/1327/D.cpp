#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 2e5 + 10;
int n, a[maxn], col[maxn];

bool vis[maxn];
int tot, data[maxn];

int check(int len) {
  rep(st, 1, len) {
    bool flg = 1;
    for (int i = st + len; i <= tot; i += len) {
      flg &= col[data[i]] == col[data[i - len]];
    }
    if (flg) return len;
  }
  return 1e9;
}

void solve() {
  rep(i, 1, n) vis[i] = 0;
  cin >> n;
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) col[i] = read();
  int res = 1e9;
  rep(u, 1, n) if (!vis[u]) {
    vis[u] = 1, data[tot = 1] = u;
    for (int v = a[u]; u != v; v = a[v]) {
      vis[v] = 1, data[++tot] = v;
    }
    int lim = sqrt(tot) + 0.5;
    rep(len, 1, lim) if (tot % len == 0) {
      chkmin(res, min(check(len), check(tot / len)));
    }
  }
  printf("%d\n", res);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}