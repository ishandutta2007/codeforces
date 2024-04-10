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

const int MAX = 505;

int a[MAX];
int f[MAX][MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);

  REP(d, n) REP(i, n-d) {
    int j = i + d;
    
    if (d == 0) { f[i][j] = 0; continue; }
    if (d == 1 && a[i] == a[j]) { f[i][j] = 0; continue; }
    
    f[i][j] = d + 1;
    if (a[i] == a[j]) {
      f[i][j] = min(f[i][j], f[i+1][j-1]);
    }

    for (int ni = i + 1; ni <= j; ++ni) {
      f[i][j] = min(f[i][j], 1 + f[i][ni-1] + f[ni][j]);
    }
  }
    
  printf("%d\n", f[0][n-1] + 1);
  return 0;
}