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
const int maxn = 1010;
int n;
int rt, len;

vector <int> E[maxn], vec[maxn];

int maxd, fa[maxn], dep[maxn];

void dfs(int u, int f) {
  fa[u] = f;
  chkmax(maxd, dep[u]);
  vec[dep[u]].push_back(u);
  for (int v : E[u]) if (v != f) {
    dep[v] = dep[u] + 1, dfs(v, u);
  }
}

typedef pair <int, int> pii;
pii ans[maxn];

pii query(int dep) {
  assert(!vec[dep].empty());
  if (ans[dep].first != 0) return ans[dep];
  printf("? %d ", (int) vec[dep].size());
  for (int u : vec[dep]) printf("%d ", u);
  puts("");
  fflush(stdout);
  int x, d;
  scanf("%d %d", &x, &d);
  if (x == -1 || d == -1) assert(0);
  return ans[dep] = pii(x, d);
}

void solve() {
  scanf("%d", &n);
  memset(ans, 0, sizeof ans);
  rep(i, 0, n) E[i].clear(), vec[i].clear();
  rep(i, 2, n) {
    int u, v;
    scanf("%d %d", &u, &v);
    E[u].push_back(v), E[v].push_back(u);
  }
  printf("? %d ", n);
  rep(i, 1, n) printf("%d ", i);
  puts("");
  fflush(stdout);
  scanf("%d %d", &rt, &len);
  maxd = dep[rt] = 0, dfs(rt, 0);
  int l = (len - 1) / 2 + 1, r = min(len, maxd), pos = rt;
  while (l <= r) {
    int mid = (l + r) >> 1;
    pii p = query(mid);
    p.second == len ? pos = p.first, l = mid + 1 : r = mid - 1;
  }
//  pii p = query(r);
//  int pos = p.first;
//  assert(p.second == len);
  int tmp = len - dep[pos];
  static bool vis[maxn];
  memset(vis, 0, sizeof vis);
  for (int u = pos; u; u = fa[u]) {
    vis[u] = 1;
  } 
  vector <int> seq;
  for (int u : vec[tmp]) if (!vis[u] || u == rt) seq.push_back(u);
  if (seq.empty()) assert(0);
  printf("? %d ", (int) seq.size());
  for (int u : seq) printf("%d ", u);
  puts("");
  fflush(stdout);
  int x, d;
  scanf("%d %d", &x, &d);
  assert(d == len);
  if (x == -1) assert(0);
  printf("! %d %d\n", pos, x);
  fflush(stdout);
  char data[15];
  scanf("%s", data);
  if (*data != 'C') assert(0);
  fflush(stdout);
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}