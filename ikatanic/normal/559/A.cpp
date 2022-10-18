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
  int A, B, C, D, E, F;
  scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

  assert(B + C == E + F);
  if (B > F) swap(B, F), swap(C, E);

  int ans = 0;
  int cur = 2*A - 1;
  REP(i, B)
    ans += (cur += 2);
  cur++;
  ans += cur * (F - B);
  cur++;
  REP(i, E)
    ans += (cur -= 2);

  printf("%d\n", ans);
  return 0;
}