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

const int inf = 1e9;

int main(void) {
  int n;
  scanf("%d", &n);

  int sum = 0;
  int lo = -inf;
  int hi = inf;
  REP(i, n) {
    int c, d;
    scanf("%d %d", &c, &d);
    if (d == 2) {
      hi = min(hi, 1900-1 - sum);
    } else {
      lo = max(lo, 1900 - sum);
    }
    sum += c;
  }

  if (lo > hi) {
    puts("Impossible");
  } else if (hi == inf) {
    puts("Infinity");
  } else printf("%d\n", hi + sum);
  
  return 0;
}