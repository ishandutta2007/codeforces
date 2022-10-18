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

const int inf = 1000000000;

int c[5];

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    c[x]++;
  }
  
  int ans = inf;
  REP(i, n+1) {
    static int a[5];
    REP(i, 5) a[i] = c[i];

    static int g[5];
    REP(i, 5) g[i] = 0;
    
    int rem = i, sum = 0;
    for (int i = 4; i >= 0; --i) {
      int d = min(rem, a[i]);
      a[i] -= d, g[i] += d, rem -= d;
      sum += a[i]*i;
    }
    sum += g[4];
    
    int cnt = 0;
    REP(j, 3) {
      int u = g[j]*(3-j);
      if (u > sum) { cnt = -1; break; } else
        g[3] += g[j], g[j] = 0, sum -= u, cnt += u; 
    }

    if (cnt == -1) continue;
    
    sum -= g[4];
    if (sum > 0) {
      if (sum > g[3]) continue;
      cnt += sum;
    }
    ans = min(ans, cnt);
  }
    
  if (ans == inf) ans = -1;
  printf("%d\n", ans);
  return 0;
}