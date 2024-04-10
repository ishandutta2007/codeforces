#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Pair;

const int N = 1000 + 10;

int n, m;

struct Info {
  int in, out, w, s, v;
  inline bool operator< (const Info &rhs) const {
    int a = out - in, b = rhs.out - rhs.in;
    return a > b;
  }
} info[N];

int f[N][N];

std::vector<Pair> adj[N];

void solve(int s) {
  for (int i = n; i >= 0; --i) {
    if (s > info[i].s) continue;
    int l = info[i].in, r = info[i].out;
    for (int j = 0; j <= m; ++j) adj[j].clear();
    for (int j = 1; j <= n; ++j) {
      int t = std::min(s - info[j].w, info[j].s);
      if (t >= 0) adj[info[j].out].push_back(Pair(info[j].in, f[t][j] + info[j].v));
    }
    static int g[N];
    g[l - 1] = 0;
    for (int j = l; j <= r; ++j) {
      g[j] = g[j - 1];
      for (int k = adj[j].size() - 1; k >= 0; --k) {
        int a = adj[j][k].first, b = adj[j][k].second;
        if (a < l) break;
        if (j == r && a == l) continue;
        g[j] = std::max(g[j], g[a] + b);
      }
    }
    f[s][i] = g[r];
  }
}

int main() {
  scanf("%d%d", &n, &info[0].s);
  info[0].in = 1;
  m = info[0].out = 2 * n + 1;
  for (int i = 1; i <= n; ++i) scanf("%d%d%d%d%d", &info[i].in, &info[i].out, &info[i].w, &info[i].s, &info[i].v), ++info[i].in, ++info[i].out;
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      assert(!(info[i].in == info[j].in && info[i].out == info[j].out));
  std::sort(info + 1, info + n + 1);
  for (int i = 0; i <= info[0].s; ++i) solve(i), ans = std::max(ans, f[i][0]);
  printf("%d\n", ans);
  return 0;
}