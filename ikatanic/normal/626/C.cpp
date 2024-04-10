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

bool can(int n, int m, int R) {
  n = max(0, n - (R/2 - R/6));
  m = max(0, m - (R/3 - R/6));
  return n + m <= R/6;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int lo = 0, hi = 1e8;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (can(n, m, mid)) hi = mid; 
    else lo = mid+1;
  }

  printf("%d\n", lo);
  return 0;
}