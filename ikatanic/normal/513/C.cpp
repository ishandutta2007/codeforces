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

long double f[MAX][1<<5];
int a[10], b[10];
int n, m;

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", a+i, b+i);

  long double ans = 0;

  f[0][0] = 1.0;
  REP(pos, MAX) REP(s, 1<<n) REP(ns, 1<<n)
    if ((s & ns) == 0) {
      long double prob = f[pos][s];

      REP(i, n)
        if (!(s&(1<<i))) {
          if (ns & (1<<i)) {
            if (a[i] <= pos && pos <= b[i])
              prob *= 1.0 / (b[i] - pos + 1);
            else
              prob = 0;
          } else
            if (a[i] <= pos && pos <= b[i]) {
              if (pos == b[i]) prob = 0; else
                prob *= (long double)(b[i] - pos) / (b[i] - pos + 1);
            }
        }

      int cnt1 = 0, cnt2 = 0;
      REP(i, n) {
        if (s&(1<<i)) cnt1++;
        if (ns&(1<<i)) cnt2++;
      }

      if (cnt1 < n-1 && cnt1+cnt2 >= n-1) {
        ans += prob * pos;
      }
      f[pos + 1][s | ns] += prob;
    }

  double aa = ans;
  printf("%.12lf\n", aa);
  return 0;
}