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

bool ask(int x, int y) { 
  printf("1 %d %d\n", x, y);
  fflush(stdout);
  static char s[10];
  scanf("%s", s);
  return s[0] == 'T';
}

int go(int lo, int hi) {
  if (lo > hi) return -1;
  if (lo == hi) return lo;
  
  int mid = (lo + hi) / 2;
  if (ask(mid, mid + 1)) {
    return go(lo, mid);
  } else {
    return go(mid + 1, hi);
  }
}

bool eq(int x, int y) {
  return ask(x, y) && ask(y, x);
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  int x = go(1, n);
  int y = go(x + 1, n);

  if (y == -1 || !eq(x, y)) y = go(1, x-1);
  
  printf("2 %d %d\n", x, y);
  fflush(stdout);
  return 0;
}