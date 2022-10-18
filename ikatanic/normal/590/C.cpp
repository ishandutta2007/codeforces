#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;
const int inf = 1e8;

char a[MAX][MAX];
int d[3][MAX][MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  
  REP(i, 3) {
    REP(x, n) REP(y, m) d[i][x][y] = inf;
    
    queue<int> Q;
    REP(x, n) REP(y, m)
      if (a[x][y] == i + '1') {
        Q.push(x); Q.push(y);
        d[i][x][y] = 0;
      }

    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      int y = Q.front(); Q.pop();

      static int dx[] = {0, 1, 0, -1};
      static int dy[] = {1, 0, -1, 0};
      REP(k, 4) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
        if (d[i][x][y] + 1 < d[i][nx][ny]) {
          d[i][nx][ny] = d[i][x][y] + 1;
          Q.push(nx); Q.push(ny);
        }
      }
    }
  }


  int ans = inf;
  REP(x, n) REP(y, m) {
    if (a[x][y] != '.') continue;
    int cost = 1;
    REP(i, 3) cost += d[i][x][y]-1;
    ans = min(ans, cost);
  }

  int f[3][3];
  REP(i, 3) REP(j, 3) {
    f[i][j] = inf;
    REP(x, n) REP(y, m)
      if (a[x][y] == j + '1') f[i][j] = min(f[i][j], d[i][x][y]-1);
  }
  
  ans = min(ans, f[0][1] + f[0][2]);
  ans = min(ans, f[0][1] + f[1][2]);
  ans = min(ans, f[0][2] + f[2][1]);

  printf("%d\n", ans > inf/2 ? -1 : ans);
  return 0;
}