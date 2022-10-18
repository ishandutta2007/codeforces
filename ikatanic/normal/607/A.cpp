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

const int MAX = 2e6;

int r[MAX];
int f[MAX];

int main(void) {
  int n;
  scanf("%d", &n);

  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    r[a] = b;
  }

  REP(x, MAX) {
    if (r[x] == 0) {
      f[x] = x > 0 ? f[x - 1] : 0;
    } else {
      f[x] = 1 + (x - r[x] > 0 ? f[x - r[x] - 1] : 0);
    }
  }

  int best = 0;
  REP(x, MAX) best = max(best, f[x] + 1);
  printf("%d\n", n+1-best);
  return 0;
}