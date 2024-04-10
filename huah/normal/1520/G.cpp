#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
#define mp(x, y) make_pair(x, y)
void ast(ll x, ll l, ll r) { assert(x >= l && x <= r); }
const int N = 2e3 + 5;
int n, m, w, a[N][N];
ll dis[2][N][N];
queue<pair<int, int> > q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void bfs(int sx, int sy, ll dis[N][N]) {
  q.push(mp(sx, sy));
  dis[sx][sy] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == -1 ||
          dis[nx][ny] != dis[0][0])
        continue;
      dis[nx][ny] = dis[x][y] + 1;
      q.push(mp(nx, ny));
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int k = 0; k < 2; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) dis[k][i][j] = inf;
  bfs(1, 1, dis[0]);
  bfs(n, m, dis[1]);
  ll ans = inf;
  if (dis[0][n][m] != dis[0][0][0]) ans = min(ans, dis[0][n][m] * w);
  ll mn[2];
  mn[0] = mn[1] = inf;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= 1; k++)
        if (dis[k][i][j] != dis[k][0][0] && a[i][j])
          mn[k] = min(mn[k], dis[k][i][j] * w + a[i][j]);
  ans = min(ans, mn[0] + mn[1]);
  if (ans == inf) ans = -1;
  printf("%lld\n", ans);
}