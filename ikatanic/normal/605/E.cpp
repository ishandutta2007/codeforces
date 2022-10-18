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

const int MAX = 1010;
const double inf = 1e100;

double p[MAX][MAX];
double f[MAX], s[MAX], pr[MAX];
bool bio[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) REP(j, n) {
    int x;
    scanf("%d", &x);
    p[i][j] = x / 100.0;
  }

  REP(i, n) f[i] = inf, pr[i] = 1;
  f[n-1] = 0;

  while (true) {
    int x = -1;
    REP(i, n)
      if (!bio[i])
        if (x == -1 || f[i] < f[x]) x = i;

    if (x == 0) {
      printf("%.10lf\n", f[0]);
      return 0;
    }


    bio[x] = true;

    REP(i, n)
      if (!bio[i]) {
        s[i] += pr[i] * p[i][x] * f[x];
        pr[i] *= 1 - p[i][x];
        f[i] = (1 + s[i]) / (1 - pr[i]);
      }
  }

  assert(false);
  return 0;
}