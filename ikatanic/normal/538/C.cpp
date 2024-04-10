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

const int MAX = 100010;

int d[MAX], h[MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    scanf("%d %d", d+i, h+i);
    --d[i];
  }

  int ans = max(h[0] + d[0], h[m-1] + (n-1 - d[m-1]));
  for (int i = 0; i+1 < m; ++i) {
    int a = d[i], b = d[i + 1];
    int ha = h[i], hb = h[i + 1];
    
    bool ok = false;
    REP(c, 2) {
      int v = hb + b-a - ha - c;
      if (v%2) continue;

      int u = v/2;
      int d = ha - hb + u;   
      if (u >= 0 && d >= 0) {
        ok = true;
        ans = max(ans, ha + u);
      }
    }

    if (!ok) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}