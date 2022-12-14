#include <cstdio>
#include <algorithm>

const int N = 400 + 10, INF = 1 << 27;

int n, m;
int dist[N][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = m; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    dist[a][b] = dist[b][a] = 1;
  }
  if (dist[1][n]) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (!dist[i][j]) dist[i][j] = 1; else dist[i][j] = INF;
  } else {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (!dist[i][j]) dist[i][j] = INF;
  }
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (register int k = 1; k <= n; ++k)
    for (register int i = 1; i <= n; ++i)
      for (register int j = 1; j <= n; ++j)
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
  if (dist[1][n] < INF) printf("%d\n", dist[1][n]); else puts("-1");
  return 0;
}