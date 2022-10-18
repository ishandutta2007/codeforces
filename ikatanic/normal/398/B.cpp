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

const int MAXN = 2002;

double f[MAXN][MAXN];
bool bior[MAXN], bioc[MAXN];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, k) {
    int r, c;
    scanf("%d %d", &r, &c); --r, --c;
    bior[r] = bioc[c] = true;
  }

  int a = 0, b = 0;
  REP(i, n) {
    if (!bior[i]) a++;
    if (!bioc[i]) b++;
  }

  REP(i, a+1) REP(j, b+1) {
    if (i == 0 && j == 0) {
      f[i][j] = 0;
      continue;
    }

    double pij = double(i)/n*double(j)/n;
    double pi = double(i)/n - pij;
    double pj = double(j)/n - pij;
    double p0 = 1 - pi - pj - pij;

    f[i][j] = 1;
    if (i > 0) f[i][j] += pi*f[i-1][j];
    if (j > 0) f[i][j] += pj*f[i][j-1];
    if (i > 0 && j > 0) f[i][j] += pij*f[i-1][j-1];
    f[i][j] /= (1 - p0);
  }
  
  printf("%lf\n", f[a][b]);
  return 0;
}