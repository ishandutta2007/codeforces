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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
int n, m, k;

int h[maxn];

struct edges {
  int nxt, to;
} E[maxn << 2];

void addline(int u, int v) {
  static int ecnt = 1;
  E[++ecnt] = edges{h[u], v}, h[u] = ecnt;
}

namespace Tree {
  vector <int> vec[2];

  void dfs(int u, int f, int d) {
    vec[d].push_back(u);
    for (int i = h[u]; i; i = E[i].nxt) {
      int v = E[i].to;
      if (v != f) dfs(v, u, d ^ 1);
    }
  }

  void solve() {
    dfs(1, 0, 0);
    if (vec[0].size() < vec[1].size()) {
      swap(vec[0], vec[1]);
    }
    puts("1");
    rep(i, 0, (k + 1) / 2 - 1) printf("%d ", vec[0][i]);
  }
}

vector <int> cir;
int chk, top, st[maxn], vis[maxn];

void dfs(int u, int f) {
  vis[u] = 2;
  st[++top] = u;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (v != f && vis[v] == 2) {
      chk = 2;
      per(i, top, 1) {
        cir.push_back(st[i]);
        if (st[i] == v) return;
      }
    }
  }
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (v != f && !vis[v]) {
      dfs(v, u);
      if (chk) return;
    }
  }
  vis[u] = 1, top--;
}

void solve() {
  cin >> n >> m >> k;
  rep(i, 1, m) {
    int u = read(), v = read();
    addline(u, v), addline(v, u);
  }
  if (m == n - 1) {
    Tree::solve(); return;
  }
  dfs(1, 0);
  if ((int) cir.size() > k) chk = 1;
  printf("%d\n", chk);
  if (chk == 1) {
    int now = 0;
    for (int i = 0; i < (int) cir.size(); i += 2) {
      printf("%d ", cir[i]);
      if (++now == (k + 1) / 2) break;
    }
  } else {
    printf("%d ", (int) cir.size());
    for (int x : cir) printf("%d ", x);
  }
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}