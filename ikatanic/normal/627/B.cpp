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

const int MAX = 200200;

llint v[MAX];

llint La[MAX];
llint Lb[MAX];

llint sum(llint* L, llint x) {
  llint r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

void add(llint* L, int x, llint v) {
  for (++x; x < MAX; x += x&-x)
    L[x] += v;
}

int main(void) {
  int n, k, a, b, q;
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  
  REP(i, q) {
    int tip;
    scanf("%d", &tip);
    if (tip == 1) {
      int d, x;
      scanf("%d %d", &d, &x); --d;
      
      add(La, d, -min(v[d], 1LL*a));
      add(Lb, d, -min(v[d], 1LL*b));

      v[d] += x;

      add(La, d, +min(v[d], 1LL*a));
      add(Lb, d, +min(v[d], 1LL*b));
    }
    if (tip == 2) {
      int p;
      scanf("%d", &p); --p;
      
      llint ans = sum(Lb, p - 1);
      if (p + k < n) ans += sum(La, n - 1) - sum(La, p + k - 1);
      printf("%lld\n", ans);
    }
  }
  return 0;
}