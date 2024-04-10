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

const int MAX = 155;
const int MAXS = 6000;
const int inf = 1e9;

int f[MAX][MAXS];
int ms[MAX];
int a[MAX];

int main(void) {
  int n, k, s;
  scanf("%d %d %d", &n, &k, &s);
  REP(i, n) scanf("%d", &a[i]);

  ms[0] = 1;
  REP(i, n)
    for (int j = k-1; j >= 0; --j) {
      while (ms[j+1] < ms[j] + i-j) f[j+1][ms[j+1]++] = inf;
      for (int s = 0; s < ms[j]; ++s)
        f[j+1][s+i-j] = min(f[j+1][s+i-j], f[j][s] + a[i]);
    }

  int ans = inf;
  REP(ss, ms[k])
    if (ss <= s) ans = min(ans, f[k][ss]);
  printf("%d\n", ans);
  return 0;
}