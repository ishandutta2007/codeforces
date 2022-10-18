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

const int MAXN = 2020;

bool bio[MAXN];
int t[MAXN], h[MAXN], m[MAXN];

int main(void) {
  int n, x;
  scanf("%d %d", &n, &x);
  REP(i, n) scanf("%d %d %d", t+i, h+i, m+i);

  int ans = 0;
  REP(rt, 2) {
    int cnt = 0;
    int now = 0, cur = x;
    REP(i, n) bio[i] = false;

    REP(it, n) {
      int k = -1;
      REP(i, n)
        if (!bio[i] && t[i] == now && h[i] <= cur)
          if (k == -1 || m[i] > m[k]) k = i;
      if (k == -1) break;
      cnt++;
      bio[k] = true;
      cur += m[k];
      now ^= 1;
    }
    
    ans = max(ans, cnt);
    REP(i, n) t[i] ^= 1;
  }
  
  printf("%d\n", ans);
  return 0;
}