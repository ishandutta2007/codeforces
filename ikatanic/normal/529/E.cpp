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

const int MAX = 1e7 + 100;
const int MAXN = 5050;

int a[MAXN];
bool ima[MAX];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) {
    scanf("%d", &a[i]);
    ima[a[i]] = true;
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int v;
    scanf("%d",  &v);
    
    int ans = k+1;
    REP(i, n) REP(x, k+1) {
      int rem = v - x * a[i];
      if (rem < 0) break;
      
      if (rem == 0) {
        ans = min(ans, x);
        continue;
      }

      FOR(y, 1, k+1-x)
        if (rem % y == 0 && rem/y < MAX && ima[rem / y]) {
          ans = min(ans, x + y);
          break;
        }
    }

    if (ans > k) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}