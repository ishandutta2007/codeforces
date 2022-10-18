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

const int MAX = 1001000;
const llint inf = 1e18;

int a[MAX];
int f[MAX];

int main(void) {
  int n;
  llint A, B;
  scanf("%d %lld %lld", &n, &A, &B);
  REP(i, n) scanf("%d", &a[i]);

  llint ans = (n-1) * A;
  REP(rot, 2) {
    vector<int> p;
    for (int d = -1; d <= +1; ++d) {
      int x = a[0] + d;
      for (int j = 2; j*j <= x; ++j)
        if (x % j == 0) {
          p.push_back(j);
          while (x % j == 0) x /= j;
        }
      if (x > 1) p.push_back(x);
    }
    
    for (int g: p) {
      int last_bad = -1;
      int cnt = 0;
      REP(i, n) {
        if (a[i] % g == 0) f[i] = 0;
        else if ((a[i]-1)%g == 0 || (a[i]+1)%g == 0) f[i] = 1, cnt++;
        else f[i] = -1, last_bad = i;
      }
      
      if (last_bad == -1) {
        ans = min(ans, cnt * B);
      }

      bool have_bad = false;
      llint best = -inf;
      int sj = 0;
      REP(j, n) {
        sj += f[j] == 1;
        have_bad |= f[j] == -1;

        llint val = j*A - sj*B;
        if (j >= last_bad && j > 0) {
          ans = min(ans, cnt*B + val - best);
        }
        if (!have_bad) best = max(best, val);
      }
    }
    reverse(a, a + n);
  }

  printf("%lld\n", ans);
  return 0;
}