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

const int MAX = 300300;
const int MAXK = 5050;
const llint inf = 1e18;

int a[MAX];
llint f[MAXK][MAXK];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);
  sort(a, a + n);
  int s = (n + k - 1) / k;

  REP(i, k+1) REP(j, k+1) f[i][j] = inf;
  f[0][0] = 0;
  REP(i, k) REP(j, k) {
    int pos = i*s + j*(s-1);
    if (pos + s <= n)
      f[i + 1][j] = min(f[i + 1][j], f[i][j] + a[pos + s - 1] - a[pos]);
    if (s-1 > 0 && pos + s - 1 <= n)
      f[i][j + 1] = min(f[i][j + 1], f[i][j] + a[pos + s - 2] - a[pos]);
  }

  int c1 = 0, c2 = 0;
  REP(i, k)
    if ((n-i+k-1)/k == s) c1++; else
      c2++;

  printf("%lld\n", f[c1][c2]);
  return 0;
}