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

const int MAXN = 55;

int a[MAXN];

int main(void) {
  int n;
  llint m;

  scanf("%d %lld", &n, &m);
  if (n == 1) {
    puts("1");
    return 0;
  }
  m--;

  int l = 0, r = n-1;
  REP(i, n)
    if (i < n-1 && (m & (1LL<<(n-1-i-1)))) a[r--] = i; else
      a[l++] = i;

  REP(i, n) printf("%d ", a[i]+1);
  printf("\n");
  return 0;
}