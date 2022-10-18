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
typedef pair<int, int> par;

const int MAXN = 505;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char a[MAXN][MAXN];
bool b[MAXN][MAXN];
int n, m, k, rem;

void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#' || b[x][y] || !rem) return;
  b[x][y] = true;
  rem--;
  REP(i, 4)
    dfs(x+dx[i], y+dy[i]);
}

int main(void)
{
  scanf("%d %d %d", &n, &m, &k);

  rem = 0;
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, m)
      if (a[i][j] == '.') rem++;
  }
  rem -= k;
  
  REP(i, n) REP(j, m) 
    if (a[i][j] == '.') dfs(i, j);

  REP(i, n) REP(j, m)
    if (a[i][j] == '.' && !b[i][j]) a[i][j] = 'X';

  REP(i, n) puts(a[i]);
  return 0;
}