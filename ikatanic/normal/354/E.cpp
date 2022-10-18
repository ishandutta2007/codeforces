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

bool f[20][5];
int r[20][5];
int p[20][5];
int a[20];

int dig[50][6];
bool can[50];

int main(void)
{
  REP(i, 1000000) {
    bool ok = true;
    int sum = 0, x = i;
    REP(j, 6) {
      int d = x%10; x /= 10;
      if (d != 0 && d != 4 && d != 7) { ok = false; break; }
      sum += d;
    }

    if (ok && !can[sum]) {
      x = i;
      REP(j, 6) dig[sum][j] = x%10, x /= 10;
      can[sum] = true;
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    llint x;
    scanf("%I64d", &x);
    
    int m = 0;
    while (x > 0) a[m++] = x%10, x /= 10;
    
    memset(f, 0, sizeof(f));
    
    f[0][0] = true;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < 5; ++j)
        if (f[i][j])
          for (int k = 0; k < 50; ++k) {
            int d = j+k;
            if (can[k] && (d%10) == a[i]) {
              f[i+1][d/10] = true;
              r[i+1][d/10] = k;
              p[i+1][d/10] = j;
            }
          }

    if (!f[m][0]) { puts("-1"); continue; }
    
    static vector<int> v;
    v.clear();

    int g = 0;
    llint ans[6];
    REP(j, 6) ans[j] = 0;
    for (int i = m; i > 0; --i) {
      REP(j, 6) 
        ans[j] = ans[j]*10 + dig[ r[i][g] ][j];
      g = p[i][g];
    }

    REP(i, 6)
      printf("%I64d%c", ans[i], i == 5 ? '\n' : ' ' );
  }

  return 0;
}