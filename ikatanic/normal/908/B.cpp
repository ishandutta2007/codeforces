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

char a[55][55];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int sx = -1, sy = -1;
  int ex = -1, ey = -1;
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, m) {
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
      if (a[i][j] == 'E') {
        ex = i, ey = j;
      }
    }
  }

  char c[111];
  scanf("%s", c);
  int k = strlen(c);

  assert(sx != -1 && ex != -1);

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};

  vector<int> f = {0, 1, 2, 3};
  int ans = 0;

  do {
    int x = sx, y = sy;
    REP(i, k) {
      x += dx[ f[c[i]-'0'] ];
      y += dy[ f[c[i]-'0'] ];
      if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
        break;
      }

      if (x == ex && y == ey) {
        ans++;
        break;
      }
    }
  } while (next_permutation(f.begin(), f.end()));

  printf("%d\n", ans);

  return 0;
}