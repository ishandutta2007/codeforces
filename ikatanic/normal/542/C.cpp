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

const int MAX = 220;

int a[MAX];
bool u[MAX];
bool bio[MAX];

llint gcd(llint a, llint b) {
  return !b ? a : gcd(b, a % b);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &a[i]);
    --a[i];
  }

  llint ans = 1;
  REP(i, n) {
    int x = i, c = 0;
    REP(j, n) bio[j] = false;

    while (!bio[x]) {
      c++;
      bio[x] = true;
      x = a[x];
    }
    
    if (x == i) {
      u[x] = true;
      ans = ans/gcd(ans, c) * c;
    }
  }

  int maks = 0;
  REP(i, n) {
    int c = 0, x = i;
    while (!u[x]) c++, x = a[x];
    int j = 1;
    while (j*ans < c) j++;
    maks = max(maks, j);
  }
  
  ans *= maks;
  printf("%lld\n", ans);
  return 0;
}