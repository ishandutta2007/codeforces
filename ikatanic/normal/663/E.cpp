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

const int MAXN = 20;
const int MAXM = 100100;

char s[MAXN][MAXM];
int a[MAXM];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", s[i]);
  REP(j, m) {
    REP(i, n) 
      if (s[i][j] == '1') a[j] |= 1<<i;
  }

  static int f[MAXN+1][1<<MAXN];
  REP(i, m) f[0][a[i]]++;
  REP(i, n)
    for (int j = n-1; j >= 0; --j)
      REP(s, 1<<n)
        f[j + 1][s ^ (1<<i)] += f[j][s];

  static int ans[1<<MAXN];
  REP(s, 1<<n) REP(j, n+1) ans[s] += min(j, n-j) * f[j][s];
  printf("%d\n", *min_element(ans, ans + (1<<n)));
  return 0;
}