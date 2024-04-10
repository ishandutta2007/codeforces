#include <cstdio>
#include <bitset>
#include <algorithm>
#include <unordered_map>

const int N = 150 + 10, INF = 0x3f3f3f3f;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n, m, ans;

struct Edge {
  int x, y, z;
  inline bool operator< (const Edge &rhs) const {
    return z < rhs.z;
  }
} edge[N];

int stage[N], tot;

std::bitset<N> flag[4 * N * N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z), stage[i] = edge[i].z;
  stage[tot = m + 1] = 0;
  std::sort(stage + 1, stage + tot + 1);
  std::sort(edge + 1, edge + m + 1);
  tot = std::unique(stage + 1, stage + tot + 1) - stage - 1;
  ans = INF;
  flag[0][1] = 1;
  stage[tot + 1] = INF;
  for (int i = 1, r = 1, cur; i <= tot && (cur = stage[i]) <= ans; ++i) {
    while (r <= m && edge[r].z <= cur) ++r;
    int temp = std::min(2 * n * n + 10, stage[i + 1] - cur);
    for (int a = 1; a <= temp; ++a) flag[a].reset();
    for (int j = 0; j < temp; ++j)
      for (int k = 0; k < r; ++k)
        if (flag[j][edge[k].x]) flag[j + 1][edge[k].y] = 1;
    for (int j = 0; j <= temp; ++j) if (flag[j][n]) ans = std::min(ans, cur + j);
    if (temp + cur == stage[i + 1]) {
      flag[0] = flag[temp];
      continue;
    }
    std::unordered_map<std::bitset<N>, int> pool;
    for (int j = 0; j <= temp; ++j) {
      if (pool.count(flag[j])) {
        int a = pool[flag[j]], b = j, c = b - a;
        cur += a;
        int det = stage[i + 1] - cur;
        flag[0] = flag[a + det % c];
        break;
      }
      pool[flag[j]] = j;
    }
  }
  if (ans == INF) puts("Impossible"); else printf("%d\n", ans);
  return 0;
}