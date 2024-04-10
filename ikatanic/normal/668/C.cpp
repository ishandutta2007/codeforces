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

const int MAX = 100100;

double mini[MAX], maks[MAX];
double p[MAX], r[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%lf", &maks[i]);
  REP(i, n) scanf("%lf", &mini[i]);
  assert(n < 100000);

  double sp = 0, sr = 0;
  REP(i, n) {
    // p(i)sr + r(i)sp + p(i)r(i) = maks(i)
    // p(i) + r(i) = mini(i) + maks(i)
    
    double A = 1;
    double B = sr - sp - mini[i] - maks[i];
    double C = maks[i] - (mini[i] + maks[i])*sr;
    double D = B*B - 4*A*C;
    D = max(D, 0.0);
    D = sqrtl(D);

    double x = (-B + D) / (2*A);
    if (x > 1) x = (-B - D) / (2*A);
    r[i] = x;
    p[i] = mini[i] + maks[i] - r[i];
    
    sp += p[i];
    sr += r[i];
  }

  REP(i, n) printf("%.10lf ", p[i]); printf("\n");
  REP(i, n) printf("%.10lf ", r[i]); printf("\n");
  return 0;
}