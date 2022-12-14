#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

const int N = 200000 + 10, INF = 0x3f3f3f3f;

int n, m, x[N], y[N];

std::pair<int, int> edge[N];

int fa[N], dep[N];
std::vector<int> adj[N];

void dfs(int a) {
  for (auto b : adj[a]) if (b != fa[a]) fa[b] = a, dep[b] = dep[a] + 1, dfs(b);
}

class {
  int anc[N];
 public:
  int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }
  void clear() { std::iota(anc, anc + n + 1, 0); }
  inline void meld(int x, int y) {
    anc[find(x)] = find(y);
  }
  inline bool check(int x, int y) { return find(x) == find(y); }
} dsu[2];

int p[N], q[N], cur[N];

bool res[N];
int tag[N];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int z;
    scanf("%d%d%d", &x[i], &y[i], &z);
    edge[i] = {z, i};
  }
  std::sort(edge + 1, edge + m + 1);
  dsu[0].clear();
  for (int i = 1; i <= m; ++i) {
    int j = edge[i].second, a = x[j], b = y[j];
    if (dsu[0].check(a, b)) continue;
    dsu[0].meld(a, b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    tag[j] = 1;
  }
  dep[1] = 1, dfs(1);
  for (int i = 1; i <= m; ++i) if (tag[i]) tag[i] = (fa[x[i]] == y[i] ? x[i] : y[i]);
  std::fill(p + 1, p + m + 1, 0);
  std::fill(q + 1, q + m + 1, INF);
}

bool flag[N];

void mark(int a, int b) {
  while ((a = dsu[1].find(a)) != (b = dsu[1].find(b))) {
    if (dep[a] < dep[b]) std::swap(a, b);
    flag[a] = true;
    dsu[1].meld(a, fa[a]);
    a = dsu[1].find(a);
  }
}

void solve() {
  static std::pair<int, int> pool[N];
  for (int i = 1; i <= m; ++i) pool[i] = {cur[i], i};
  std::sort(pool + 1, pool + m + 1);
  dsu[0].clear();
  dsu[1].clear();
  std::fill(flag, flag + n + 1, false);
  for (int i = 1, j = 1; i <= m; ++i) {
    for (; j <= m && edge[j].first <= pool[i].first; ++j) {
      int k = edge[j].second;
      if (tag[k]) dsu[0].meld(x[k], y[k]); else mark(x[k], y[k]);
    }
    int k = pool[i].second;
    res[k] = (!dsu[0].check(x[k], y[k]) || (tag[k] && !flag[tag[k]]));
  }
}

int main() {
  init();
  for (int i = 37; i--;) {
    for (int j = 1; j <= m; ++j) cur[j] = (p[j] + q[j] + 1) >> 1;
    solve();
    for (int j = 1; j <= m; ++j) if (res[j]) p[j] = cur[j]; else q[j] = cur[j] - 1;
  }
  for (int i = 1; i <= m; ++i) printf("%d ", p[i] >= INF ? -1 : p[i]);
  return 0;
}