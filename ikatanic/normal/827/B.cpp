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

  int lo = 1, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;

    int best = max(0, min(mid / 2, mid - mid / 2) - 1);
    llint cnt = mid - 1 + best * 1LL * (k - 2);
    if (cnt < n - k) lo = mid + 1;
    else hi = mid;
  }

  printf("%d\n", lo);
  REP(i, lo) printf("%d %d\n", i+1, i+2);

  int m = lo / 2;
  int maks = max(0, min(m, lo - m) - 1);

  int cur = lo + 1;

  n -= k;
  n -= lo - 1;
  k -= 2;
  assert(n >= 0 && k >= 0);
  
  while (k > 0) {
    int d = min(maks, n);
    int prev = m;
    REP(i, d + 1) {
      printf("%d %d\n", prev+1, (cur++)+1);
      prev = cur - 1;
    }
    n -= d;
    k--;
  }
  
  return 0;
}