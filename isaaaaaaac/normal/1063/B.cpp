#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

const int N = 2010;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

struct node {
  int x, y, s, t;
  node() {}
  node(int _x, int _y, int _s, int _t) : x(_x), y(_y), s(_s), t(_t) {}
};

int n, m, sx, sy, L, R, ans;
char G[N][N];
deque <node> Q;
bool vis[N][N];

int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &sx, &sy);
  scanf("%d%d", &L, &R);
  for (int i = 1; i <= n; i ++) scanf("%s", G[i] + 1);
  ans = 1;
  Q.push_back(node(sx, sy, 0, 0));
  vis[sx][sy] = 1;
  node c;
  while (Q.size()) {
    c = Q.front(); Q.pop_front();
    int x = c.x, y = c.y, nx, ny, ss, tt;
    for (int i = 0; i < 4; i ++) {
      nx = x + dx[i];
      ny = y + dy[i];
      if (G[nx][ny] != '.' || vis[nx][ny]) continue;
      ss = c.s; tt = c.t;
      if (dy[i] == -1) ss ++;
      else if (dy[i] == 1) tt ++;
      if (ss > L || tt > R) continue;
      vis[nx][ny] = 1;
      ans ++;
      if (dy[i] == 0) Q.push_front(node(nx, ny, ss, tt));
      else Q.push_back(node(nx, ny, ss, tt));
    }
  }
  printf("%d\n", ans);
  return 0;
}