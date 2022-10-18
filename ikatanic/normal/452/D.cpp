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

const int inf = 1e9;

int f[3][1010];
int n[3], t[3];
int best[3];

int main(void) {
  int k;
  scanf("%d", &k);
  REP(i, 3) scanf("%d", n+i);
  REP(i, 3) scanf("%d", t+i);
  
  int ans = 0;
  while (k > 0) {
    REP(i, 3) {
      best[i] = inf;
      REP(j, n[i])
        best[i] = min(best[i], f[i][j]);
    }
    
    int start = max(best[0], max(best[1] - t[0], best[2] - t[0] - t[1]));
    int pre = 0;
    REP(i, 3) {
      pre += t[i];
      REP(j, n[i])
        if (f[i][j] == best[i]) {
          f[i][j] = start + pre;
          break;
        }
    }
    ans = max(ans, start + pre);
    k--;
  }
  
  printf("%d\n", ans);
  return 0;
}