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

const int MAXN = 3000100;

int a[MAXN];

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) a[n+i] = a[2*n+i] = a[i];
  
  REP(i, q) {
    llint b;
    scanf("%lld", &b);
    
    int x = 0, k = 0;
    int best_gap = n, start = -1;
    while (x < n) {
      int y = x;
      llint sum = 0;
      while (y < 2*n && sum+a[y] <= b) sum += a[y++];
      if (y-x < best_gap) best_gap = y-x, start = x;
      x = y;
      k++;
    }

    int ans = k;
    for (int off = start; off <= start+best_gap; ++off) {
      if (off >= 2*n) break;

      int x = 0, k = 0;
      while (x < n) {
        int y = x;
        llint sum = 0;
        while (y < n && sum+a[off+y] <= b) sum += a[off+y++];
        x = y;
        k++;
      }
      ans = min(ans, k);
    }

    printf("%d\n", ans);
  }
        
  return 0;
}