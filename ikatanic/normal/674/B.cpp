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

int main(void) {
  int n, k, a, b, c, d;
  scanf("%d %d", &n, &k);
  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (k < n+1 || n == 4) {
    puts("-1");
    return 0;
  }

  vector<int> v;
  FOR(i, 1, n+1)
    if (i != a && i != b && i != c && i != d) v.push_back(i);

  printf("%d %d", a, c);
  for (int x: v) printf(" %d", x);
  printf(" %d %d\n", d, b);

  printf("%d %d", c, a);
  for (int x: v) printf(" %d", x);
  printf(" %d %d\n", b, d);
  return 0;
}