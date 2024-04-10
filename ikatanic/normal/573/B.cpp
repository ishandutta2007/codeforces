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

const int MAX = 100010;

int a[MAX];
int f[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  a[0] = 0;
  REP(i, n) scanf("%d", &a[i+1]);
  a[n+1] = 0;
  n += 2;

  int cur = 0;
  REP(i, n) {
    cur = min(cur, a[i] - i);
    f[i] = cur + i;
  }
  cur = n-1;
  for (int i = n-1; i >= 0; --i) {
    cur = min(cur, a[i] + i);
    f[i] = min(f[i], cur - i);
  }

  printf("%d\n", *max_element(f, f + n));
  return 0;
}