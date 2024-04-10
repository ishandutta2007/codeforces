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

const int MAXN = 1000100;
const int M = 23;

vector<int> E[MAXN];
int a[MAXN][M];
int dad[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  n++;

  FOR(i, 1, n) {
    scanf("%d", dad+i); --dad[i];
    E[dad[i]].push_back(i);
  }
  
  for (int x = n-1; x >= 0; --x) {
    REP(j, M) a[x][j] = n;
    a[x][0] = x;
    
    static int m1[M], m2[M];
    REP(j, M) m1[j] = m2[j] = n+1;

    for (int y: E[x])
      REP(j, M)
        if (a[y][j] <= m1[j]) {
          m2[j] = m1[j];
          m1[j] = a[y][j];
        } else
          if (a[y][j] < m2[j]) m2[j] = a[y][j];

    int cur = n;
    for (int j = M-1; j > 0; --j) {
      cur = m1[j];
      if (x == 0) cur = min(cur, m1[j-1]); else
        cur = min(cur, m2[j-1]);
      a[x][j] = cur;
    }
  }

  a[0][0] = 1;
  REP(j, M-1) {
    int lo = a[0][j], hi = a[0][j+1];
    lo = max(lo, 1);
    hi = min(hi, n);
    FOR(i, lo, hi)
      printf("%d ", j);
  }
  printf("\n");
  return 0;
}