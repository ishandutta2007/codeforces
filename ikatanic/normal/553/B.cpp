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

const int MAX = 55;

llint c[MAX];

int main(void) {
  int n;
  llint k;
  scanf("%d %lld", &n, &k);
  
  c[0] = c[1] = 1;
  for (int i = 2; i <= n; ++i)
    c[i] = c[i-1] + c[i-2];
  
  int cur = 1;
  while (n > 0) {
    if (c[n - 1] >= k) {
      printf("%d ", cur);
      cur++, n--;
    } else {
      k -= c[n - 1];
      printf("%d %d ", cur+1, cur);
      cur += 2, n -= 2;
    }
  }
  printf("\n");
  return 0;
}