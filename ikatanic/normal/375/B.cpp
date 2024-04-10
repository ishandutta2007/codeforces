#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef unsigned int uint;

char a[5005][5005];
int d[5005];
int f[5005];

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  REP(i, n) d[i] = -1;

  int ans = 0;
  REP(l, m) {
    REP(i, m) f[i] = 0;

    int cnt = 0;
    REP(i, n)
      if (a[i][l] == '1') {
        if (d[i] < l) d[i] = l;
        while (d[i] < m && a[i][d[i]] == '1') d[i]++;
        f[d[i]]++;
        cnt++;
      }

    for (int r = l; r < m; ++r) {
      cnt -= f[r];
      ans = max(ans, (r-l+1)*cnt);
    }
  }

  printf("%d\n", ans);
  return 0;
}