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

long double f[MAX], nf[MAX];
int a[MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", &a[i]);

  if (m == 1) {
    puts("1");
    return 0;
  }

  f[0] = 1.0;
  REP(i, n) {
    long double sum = 0;
    int maks = (i+1) * m + 1;
    REP(j, maks) {
      nf[j] = sum;
      if (j - a[i] >= 0) nf[j] -= f[j - a[i]];
      sum += f[j];
      if (j - m >= 0) sum -= f[j - m];
    }

    REP(j, maks) {
      f[j] = nf[j] / (m-1);
    }
  }

  int score = accumulate(a, a + n, 0);
  long double ans = accumulate(f, f + score, 0.0) * (m-1) + 1;
  printf("%.12lf\n", (double)ans);
  return 0;
}