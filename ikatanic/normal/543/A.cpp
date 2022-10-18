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

const int MAX = 550;
int mod;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int f[MAX][MAX];
int a[MAX];

int main(void) {
  int n, m, b;
  scanf("%d %d %d %d", &n, &m, &b, &mod);
  REP(i, n) scanf("%d", a+i);

  f[0][0] = 1 % mod;
  REP(i, n) REP(j, m+1) REP(k, b+1)
    if (k + a[i] <= b && j < m) f[j+1][k+a[i]] = add(f[j+1][k+a[i]], f[j][k]);
    
  int ans = 0;
  REP(k, b+1) ans = add(ans, f[m][k]);
  printf("%d\n", ans);
  return 0;
}