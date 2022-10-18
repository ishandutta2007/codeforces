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

int main(void) {
  int n, h;
  scanf("%d %d", &n, &h);

  double a = h * 1.0 / n;
  FOR(i, 1, n) {
    double x = sqrt(i*a * h);
    printf("%.12lf ", x);
  }
  printf("\n");
  return 0;
}