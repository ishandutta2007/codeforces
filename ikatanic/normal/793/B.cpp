#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;

char a[MAX][MAX];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool bio[MAX][MAX][4][3];

void dfs(int x, int y, int dir, int k) {
  if (k > 2) return;
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (a[x][y] == '*') return;
  
  if (bio[x][y][dir][k]) return;
  bio[x][y][dir][k] = true;
  
  if (a[x][y] == 'T') {
    puts("YES");
    exit(0);
  }

  REP(d, 4) {
    dfs(x + dx[d], y + dy[d], d, k + (d != dir));
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);

  REP(i, n) REP(j, m)
    if (a[i][j] == 'S') {
      REP(k, 4) dfs(i, j, k, 0);
    }
  puts("NO");
  return 0;
}