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

const int MAXS = 500010;

bool f[MAXS];

int main(void) {
  int n, d;
  scanf("%d %d", &n, &d);
  
  f[0] = 1;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    for (int j = MAXS-1-x; j >= 0; --j)
      f[j+x] |= f[j];
  }

  int r = 1, sum = 0, ans = 0;
  while (r < MAXS) {
    int next = -1;
    while (r <= sum+d && r < MAXS) {
      if (f[r]) next = r;
      r++;
    }

    if (next == -1) break;
    sum = next, ans++;
  }
  
  printf("%d %d\n", sum, ans);
  return 0;
}