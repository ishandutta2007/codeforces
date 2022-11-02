#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 3e5 + 5, bdr = 10;
ll p, q;
struct node {
  int x, y, b;
  ll v;
};
priority_queue<node> que;
vector<vector<char>> s;
vector<vector<bool>> vis;
// vector<vector<int>> cntp;
// vector<vector<int>> cntq;
vector<vector<int>> bel;
vector<vector<ll>> dis;
// ll eval(node a) { return cntp[a.x][a.y] * p + cntq[a.x][a.y] * q; }
bool operator<(node a, node b) { return a.v > b.v; }
char ts[maxn];
void spread(node u) {
  if (vis[u.x][u.y]) return;
  vis[u.x][u.y] = true;
  bel[u.x][u.y] = u.b;
  dis[u.x][u.y] = u.v;
  // vis[u.x] = true;
  // vis[u.y] = true;
  switch (s[u.x - 1][u.y]) {
    case 'D':
      que.push({u.x - 2, u.y, u.b, u.v + q});
      break;
    case 'R':
      que.push({u.x - 1, u.y - 1, u.b, u.v + p});
      break;
    case 'L':
      que.push({u.x - 1, u.y + 1, u.b, u.v + p});
      break;
  }
  switch (s[u.x + 1][u.y]) {
    case 'U':
      que.push({u.x + 2, u.y, u.b, u.v + q});
      break;
    case 'R':
      que.push({u.x + 1, u.y - 1, u.b, u.v + p});
      break;
    case 'L':
      que.push({u.x + 1, u.y + 1, u.b, u.v + p});
      break;
  }
  switch (s[u.x][u.y - 1]) {
    case 'R':
      que.push({u.x, u.y - 2, u.b, u.v + q});
      break;
    case 'D':
      que.push({u.x - 1, u.y - 1, u.b, u.v + p});
      break;
    case 'U':
      que.push({u.x + 1, u.y - 1, u.b, u.v + p});
      break;
  }
  switch (s[u.x][u.y + 1]) {
    case 'L':
      que.push({u.x, u.y + 2, u.b, u.v + q});
      break;
    case 'D':
      que.push({u.x - 1, u.y + 1, u.b, u.v + p});
      break;
    case 'U':
      que.push({u.x + 1, u.y + 1, u.b, u.v + p});
      break;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%lld%lld", &p, &q);
  vector<int> a;
  s.assign(n + bdr * 2, vector<char>(m + bdr * 2, '#'));
  vis.assign(n + bdr * 2, vector<bool>(m + bdr * 2, false));
  bel.assign(n + bdr * 2, vector<int>(m + bdr * 2, 0));
  dis.assign(n + bdr * 2, vector<ll>(m + bdr * 2, 0LL));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", ts);
    for (int j = 0; j < m; j++) {
      s[i + bdr][j + bdr] = ts[j];
      if (ts[j] == '.') {
        int x = i + bdr, y = j + bdr;
        que.push({x, y, ++cnt, 0LL});
      }
    }
  }
  while (que.size()) {
    auto nd = que.top();
    que.pop();
    spread(nd);
  }
  ll ans = inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x = i + bdr, y = j + bdr;
      if (!vis[x][y]) continue;
      if (vis[x - 1][y]) ans = min(ans, dis[x][y] + dis[x - 1][y]);
      if (vis[x + 1][y]) ans = min(ans, dis[x][y] + dis[x + 1][y]);
      if (vis[x][y - 1]) ans = min(ans, dis[x][y] + dis[x][y - 1]);
      if (vis[x][y + 1]) ans = min(ans, dis[x][y] + dis[x][y + 1]);
    }
  printf("%lld\n", ans < inf / 2 ? ans : -1);
  return 0;
}