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
  int n;
  static char s[222];
  scanf("%d", &n);
  scanf("%s", s);

  int ans = 0;
  REP(i, n) {
    int dx = 0, dy = 0;
    FOR(j, i, n) {
      if (s[j] == 'R') dy++;
      if (s[j] == 'L') dy--;
      if (s[j] == 'U') dx++;
      if (s[j] == 'D') dx--;
      if (dx == 0 && dy == 0) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}