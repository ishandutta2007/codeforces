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

const int MAX = 500500;
const int K = 60;

int dad[MAX];
double f[MAX][K];

int main(void) {
  int n = 1;
  f[0][0] = 0;
  FOR(i, 1, K) f[0][i] = 1;
  dad[0] = -1;
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int type, x;
    scanf("%d %d", &type, &x); --x;
    
    if (type == 1) {
      int nx = n++;
      dad[nx] = x;
      f[nx][0] = 0;
      FOR(i, 1, K) f[nx][i] = 1;

      int y = nx;
      double oldf = 1.0;
      FOR(h, 1, K) {
        if (x == -1) break;
        double tmp = f[x][h];
        f[x][h] *= (1 + f[y][h-1]) / (1 + oldf);
        oldf = tmp;
        y = x;
        x = dad[x];
        
      }
    } else {
      double ans = 0;
      REP(i, K) ans += f[x][i];
      ans = K-1 - ans;
      printf("%.12lf\n", ans);
    }
  }
  return 0;
}