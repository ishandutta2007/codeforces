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

const int MAX = 111;

char a[MAX][MAX];
int c[MAX][MAX];

int ans;

void go(int i, int j) {
  int k = a[i][j] - c[i][j];
  if (k == 0) return;

  ans++;
  REP(x, i+1) REP(y, j+1)
    c[x][y] += k;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, m) a[i][j] = a[i][j] == 'B' ? -1 : +1;
  }

  ans = 0;
  while (n > 0 && m > 0) {
    go(n-1, m-1);
    for (int i = n-2; i >= 0; --i) go(i, m-1);
    for (int i = m-2; i >= 0; --i) go(n-1, i);
    n--, m--;
  }

  printf("%d\n", ans);
  return 0;
}