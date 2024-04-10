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

int e[25][25];

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    REP(i, n) REP(j, n) e[i][j] = 0;
    
    REP(i, n) {
      int j = (i+1)%n;
      e[i][j] = e[j][i] = 1;
      j = (j+1)%n;
      e[i][j] = e[j][i] = 1;
    }
    
    REP(i, n) REP(j, i)
      if (!e[i][j] && p > 0) {
        e[i][j] = e[j][i] = 1;
        p--;
      }

    REP(i, n) REP(j, i)
      if (e[i][j]) printf("%d %d\n", j+1, i+1);
  }
    
  return 0;
}