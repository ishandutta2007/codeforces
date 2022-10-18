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

const int MAXN = 100010;

int a[MAXN];
llint f[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }

  f[1] = a[1];
  FOR(i, 2, MAXN)
    f[i] = max(f[i-1], f[i-2] + llint(i)*a[i]);

  cout << f[MAXN-1] << endl;
  return 0;
}