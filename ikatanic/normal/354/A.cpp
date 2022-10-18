#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int w[100100];
int s[100100];

int main(void)
{
  int n, l, r, ql, qr;
  scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
  REP(i, n) {
    scanf("%d", w+i);
    s[i] = w[i];
    if (i > 0) s[i] += s[i-1];
  }

  int ans = 2000000001;
  REP(lc, n+1) {
    int rc = n-lc;
    int cost = 0;
    
    if (lc > 0) cost += s[lc-1]*l + (s[n-1]-s[lc-1])*r; else
      cost = s[n-1]*r;
    if (lc > rc) cost += (lc-rc-1)*ql; else
      if (lc < rc) cost += (rc-lc-1)*qr;
    ans = min(ans, cost);
  }

  printf("%d\n", ans);
  return 0;
}