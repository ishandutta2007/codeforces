#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 505, maxm = 2.5e5 + 5;
int dis[maxn][maxn];
int u[maxm], v[maxm];
ll w[maxm];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(dis[0], dis[n + 1], maxn);
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%lld", &u[i], &v[i], &w[i]);
      dis[u[i]][v[i]] = dis[v[i]][u[i]] = 1;
    }
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    ll ans = inf;
    for (int i = 0; i < m; i++) {
      int d = min(dis[u[i]][1] + dis[v[i]][n], dis[v[i]][1] + dis[u[i]][n]) + 1;
      for (int k = 1; k <= n; k++)
        d = min(d, min(dis[u[i]][k], dis[v[i]][k]) + dis[k][1] + dis[k][n] + 2);
      // d = min(d, dis[u[i]][1] + dis[u[i]][n] + 2);
      // d = min(d, dis[v[i]][1] + dis[v[i]][n] + 2);
      ans = min(ans, d * w[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}