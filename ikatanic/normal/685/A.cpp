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

int calc(int x) {
  int ret = 0;
  while (x > 0) ret++, x /= 7;
  return max(ret, 1);
}

int mask(int x, int c) {
  int ret = 0;
  REP(i, c) {
    ret |= 1 << (x % 7);
    x /= 7;
  }
  return ret;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int N = calc(n-1);
  int M = calc(m-1);

  if (N + M > 7) {
    puts("0");
    return 0;
  }

  int ans = 0;
  REP(i, n) REP(j, m) {
    int x = mask(i, N);
    int y = mask(j, M);
    if (x & y) continue;

    int cx = 0, cy = 0;
    REP(i, 7) cx += (x>>i)&1, cy += (y>>i)&1;
    if (cx == N && cy == M) ans++;
  }

  printf("%d\n", ans);
  return 0;
}