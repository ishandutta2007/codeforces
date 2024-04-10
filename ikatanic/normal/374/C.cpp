#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1010;
const int inf = 1e9;

char a[MAXN][MAXN];
int f[MAXN][MAXN];
int color[MAXN][MAXN];

int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

enum {BLACK, GRAY, WHITE};

char niz[] = "DIMA";

void dfs(int x, int y) {
  f[x][y] = 0;
  color[x][y] = GRAY;
  
  char next;
  REP(i, 4)
    if (a[x][y] == niz[i]) {
      next = niz[(i+1)%4];
      break;
    }

  REP(k, 4) {
    int X = x+dx[k], Y = y+dy[k];
    if (X < 0 || X >= n || Y < 0 || Y >= m || a[X][Y] != next) continue;
    if (color[X][Y] == GRAY) { f[x][y] = inf; break; }
    if (color[X][Y] == BLACK) dfs(X, Y);
    f[x][y] = max(f[x][y], f[X][Y]);
  }
  if (a[x][y] == 'A') f[x][y]++;
  
  color[x][y] = WHITE;
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  
  int ans = 0;
  REP(i, n) REP(j, m)
    if (a[i][j] == 'D') {
      if (color[i][j] == BLACK) dfs(i, j);
      ans = max(ans, f[i][j]);
    }

  if (ans == 0) puts("Poor Dima!"); else
    if (ans >= inf) puts("Poor Inna!"); else
      printf("%d\n", ans);
  return 0;
}