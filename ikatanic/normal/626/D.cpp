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

const int MAX = 10010;

int a[MAX+1];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);

  static llint d[MAX];
  REP(i, n) REP(j, i) d[a[i]-a[j]]++;

  static llint d2[MAX];
  REP(i, MAX/2) REP(j, MAX/2) d2[i+j] += d[i] * d[j];

  static llint d2s[MAX];
  REP(i, MAX) {
    d2s[i] = d2[i];
    if (i > 0) d2s[i] += d2s[i-1];
  }

  long double ans = 0;
  long double combs = n*(n-1) / 2;
  REP(i, n) REP(j, i) {
    ans += d2s[a[i] - a[j] - 1] / combs / combs;
  }
  ans /= combs;
  printf("%.15lf\n", (double)ans);
  return 0;
}