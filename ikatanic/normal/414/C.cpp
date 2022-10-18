#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 21;

int a[1<<MAXN];

llint tot[MAXN];
llint inv[MAXN];

int countLess(int x, int *st, int *en) {
  return (lower_bound(st, en, x) - st);
}

int countGreater(int x, int *st, int *en) {
  return (en - upper_bound(st, en, x));
}

int main(void) {
  int n;
  scanf("%d", &n);
  int N = 1<<n;
  REP(i, N) scanf("%d", a+i);
  
  tot[0] = inv[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int len = 1<<i;
    int half = len/2;

    for (int l = 0; l < N; l += len) {
      // [l, l + len]
      REP(j, half) {
        int lt = countLess(a[l+j], a+l+half, a+l+len);
        int gt = countGreater(a[l+j], a+l+half, a+l+len);
        tot[i] += lt+gt;
        inv[i] += lt;
      }
      inplace_merge(a+l, a+l+half, a+l+len);
    }
  }

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int q;
    scanf("%d", &q);
    
    REP(i, q+1)
      inv[i] = tot[i] - inv[i];
    
    llint ans = 0;
    REP(i, n+1)
      ans += inv[i];
    printf("%I64d\n", ans);
  }
  return 0;
}