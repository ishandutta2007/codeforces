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

double pow(double a, int b) {
  double r = 1;
  while (b > 0) {
    if (b&1) r *= a;
    a *= a, b /= 2;
  }
  return r;
}

int main(void) {
  int m, n;
  scanf("%d %d", &m, &n);
  double ans = 0;
  for (int i = 1; i <= m; ++i)
    ans += (pow(double(i)/m, n) - pow(double(i-1)/m, n)) * i;
  printf("%lf\n", ans);
  return 0;
}