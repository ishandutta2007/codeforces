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

const int MAXN = 2020;

char a[MAXN][MAXN];
int cnt[MAXN][MAXN];

queue<int> Q;

int dx[] = {+1, 0, -1, 0};
int dy[] = {0, +1, 0, -1};

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);

  auto valid = [&] (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
  };

  auto kill = [&] (int x, int y) {
    REP(k, 4) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (valid(x2, y2) && a[x2][y2] == '.') {
        cnt[x2][y2]--;
        if (cnt[x2][y2] <= 1) {
          Q.push(x2);
          Q.push(y2);
        }
      }
    }
  };

  REP(i, n) REP(j, m) {
    cnt[i][j] = 0;
    REP(k, 4)
      if (valid(i + dx[k], j + dy[k]))
        cnt[i][j] += a[i + dx[k]][j + dy[k]] == '.';
    if (a[i][j] == '.' && cnt[i][j] <= 1) {
      Q.push(i);
      Q.push(j);
    }
  }

  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    int y = Q.front(); Q.pop();

    if (a[x][y] != '.') continue;

    REP(k, 4) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (valid(x2, y2) && a[x2][y2] == '.') {
        if (a[x][y] == '.') {
          if (k == 0) a[x][y] = '^', a[x2][y2] = 'v';
          if (k == 2) a[x][y] = 'v', a[x2][y2] = '^';
          if (k == 1) a[x][y] = '<', a[x2][y2] = '>';
          if (k == 3) a[x][y] = '>', a[x2][y2] = '<';
          kill(x, y);
          kill(x2, y2);
        }
      }
    }

    if (a[x][y] == '.') {
      puts("Not unique");
      return 0;
    }
  }

  REP(i, n) REP(j, m)
    if (a[i][j] == '.') {
      puts("Not unique");
      return 0;
    }

  REP(i, n) puts(a[i]);
  return 0;
}