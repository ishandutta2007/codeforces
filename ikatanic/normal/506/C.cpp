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

const int MAXN = 100100;

llint h[MAXN], a[MAXN];
int cnt[MAXN];
int n, m, k, p;

bool can(llint H) {
  llint sum = 0;
  REP(i, m+1) cnt[i] = 0;
  REP(i, n) {
    if (h[i] + m*a[i] <= H) continue;
    if (a[i] > H) return false;
    
    int j = m;
    llint cur = H;

    while (j > 0) {
      if (cur - j*a[i] >= h[i]) break;
      llint w = min(cur / a[i], (llint)j);
      llint delta = a[i] - (cur - w*a[i]);
      if (w == j) delta = h[i] - (cur - w*a[i]);
      llint need = (delta + p-1) / p;

      sum += need;
      cnt[j-w+1] += need;

      if (sum > m*k) return false;
      j -= w;
      cur += need*p - w*a[i];
    }
  }
  
  int cur = 0;
  FOR(i, 1, m+1) {
    cur += cnt[i];
    cur = max(cur-k, 0);
  }
  return cur == 0;
}

int main(void) {
  scanf("%d %d %d %d", &n, &m, &k, &p);
  REP(i, n) scanf("%lld %lld", h+i, a+i);


  llint lo = 0, hi = 2e18;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;

    if (can(mid)) hi = mid; else
      lo = mid+1;
  }
  printf("%lld\n", lo);
  return 0;
}