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

const int MAXN = 500005;

int a[MAXN];

bool can(int n, int m) {
  if (2*m > n) return false;
  REP(i, m)
    if (a[i]*2 > a[n-m+i]) return false;
  return true;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  sort(a, a + n);
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1)/2;
    if (can(n, mid)) lo = mid; else
      hi = mid-1;
  }

  printf("%d\n", n-lo);
  return 0;
}