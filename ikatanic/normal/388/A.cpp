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

int a[101];
bool dead[101];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  sort(a, a + n);
  int ans = 0;
  REP(i, n)
    if (!dead[i]) {
      int c = 0;
      for (int j = i; j < n; ++j)
        if (!dead[j] && a[j] >= c) dead[j] = true, c++;
      ans++;
    }

  printf("%d\n", ans);
  return 0;
}