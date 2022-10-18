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

int a[111111];
int d[111111];

int main(void) {
  int n;
  scanf("%d", &n);

  int m = 1<<(n+1);
  FOR(i, 2, m) scanf("%d", a+i);
  
  int ans = 0;
  for (int i = (1<<n)-1; i > 0; --i) {
    ans += abs(a[i*2] - a[i*2+1]);
    a[i] += max(a[i*2], a[i*2+1]);
    
  }
  printf("%d\n", ans);
  return 0;
}