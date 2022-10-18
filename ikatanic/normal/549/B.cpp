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

char e[111][111];
int c[111], a[111];
bool ok[111];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%s", e[i]);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) {
    ok[i] = true;
    REP(j, n)
      if (e[i][j] == '1') c[j]++;
  }

  while (true) {
    int f = -1;
    REP(i, n)
      if (c[i] == a[i]) { f = i; break; }

    if (f == -1) break;

    assert(ok[f]);
    REP(j, n)
      if (e[f][j] == '1') c[j]--;
    ok[f] = false;
  }

  int cnt = 0;
  REP(i, n) cnt += ok[i];
  printf("%d\n", cnt);
  REP(i, n)
    if (ok[i]) printf("%d ", i+1);
  printf("\n");
  return 0;
}