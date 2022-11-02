#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int d = 4, dx[d] = {1, 1, -1, -1}, dy[d] = {1, -1, -1, 1};
const int inf = 1e9;
const int maxn = 2e5 + 5, bdr = 10;
vector<vector<char>> s;
vector<vector<bool>> vis;
vector<vector<int>> fx;
vector<vector<int>> fy;
vector<vector<int>> dis;
struct node {
  int x, y, fx, fy;
  int dis;
};
bool operator<(node a, node b) { return a.dis > b.dis; }
priority_queue<node> que;
char tmp[maxn];
bool check(node u) {
  return !(s[u.x - 1][u.y] == '#' || s[u.x + 1][u.y] == '#' ||
           s[u.x][u.y - 1] == '#' || s[u.x][u.y + 1] == '#') &&
         s[u.x][u.y] != '$';
}
void spread(node u) {
  if (vis[u.x][u.y]) return;
  vis[u.x][u.y] = true;
  fx[u.x][u.y] = u.fx;
  fy[u.x][u.y] = u.fy;
  for (int i = 0; i < d; i++) {
    node v{u.x + dx[i], u.y + dy[i], u.x, u.y, u.dis};
    v.dis += s[v.x][v.y] == '.';
    if (check(v)) que.push(v);
  }
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    while (que.size()) que.pop();
    s.assign(n + bdr * 2, vector<char>(m + bdr * 2, '$'));
    vis.assign(n + bdr * 2, vector<bool>(m + bdr * 2, false));
    dis.assign(n + bdr * 2, vector<int>(m + bdr * 2, 0));
    fx.assign(n + bdr * 2, vector<int>(m + bdr * 2, -1));
    fy.assign(n + bdr * 2, vector<int>(m + bdr * 2, -1));
    for (int i = 0; i < n; i++) {
      scanf("%s", tmp);
      for (int j = 0; j < m; j++) {
        int x = i + bdr, y = j + bdr;
        s[x][y] = tmp[j];
      }
    }
    for (int i = 0; i < n; i++) {
      int x = i + bdr, y = m - 1 + bdr;
      node u = {x, y, -1, -1, (int)(s[x][y] == '.')};
      if (check(u)) que.push(u);
    }
    bool flg = true;
    while (que.size()) {
      auto u = que.top();
      que.pop();
      spread(u);
      if (u.y == bdr) {
        flg = false;
        break;
      }
    }
    int pos = -1, ans = inf;
    for (int i = 0; i < n; i++) {
      int x = i + bdr, y = bdr;
      if (vis[x][y] && dis[x][y] < ans) {
        ans = dis[x][y];
        pos = x;
      }
    }
    if (!~pos) {
      puts("NO");
      continue;
    }
    int x = pos, y = bdr;
    while (~x) {
      s[x][y] = '#';
      int p = fx[x][y], q = fy[x][y];
      x = p;
      y = q;
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) putchar(s[i + bdr][j + bdr]);
      puts("");
    }
  }
  return 0;
}