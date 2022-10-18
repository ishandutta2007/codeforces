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

const int MAX = 111;

char a[MAX][MAX];
char ans[MAX][MAX];
bool done[MAX][MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%s", a[i]);
  
  for (int dx = -(n-1); dx <= n-1; ++dx)
    for (int dy = -(n-1); dy <= n-1; ++dy) {
      if (dx == 0 && dy == 0) {
        ans[dx+n-1][dy+n-1] = 'o';
        continue;
      }

      bool ok = true;
      REP(i, n) REP(j, n)
        if (a[i][j] == 'o') {
          int ni = i + dx, nj = j + dy;
          if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
          if (a[ni][nj] == '.') {
            ok = false;
            break;
          }
        }

      if (!ok) {
        ans[dx+n-1][dy+n-1] = '.';
        continue;
      }

      ans[dx+n-1][dy+n-1] = 'x';
      REP(i, n) REP(j, n)
        if (a[i][j] == 'o') {
          int ni = i + dx, nj = j + dy;
          if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
          done[ni][nj] = true;
        }
    }

  REP(i, n) REP(j, n)
    if (a[i][j] == 'x' && !done[i][j]) {
      puts("NO");
      return 0;
    }

  puts("YES");
  REP(i, 2*n-1) {
    ans[i][2*n-1] = '\0';
    puts(ans[i]);
  }
    
  return 0;
}