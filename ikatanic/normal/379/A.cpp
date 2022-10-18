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

int main(void)
{
  int a, b;
  scanf("%d %d", &a, &b);
  
  int ans = 0;
  while (a > 0) {
    int d = min(a, b);
    ans += d, a -= d;
    if (d == b) a++;
  }

  printf("%d\n", ans);
  return 0;
}