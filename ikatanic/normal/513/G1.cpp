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

const int MAXN = 110;

int a[MAXN];
int cnt = 0;
int n, k;

void rec(int rem) {
  if (rem == 0) {
    REP(i, n) REP(j, i)
      cnt += a[j] > a[i];
    return;
  }

  REP(i, n) FOR(j, i, n) {
    reverse(a + i, a + j + 1);
    rec(rem - 1);
    reverse(a + i, a + j + 1);
  }
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);
  
  rec(k);
  double ans = cnt;
  REP(i, k) ans /= n*(n+1)/2;

  printf("%.12lf\n", ans);
  return 0;
}