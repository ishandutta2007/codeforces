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

const int MAX = 110;

int f[MAX][MAX];

int main(void) {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  int rem1 = (n + 1) / 2;
  int rem2 = n / 2;
  REP(i, a) {
    REP(j, b) {
      if (rem1 > 0)
        if ((i == 0 || f[i-1][j] == 0 || f[i-1][j] == 2))
            if ((j == 0 || f[i][j-1] == 0 || f[i][j-1] == 2)) {
                f[i][j] = 1;
                rem1--;
                continue;
              }
      
      if (rem2 > 0)
        if ((i == 0 || f[i-1][j] == 0 || f[i-1][j] == 1))
            if ((j == 0 || f[i][j-1] == 0 || f[i][j-1] == 1)) {
                f[i][j] = 2;
                rem2--;
                continue;
            }
    }
  }

  if (rem1 || rem2) {
    puts("-1");
    return 0;
  }

  int c1 = -1, c2 = 0;
  REP(i, a) REP(j, b) {
    if (f[i][j] == 1) f[i][j] = (c1 += 2);
    else if (f[i][j] == 2) f[i][j] = (c2 += 2);
    assert(f[i][j] <= n);
  }

  REP(i, a) {
    REP(j, b) printf("%d ", f[i][j]);
    printf("\n");
  }

  return 0;
}