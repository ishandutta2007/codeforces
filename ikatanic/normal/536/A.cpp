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
  int A, B, q;
  scanf("%d %d %d", &A, &B, &q);
  while (q--) {
    int l, t, m;
    scanf("%d %d %d", &l, &t, &m);
    --l;

    if (A + llint(l)*B > t) {
      printf("-1\n");
      continue;
    }

    int lo = l, hi = 2e6;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      
      llint maks = A + llint(mid)*B;
      llint n = mid - l + 1;
      llint off = A + llint(l)*B;
      llint sum = off*n + n*(n-1)/2*B;
      
      if (maks <= t && sum <= llint(m)*t) lo = mid; else
        hi = mid - 1;
    }
    
    printf("%d\n", lo+1);
  }
  return 0;
}