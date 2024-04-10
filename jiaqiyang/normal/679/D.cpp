#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 400 + 10, M = N * N;

int n, m, a[M], b[M];

bool adj[N][N];
int dist[N][N], deg[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &a[i], &b[i]);
  memset(dist, 0x3f, sizeof dist);
  for (int i = 1; i <= m; ++i) {
    adj[a[i]][b[i]] = adj[b[i]][a[i]] = 1;
    dist[a[i]][b[i]] = dist[b[i]][a[i]] = 1;
    ++deg[a[i]], ++deg[b[i]];
  }
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
  double ans = 0.;
  for (int i = 1; i <= n; ++i) {
    static int id[N];
    for (int j = 1; j <= n; ++j) id[j] = j;
    std::sort(id + 1, id + n + 1, [&] (int a, int b) { return dist[i][a] < dist[i][b]; });
    double cur = 0.;
    for (int l = 1; l <= n;) {
      int r = l;
      while (r <= n && dist[i][id[r]] == dist[i][id[l]]) ++r;
      static double prob[N];
      for (int j = 1; j <= n; ++j) prob[j] = 0.;
      for (int j = l; j < r; ++j) {
        int a = id[j];
        for (int b = 1; b <= n; ++b) if (adj[a][b]) prob[b] += 1. / n / deg[a];
      }
      std::vector<int> temp;
      for (int j = 1; j <= n; ++j) if (prob[j]) temp.push_back(j);
      double x = 1. / n;
      for (int j = 1; j <= n; ++j) {
        std::sort(temp.begin(), temp.end(), [&] (int a, int b) { return dist[j][a] < dist[j][b]; });
        double y = 0.;
        for (int k = 0; k < temp.size();) {
          int t = k;
          while (t < temp.size() && dist[j][temp[t]] == dist[j][temp[k]]) ++t;
          double z = 0.;
          for (int p = k; p < t; ++p) z = std::max(z, prob[temp[p]]);
          y += z;
          k = t;
        }
        x = std::max(x, y);
      }
      cur += x;
      l = r;
    }
    ans = std::max(ans, cur);
  }
  printf("%.10f\n", ans);
  return 0;
}