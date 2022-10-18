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

int suf[MAX];
int a[MAX];

int main(void) {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  REP(i, n) scanf("%d", &a[i]);
  for (int i = n-1; i >= 0; --i)
    suf[i] = suf[i + 1] | a[i];
  
  llint ans = 0;
  int pref = 0;
  REP(i, n) {
    llint cur = a[i];
    REP(j, k) cur *= x;
    cur |= pref | suf[i + 1];
    ans = max(ans, cur);
    pref |= a[i];
  }
  printf("%lld\n", ans);
  return 0;
}