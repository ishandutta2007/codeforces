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
  int n, r;
  scanf("%d %d", &n, &r);

  vector<int> x(n);
  vector<double> y(n);
  REP(i, n) {
    scanf("%d", &x[i]);

    y[i] = r;
    REP(j, i) {
      if (abs(x[i] - x[j]) <= 2*r) {
        y[i] = max(y[i], y[j] + sqrt(4*r*r - (x[i]-x[j])*(x[i]-x[j])));
      }
    }
  }

  REP(i, n) {
    printf("%.15lf ", y[i]);
  }
  printf("\n");
  return 0;
}