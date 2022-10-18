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
  int x;
  char b1[11], b2[11];
  scanf("%d %s %s", &x, b1, b2);

  if (b2[0] == 'w') {
    x = (x - 5 + 14) % 7;
    printf("%d\n", 52 + (x < 2));
  } else {
    if (x < 30) printf("%d\n", 12);
    if (x == 30) printf("%d\n", 11);
    if (x == 31) printf("%d\n", 7);
  }
  return 0;
}