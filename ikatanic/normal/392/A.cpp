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

inline bool good(int x, int y, int n) {
  return llint(x)*x + llint(y)*y <= llint(n)*n;
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  int y = 0, ly = 0, cnt = 0;
  for (int x = n-1; x >= 1; --x) {
    while (good(x, y+1, n)) y++;
    if (y != ly) cnt += y-ly-1;
    cnt++, ly = y;
  }

  cnt *= 4;
  if (n > 0) cnt += 4; else
    cnt++;
  printf("%d\n", cnt);
  return 0;
}