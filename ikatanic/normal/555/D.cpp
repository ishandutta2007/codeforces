#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

int x[MAX];
int a[MAX];
int n;

map<int, int> id12, id21;

int next(int a, int l, bool left) {
  if (left) {
    int lo = 0, hi = a;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (x[a] - x[mid] > l) lo = mid + 1; else
        hi = mid;
    }
    return lo;
  } else {
    int lo = a, hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (x[mid] - x[a] > l) hi = mid - 1; else
        lo = mid;
    }
    return lo;
  }
}

int main(void) {
  int q;
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", &x[i]);
  REP(i, n) a[i] = x[i];
  sort(x, x + n);
  REP(i, n) {
    int j = lower_bound(x, x + n, a[i]) - x;
    id12[i] = j;
    id21[j] = i;
  }

  REP(i, q) {
    int a, l;
    scanf("%d %d", &a, &l); --a;
    a = id12[a];

    int b = next(a, l, false);
    l -= x[b] - x[a];
    
    bool left = true;
    while (true) {
      int c = next(b, l, left);
      if (c == b) break;
      int d = abs(x[b] - x[c]);

      int k = l / d;
      if (k % 2 == 0) c = b, left ^= 1;
      l -= k * d;

      b = c;
      left ^= 1;
    }

    b = id21[b];
    printf("%d\n", b+1);
  }
  return 0;
}