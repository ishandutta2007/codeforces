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

int main(void) {
  int n, d, h;
  scanf("%d %d %d", &n, &d, &h);
  
  if (d == 1) {
    if (n != 2) { puts("-1"); return 0; }
    printf("1 2\n");
    return 0;
  }

  if (d-h > h) { puts("-1"); return 0; }

  int N = 2;
  int cur = 1;
  for (int i = 1; i <= h; ++i) {
    printf("%d %d\n", cur, N);
    cur = N++;
  }
  
  cur = 1;
  for (int i = 1; i <= d-h; ++i) {
    printf("%d %d\n", cur, N);
    cur = N++;
  }

  while (N <= n) {
    printf("%d %d\n", h, N);
    cur = N++;
  }
  return 0;
}