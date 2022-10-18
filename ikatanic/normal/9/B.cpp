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

const double inf = 1e100;

int X[111];

int main(void) {
  int n, vb, vs;
  scanf("%d %d %d", &n, &vb, &vs);
  REP(i, n) scanf("%d", X+i);
  
  int x, y;
  scanf("%d %d", &x, &y);

  double ans = inf;
  int id = -1;
  for (int i = n-1; i > 0; --i) {
    double d = sqrt(llint(X[i]-x)*(X[i]-x) + llint(y)*y);
    double t = double(X[i])/vb + d/vs;
    if (t + 1e-10 < ans) ans = t, id = i;
  }
  
  printf("%d\n", id+1);
  return 0;
}