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

const int maxn = 2010;
int n, rt, fa[maxn], sz[maxn], cnt[maxn];

vector <int> e[maxn], vec[maxn];

void dfs(int u) {
  sz[u] = 1;
  for (int v : e[u]) {
    dfs(v);
    sz[u] += sz[v];
    for (int x : vec[v]) vec[u].push_back(x);
  }
  if (cnt[u] >= sz[u]) {
    puts("NO"); exit(0);
  }
  vec[u].insert(vec[u].begin() + cnt[u], u);
}

int main() {
  n = read();
  rep(i, 1, n) {
    fa[i] = read(), cnt[i] = read();
    if (fa[i]) {
      e[fa[i]].push_back(i);
    } else {
      rt = i;
    }
  }
  dfs(rt);
  puts("YES");
  int cur = 0;
  static int ans[maxn];
  for (int x : vec[rt]) {
    ans[x] = ++cur;
  }
  rep(i, 1, n) printf("%d ", ans[i]);
  return 0;
}