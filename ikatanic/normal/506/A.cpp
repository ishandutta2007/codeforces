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

const int N = 30000;
const int off = 500;
const int MAXK = 1000;

int f[N+1][MAXK];
int a[N+1];

int main(void) {
  int m, d;
  scanf("%d %d", &m, &d);
  REP(i, m) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }

  int ans = 0;
  f[d][off] = 1 + a[0] + a[d];
  REP(i, N+1) REP(j, MAXK)
    if (f[i][j]) {
      ans = max(ans, f[i][j]-1);
      int k = d + j - off;
      for (int l = -1; l <= 1; ++l)
        if (k+l > 0 && i+k+l <= N) f[i+k+l][j+l] = max(f[i+k+l][j+l], f[i][j] + a[i+k+l]);
    }

  printf("%d\n", ans);
  return 0;
}