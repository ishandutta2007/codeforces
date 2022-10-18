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

const int MAX = 200020;

int a[MAX];
int f[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  for (int i = 1; i < n; ++i) {
    int clo = 1, v = i-1;
    while (v > 0) {
      int lo = clo, hi = (i-1)/v + 1;
      if (llint(v)*v > i) hi = clo + 1;
      while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((i-1) < v*mid) hi = mid; else
          lo = mid + 1;
      }

      if (a[i] < a[v]) f[clo]++, f[lo]--;
      clo = lo;
      v = (i-1) / clo;
    }

    if (a[i] < a[0]) f[clo]++;
  }

  int bal = 0;
  for (int i = 1; i < n; ++i) {
    bal += f[i];
    printf("%d ", bal);
  }
  printf("\n");
  return 0;
}