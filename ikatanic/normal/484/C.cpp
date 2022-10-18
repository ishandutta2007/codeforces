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
const int MAXLG = 20;

char a[MAXN], na[MAXN];
int f[MAXN][MAXLG];
int x[MAXN], y[MAXN];
int pos[MAXN];

void calc_jumps(int k, int d) {
  REP(i, k) x[i] = i;
  int cnt = 0;
  REP(i, d)
    for (int p = i; p < k; p += d)
      y[cnt++] = p;
  REP(i, k) f[y[i]][0] = i;
  
  FOR(j, 1, MAXLG) REP(i, k) {
    f[i][j] = f[i][j-1];
    int len = 1<<(j-1);
    if (f[i][j] >= len) f[i][j] = f[f[i][j]-len][j-1] + len;
  }
}

int calc_pos(int i, int n) {
  int off = 0;
  for (int j = MAXLG-1; j >= 0; --j)
    if (n&(1<<j)) {
      i = f[i][j];
      if (i >= (1<<j)) {
        i -= (1<<j);
        off += (1<<j);
      } else
        break;
    }
  return off + i;
}

int main(void) {
  scanf("%s", a);
  int n = strlen(a);

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int k, d;
    scanf("%d %d", &k, &d);
    calc_jumps(k, d);

    REP(j, n) {
      int start, off;
      if (j < k) start = j, off = 0; else
        start = k-1, off = j - (k-1);
      na[calc_pos(start, n-k+1-off) + off] = a[j];
    }
    REP(j, n) a[j] = na[j];

    puts(a);
  }
      
  return 0;
}