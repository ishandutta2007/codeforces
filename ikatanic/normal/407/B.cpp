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

const int mod = 1e9 + 7;

int f[1001];

int main(void) {
  int n;
  scanf("%d", &n);

  int ans = 0;
  REP(i, n) {
    int p;
    scanf("%d", &p); --p;
    f[i] = 2;
    for (int j = p; j < i; ++j) {
      f[i] += f[j];
      if (f[i] >= mod) f[i] -= mod;
    }
    ans += f[i];
    if (ans >= mod) ans -= mod;
  }

  printf("%d\n", ans);
  return 0;
}