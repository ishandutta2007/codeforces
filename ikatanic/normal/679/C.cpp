#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 505;
const int MAXC = MAX*MAX;

char a[MAX][MAX];
bool bio[MAX][MAX];
int comp[MAX][MAX];
int compsz[MAXC];
int minx[MAXC], maxx[MAXC];
int miny[MAXC], maxy[MAXC];

int n, k;

void dfs(int x, int y, int c) {
  if (bio[x][y]) return;

  bio[x][y] = true;
  compsz[c]++;
  comp[x][y] = c;

  minx[c] = min(minx[c], x);
  maxx[c] = max(maxx[c], x);
  miny[c] = min(miny[c], y);
  maxy[c] = max(maxy[c], y);
  
  static int dx[] = {1, 0, -1, 0};
  static int dy[] = {0, 1, 0, -1};
  
  REP(k, 4) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (0 <= nx && nx < n)
      if (0 <= ny && ny < n)
        if (a[nx][ny] == '.') dfs(nx, ny, c);
  }
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%s", a[i]);

  int c = 0;
  REP(i, n) REP(j, n)
    if (!bio[i][j] && a[i][j] == '.') {
      minx[c] = miny[c] = MAX;
      dfs(i, j, c);
      c++;
    }

  
  int ans = 0;
  for (int j = 0; j+k <= n; ++j) {
    static int e[MAX];
    REP(i, n) e[i] = 0;

    REP(i, c) {
      if (j <= miny[i] && maxy[i] < j+k) {
        if (maxx[i]-minx[i]+1 <= k) {
          int start = max(0, maxx[i]-k+1);
          int end = minx[i] + 1;
          e[start] += compsz[i];
          e[end] -= compsz[i];
        }
      }
    }

    int blocked = 0;
    REP(x, k) REP(y, k) blocked += a[x][j+y] == 'X';

    int inside = 0;
    for (int i = 0; i+k <= n; ++i) {
      inside += e[i];

      static int have[MAXC];
      static int cookie = 0;

      int total = inside + blocked;

      cookie++;
      auto count = [&] (int id) {
        if (have[id] != cookie) {
          have[id] = cookie;
          total += compsz[id];
        }
      };
      
      REP(x, k) {
        if (j > 0 && a[i+x][j-1] == '.') count(comp[i+x][j-1]);
        if (j+k < n && a[i+x][j+k] == '.') count(comp[i+x][j+k]);
      }
      REP(y, k) {
        if (i > 0 && a[i-1][j+y] == '.') count(comp[i-1][j+y]);
        if (i+k < n && a[i+k][j+y] == '.') count(comp[i+k][j+y]);
      }

      ans = max(ans, total);
      
      REP(y, k) {
        blocked -= a[i][j+y] == 'X';
        if (i+k < n) blocked += a[i+k][j+y] == 'X';
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}