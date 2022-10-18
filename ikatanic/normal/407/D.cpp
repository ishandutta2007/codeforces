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

const int MAXN = 404;
const int MAXK = MAXN*MAXN;

short f[2][MAXN][MAXN];
int bio[2][MAXK], last[2][MAXK];
int a[MAXN][MAXN];

enum {L, R};

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", a[i]+j);

  int ans = 0, cookie = 0;
  REP(d, m) {
    int now = d&1, prev = now^1;
    REP(y1, m-d) {
      int y2 = y1+d;
      cookie++;
      
      for (int x1 = n-1; x1 >= 0; --x1) {
        short &ref = f[now][x1][y1];
        ref = n-1;
        if (y1 < y2) ref = min(f[prev][x1][y1+1], f[prev][x1][y1]);
        if (x1+1 < n) ref = min(ref, f[now][x1+1][y1]);
        
        if (bio[R][a[x1][y1]] == cookie) ref = min(ref, short(last[R][a[x1][y1]]-1));
        if (bio[L][a[x1][y2]] == cookie) ref = min(ref, short(last[L][a[x1][y2]]-1));
        if (y1 < y2 && a[x1][y1] == a[x1][y2]) ref = x1-1;
        bio[L][a[x1][y1]] = cookie, last[L][a[x1][y1]] = x1;
        bio[R][a[x1][y2]] = cookie, last[R][a[x1][y2]] = x1;
        
        ans = max(ans, (y2-y1+1)*(ref-x1+1));
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}