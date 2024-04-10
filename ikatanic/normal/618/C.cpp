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

const int MAXN = 100100;

int x[MAXN], y[MAXN];

int ccw(int a, int b, int c) {
  llint w = 0;
  w += llint(x[a])*(y[b]-y[c]);
  w += llint(x[b])*(y[c]-y[a]);
  w += llint(x[c])*(y[a]-y[b]);
  return w < 0 ? -1 : w > 0;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", &x[i], &y[i]);

  int a = 0, b = 1, c = 2;
  while (ccw(a, b, c) == 0) c++;
  
  FOR(i, 2, n) 
    if (ccw(a, b, i) == 0) {
      auto X = minmax(x[a], x[b]);
      auto Y = minmax(y[a], y[b]);
      if (X.first <= x[i] && x[i] <= X.second)
        if (Y.first <= y[i] && y[i] <= Y.second)
          b = i;
    }

  if (ccw(a, b, c) < 0) swap(b, c);

  REP(i, n)
    if (i != a && i != b && i != c) 
      if (ccw(a, b, i) >= 0)
        if (ccw(c, a, i) >= 0)
          if (ccw(b, c, i) >= 0)
            c = i;
          
  printf("%d %d %d\n", a+1, b+1, c+1);
  return 0;
}