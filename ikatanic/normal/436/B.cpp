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

const int MAXN = 2020;

char a[MAXN][MAXN];

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, n) scanf("%s", a[i]);
    
  auto get = [&] (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return '-';
    return a[x][y];
  };

  REP(j, m) {
    int cnt = 0;
    REP(i, n) {
      if (get(i, j-i) == 'R') cnt++;
      if (get(i, j+i) == 'L') cnt++;
      if (a[i][j] == 'U' && (i%2) == 0) cnt++;
    }
    printf("%d%c", cnt, j+1 < m ? ' ' : '\n');
  }
  return 0;
}