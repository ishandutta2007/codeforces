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

const int MAX = 400100;

int gc[MAX];
int a[MAX];
int n;

llint solve(int g) {
  static int best[MAX];
  REP(i, g) {
    best[i] = 0;
    for (int j = i; j < n; j += g)
      best[i] = max(best[i], a[j]);
  }

  static int cnt[MAX];
  REP(i, n+1) cnt[i] = 0;
  
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < 2*n && best[j%g] == a[j]) j++;
    for (int start = i; start < n && start < j; ++start)
      cnt[min(n-1, j - start)]++;
    i = j + 1;
  }

  llint ans = 0;
  for (int i = n-1; i > 0; --i) {
    cnt[i] += cnt[i + 1];
    if (gc[i] == g) ans += cnt[i];
  }
  return ans;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) a[n+i] = a[i];
  FOR(i, 1, n+1) gc[i] = __gcd(i, n);

  llint ans = 0;
  for (int i = 1; i*i <= n; ++i)
    if (n % i == 0) {
      ans += solve(i);
      if (i*i != n) ans += solve(n/i);
    }

  printf("%lld\n", ans);
  return 0;
}