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

int main(void) {
  int n, l, v1, v2, k;
  scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);

  auto can = [&] (double R) {
    double t = (l - R*v1) / (v2 - v1);
    double t2 = (v2 - v1)*t / (v1 + v2);
    return t + ((n+k-1)/k - 1)*(t + t2) <= R;
    
  };
 
  double lo = 0, hi = double(l) / v1;
  REP(it, 100) {
    double mid = (lo + hi) / 2;
    if (can(mid)) hi = mid;
    else lo = mid;
  }

  printf("%.10lf\n", lo);
  return 0;
}