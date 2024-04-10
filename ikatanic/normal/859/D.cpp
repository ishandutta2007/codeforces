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

const int MAX = 222;

double p[MAX][MAX];
double f[MAX][MAX];
double g[MAX][MAX];
double s[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  n = 1 << n;
  REP(i, n) REP(j, n) {
    scanf("%lf", &p[i][j]);
    p[i][j] /= 100.0;
  }

  REP(i, n) g[n + i][i] = 1.0;
  REP(i, n) s[n + i] = 0.5;
  
  for (int i = n-1; i > 0; --i) {
    s[i] = s[i*2] + s[i*2+1];
    
    REP(x, n) {
      REP(y, n) {
        if (x != y) {
          g[i][x] += g[i*2][x] * g[i*2+1][y] * p[x][y];
          g[i][x] += g[i*2][y] * g[i*2+1][x] * p[x][y];
        }
      }

      double m1 = *max_element(f[i*2], f[i*2] + n);
      double m2 = *max_element(f[i*2+1], f[i*2+1] + n);
      
      f[i][x] = max(f[i][x], g[i][x] * s[i] + f[i*2][x] + m2);
      f[i][x] = max(f[i][x], g[i][x] * s[i] + f[i*2+1][x] + m1);
    }
  }

  double ret = *max_element(f[1], f[1] + n);
  printf("%.15lf\n", ret);
  return 0;
}