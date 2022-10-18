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

const int MAX = 1e6 + 1;

int f[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    f[x]++;
    for (int j = x+x; j < MAX; j += x)
      f[j] = max(f[j], f[x]);
  }

  printf("%d\n", *max_element(f, f + MAX));
  return 0;
}