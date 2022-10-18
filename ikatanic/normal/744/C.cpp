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

const int MAXR = 16*16+1;
const int MAXN = 16;
const int inf = 1e9;

bool c[MAXN];
int r[MAXN], b[MAXN];

int pc[1<<MAXN][2];

int main(void) {
  int n;
  scanf("%d", &n);

  int cnt[2] = {0, 0};
  REP(i, n) {
    char s[11];
    scanf("%s %d %d", s, &r[i], &b[i]);
    c[i] = s[0] == 'B';
    cnt[c[i]]++;
  }

  if (cnt[0] > cnt[1]) {
    REP(i, n) {
      c[i] ^= 1;
      swap(r[i], b[i]);
    }
    swap(cnt[0], cnt[1]);
  }

  int e0 = 0, e1 = 0;
  REP(i, n) {
    if (r[i] > cnt[0]) {
      e0 += r[i] - cnt[0];
      r[i] = cnt[0];
    }
    if (b[i] > cnt[1]) {
      e1 += b[i] - cnt[1];
      b[i] = cnt[1];
    }
  }

  int R = n*cnt[0]+1;
  
  static int f[1<<MAXN][MAXR];
  REP(s, 1<<n) REP(r, R) f[s][r] = inf;

  REP(r, R) f[0][r] = 0;
  REP(s, 1<<n) {
    if (s) {
      int i = 0;
      while (!(s & (1<<i))) i++;
    
      pc[s][0] = pc[s ^ (1<<i)][0];
      pc[s][1] = pc[s ^ (1<<i)][1];
      pc[s][c[i]]++;
    } else {
      pc[s][0] = pc[s][1] = 0;
    }
    
    REP(i, n) {
      if (s & (1<<i)) continue;
      
      REP(rr, R) {
        int nr = rr + max(0, r[i] - pc[s][0]);
        int nb = f[s][rr] + max(0, b[i] - pc[s][1]);
        if (nr < R) f[s ^ (1<<i)][nr] = min(f[s ^ (1<<i)][nr], nb);
      }
    }
  }

  int ans = inf;
  REP(r, R) {
    int nr = r + e0;
    int nb = f[(1<<n)-1][r] + e1;
    ans = min(ans, max(nr, nb));
  }
  ans += n;
  
  printf("%d\n", ans);
  return 0;
}