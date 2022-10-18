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

double f[1010][1010];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  f[0][0] = 1.0;
  REP(i, n) REP(j, m+1) {
    double p = double(m - j) / (n*m - i);
    f[i+1][j+1] += f[i][j] * p;
    f[i+1][j] += f[i][j] * (1 - p);
  }

  double ans = 0;
  REP(j, m+1)
    ans += j*j*f[n][j];
  ans /= n;

  printf("%lf\n", ans);
  return 0;
}