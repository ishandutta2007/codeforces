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

const int MAX = 1e6;

int f[MAX];
int r[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  
  if (n == MAX) {
    printf("1\n%d\n", MAX);
    return 0;
  }

  assert(n < MAX);

  vector<int> v;
  REP(s, 1<<6) {
    int x = 0;
    REP(i, 6)
      x = x * 10 + ((s>>i)&1);
    if (x > 0) v.push_back(x);
  }

  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = i, r[i] = 1;
    for (int x: v)
      if (x <= i && f[i-x]+1 < f[i]) f[i] = f[i-x]+1, r[i] = x;
  }

  vector<int> ans;
  while (n > 0) {
    ans.push_back(r[n]);
    n -= r[n];
  }

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}