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

const int MAXN = 100010;

llint x[MAXN], y[MAXN];
int h[MAXN], dad[MAXN], d[MAXN];
int L[MAXN][20];

int ccw(int a, int b, int c) {
  llint w = x[a]*llint(y[b]-y[c]) + x[b]*llint(y[c]-y[a]) + x[c]*llint(y[a]-y[b]);
  return w > 0;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n)
    scanf("%I64d %I64d", x+i, y+i);
  
  int m = 0;
  for (int i = n-1; i >= 0; --i) {
    dad[i] = -1;
    
    if (m > 1) {
      int lo = 0, hi = m-1;
      while (lo < hi) {
        int mid = (lo + hi + 1)/2;
        if (ccw(i, h[mid], h[mid-1])) hi = mid-1; else
          lo = mid;
      }
      
      dad[i] = h[lo];
    }
    if (m == 1) dad[i] = h[0];

    while (m > 1 && ccw(i, h[m-1], h[m-2])) m--;
    h[m++] = i;
  }
  
  REP(i, n) L[i][0] = dad[i];
  for (int j = 1; j < 20; ++j)
    REP(i, n) {
      L[i][j] = -1;
      if (L[i][j-1] != -1) L[i][j] = L[L[i][j-1]][j-1];
    }
  
  for (int i = n-1; i >= 0; --i) {
    if (dad[i] == -1) d[i] = 0; else
      d[i] = d[dad[i]] + 1;
  }

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    
    if (d[a] < d[b]) swap(a, b);
    for (int j = 19; j >= 0; --j)
      if (d[a]-(1<<j) >= d[b]) a = L[a][j];

    if (a != b) {
      for (int j = 19; j >= 0; --j)
        if (L[a][j] != L[b][j]) a = L[a][j], b = L[b][j];
      a = dad[a];
    }

    printf("%d ", a+1);
  }
  printf("\n");
  return 0;
}