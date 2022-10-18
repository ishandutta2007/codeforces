#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> masks(n, 0);
  REP(i, n) masks[i] = 1<<i;
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    masks[a] |= 1<<b;
    masks[b] |= 1<<a;
  }

  if (m == n*(n-1)/2) {
    puts("0");
    return 0;
  }

  vector<int> f(1<<n, 0);
  vector<int> r(1<<n, -1);
  REP(i, n) f[1<<i] = masks[i], r[1<<i] = i;

  vector<int> best;
  REP(i, n) best.push_back(i);

  REP(s, 1<<n) {
    if (f[s] == (1<<n)-1) {
      static int who[222];
      int sz = 0;
      for (int x = s; x != 0; x ^= (1<<r[x])) {
        who[sz++] = r[x];
      }
      if (sz < (int)best.size()) best = vector<int>(who, who + sz);;
    }
    REP(i, n) {
      if ((f[s] & (1<<i)) && !(s & (1<<i))) {
        f[s | (1<<i)] = f[s] | masks[i];
        r[s | (1<<i)] = i;
      }
    }
  }
 

  printf("%d\n", (int)best.size());
  for (int x: best) {
    printf("%d ", x+1);
  }
  printf("\n");
  return 0;
}