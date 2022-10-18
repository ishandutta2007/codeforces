#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

int a[5050], b[5050];
int p[5050];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", a+i, b+i);
  REP(i, n) p[i] = i;
  sort(p, p + n, [] (const int &x, const int &y) {
      if (a[x] != a[y]) return a[x] < a[y];
      return b[x] < b[y];
    }
  );

  int t = 0;
  REP(pi, n) {
    int i = p[pi];
    if (b[i] >= t) t = b[i]; else
      if (a[i] >= t) t = a[i];
  }

  printf("%d\n", t);
  return 0;
}