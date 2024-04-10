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

const int MAXN = 200100;

struct loga {
  int L[MAXN];

  int sum(int x) {
    int r = 0;
    for (++x; x; x -= x&-x)
      r += L[x];
    return r;
  }
  
  void add(int x, int v) {
    for (++x; x < MAXN; x += x&-x)
      L[x] += v;
  }
} P, Q, A;

int p[MAXN], q[MAXN];
int r[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", p+i);
  REP(i, n) scanf("%d", q+i);
  
  REP(i, n) P.add(i, 1), Q.add(i, 1), A.add(i, 1);

  REP(i, n) {
    P.add(p[i], -1), Q.add(q[i], -1);
    r[i] = P.sum(p[i]) + Q.sum(q[i]);
  }

  for (int i = n-1; i >= 0; --i) {
    int l = n-i-1;
    if (i > 0) r[i-1] += r[i] / (l+1);
    r[i] %= l+1;
  }

  REP(i, n) {
    int lo = 0, hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (A.sum(mid)-1 < r[i]) lo = mid+1; else
        hi = mid;
    }

    printf("%d ", lo);
    A.add(lo, -1);
  }
  printf("\n");
  return 0;
}