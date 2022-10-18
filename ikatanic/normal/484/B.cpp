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

const int MAXN = 2000100;

int a[MAXN];
int m[MAXN];
bool ima[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", a+i);
    ima[a[i]] = true;
  }

  FOR(i, 1, MAXN)
    if (ima[i]) m[i] = i; else
      m[i] = m[i-1];
  
  int ans = 0;
  FOR(x, 1, MAXN)
    if (ima[x])
      for (int lo = 2*x; lo < MAXN; lo += x) {
        int y = m[lo-1];
        if (y >= lo-x)
          ans = max(ans, y-(lo-x));
      }

  printf("%d\n", ans);
  return 0;
}