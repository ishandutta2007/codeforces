#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int lo = 2, hi = n;
  printf("1");

  bool left = true;
  REP(i, k-1) {
    if (left) printf(" %d", hi--); else
      printf(" %d", lo++);
    left ^= 1;
  }

  if (left) {
    for (int i = lo; i <= hi; ++i) printf(" %d", i);
  } else {
    for (int i = hi; i >= lo; --i) printf(" %d", i);
  }
  printf("\n");
  return 0;
}