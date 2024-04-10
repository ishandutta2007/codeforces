#include <cstdio>
#include <vector>

typedef long long i64;

const int N = 100000 + 10;

int n, id[N];

int f[N];
std::vector<int> adj[N], g[N], cnt[N];
std::vector<i64> sum[N];

int init() {
  int m, q;
  for (scanf("%d%d%d", &n, &m, &q); m--;) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  static int dep[N];
  std::vector<int> pool;
  auto bfs = [&] (int s) {
    int res = s;
    pool.clear();
    pool.push_back(s);
    static int fa[N];
    fa[s] = dep[s] = 0;
    for (int i = 0; i < pool.size(); ++i) {
      int a = pool[i];
      if (dep[a] > dep[res]) res = a;
      for (auto b : adj[a]) if (b != fa[a]) fa[b] = a, dep[b] = dep[a] + 1, pool.push_back(b);
    }
    return res;
  };
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (id[i]) continue;
    int s = bfs(i);
    ++tot;
    for (auto x : pool) id[x] = tot;
    int t = bfs(s);
    f[tot] = dep[t];
    static int temp[N];
    for (auto x : pool) temp[x] = dep[x];
    bfs(t);
    g[tot].resize(f[tot] + 1);
    for (auto x : pool) ++g[tot][std::max(temp[x], dep[x])];
    cnt[tot] = g[tot];
    for (int j = 1; j <= f[tot]; ++j) cnt[tot][j] += cnt[tot][j - 1];
    sum[tot].resize(f[tot] + 1);
    for (int j = 1; j <= f[tot]; ++j) sum[tot][j] = sum[tot][j - 1] + (i64)j * g[tot][j];
  }
  return q;
}

double solve(int u, int v) {
  double res = 0;
  int cur = std::max(f[u], f[v]);
  for (int i = 0; i <= f[u]; ++i) {
    int j = cur - 1 - i;
    int x = (j >= 0 ? cnt[v][j] : 0), y = cnt[v].back() - x;
    res += (double)g[u][i] * x * cur;
    res += (double)g[u][i] * y * (i + 1);
    res += (double)g[u][i] * (sum[v].back() - (j >= 0 ? sum[v][j] : 0));
  }
  return res / cnt[u].back() / cnt[v].back();
}

int main() {
  for (int q = init(); q--;) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = id[u], v = id[v];
    if (f[u] > f[v]) std::swap(u, v);
    printf("%.12f\n", u == v ? -1 : solve(u, v));
  }
  return 0;
}