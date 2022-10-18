#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;

int can(llint k, llint m, llint n) {
  if (k == 0) return n == 1;

  llint rem = llint(k)*m;
  n--;
  
  llint cnt = 1;
  for (int i = 1; i <= k && rem > 0 && n > 0; ++i) {
    cnt = cnt*(k-i+1)/i;
    llint w = min(cnt, rem/i);
    n -= w, rem -= w*i;
  }
  return n <= 0;
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    int lo = 0, hi = n;
    while (lo < hi) {
      int mid = (lo + hi)/2;
      if (can(mid, m, n)) hi = mid; else 
        lo = mid+1;
    }

    printf("%d\n", lo);
  }
  return 0;
}