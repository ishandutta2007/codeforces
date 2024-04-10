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
int c[MAXN];

int cntodd, cntnonzero;

void reset() {
  cntodd = cntnonzero = 0;
  REP(i, MAXN) c[i] = 0;
}

bool inc(int x, int k) {
  if (c[x]+k < 0) return false;
  if (c[x]) cntnonzero--;
  if (c[x]%2) cntodd--;
  c[x] += k;
  if (c[x]%2) cntodd++;
  if (c[x]) cntnonzero++;
  return true;
};

int count_good_l(int *a, int n) {
  int ans = 0;

  // l <= mid
  reset();
  REP(i, n) inc(a[i], +1);
  for (int l = 0; l <= n-l-1; ++l) {
    if (cntodd <= 1) ans++;
    if (!inc(a[l], -2)) break;
  }
  
  // l > mid
  reset();
  REP(i, n) {
    if ((n&1) && i == n/2) continue;
    if (i < n/2) inc(a[i], +1); else
      inc(a[i], -1);
  }

  for (int l = (n+1)/2; l < n; ++l) {
    if (cntnonzero == 0) ans++;
    if (a[l] != a[n-l-1]) break;
  }
  return ans;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  int s = 0;
  while (s < n && a[s] == a[n-s-1]) s++;

  if (s == n) {
    printf("%lld\n", llint(n)*(n+1)/2);
    return 0;
  }
  
  assert(s < n/2);

  llint ans = 0;
  llint cl = count_good_l(a + s, n - 2*s);
  reverse(a, a + n);
  llint cr = count_good_l(a + s, n - 2*s);
  
  if (cl > 0) ans += llint(s+1) * (s + cl);
  if (cr > 0) ans += llint(s+1) * (s + cr);
  if (cl > 0 && cr > 0) ans -= llint(s+1) * (s+1);

  printf("%lld\n", ans);
  return 0;
}