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

const int MAX = 1010000;

int L[MAX];

int sum(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

void add(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    L[x] += v;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  k = min(k, n-k);
  
  int x = 0;
  llint regions = 1;
  REP(i, n) {
    int y;
    if (x + k < n) {
      y = x + k;
      regions += sum(x+k-1) - sum(x) + 1;
    } else {
      y = x + k - n;
      regions += 2*i - sum(x) + sum(y-1) + 1;
    }
    printf("%lld ", regions);

    add(x, 1);
    add(y, 1);
    x = y;
  }
  printf("\n");
  return 0;
}