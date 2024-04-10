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

const int MAX = 200200;

int f[MAX];

void go(int& x, int& y) {
  int d = min(x, y);
  x -= d, y -= d;
}

int calc(int a, int b, int c, int rab, int ca, int cb, int cab, int cc) {
  int ans = rab;
  int rc = rab;
  go(cc, rc);
  go(cab, rc);
  go(cb, rc);
  go(ca, rc);

  go(cab, rab);
  go(cb, rab);
  go(ca, rab);

  cc += cab;
  rc = cc;
  int ra = cc, rb = cc;
  ans += rc;

  go(cc, rc);
  go(cb, rc);
  go(ca, rc);
  go(cb, rb);
  go(ca, rb);
  go(ca, ra);
  assert(cc == 0);

  ra = rb = rc = (cb + 1) / 2;
  ans += ra;
  go(cb, rc);
  go(ca, rc);
  go(cb, rb);
  go(ca, rb);
  go(ca, ra);
  assert(cb == 0);

  ans += (ca + 2) / 3;
  return ans;
}

int main(void) {
  int n, x[3];
  scanf("%d", &n);
  REP(i, 3) scanf("%d", &x[i]);
  REP(i, n) scanf("%d", &f[i]);

  sort(x, x + 3);
  sort(f, f + n);

  int a = x[0], b = x[1], c = x[2];
  int ans = 0;

  int cnta = 0, cntb = 0, cntc = 0;
  while (n > 0 && f[n - 1] > c) {
    int x = f[n - 1];
    if (x > a + b + c) {
      puts("-1");
      return 0;
    }

    ans++, n--;
    if (a + b >= x) cntc++;
    else if (a + c >= x) cntb++;
    else if (b + c >= x) cnta++;
  }


  int ab = min(a + b, c);
  int ca = 0, cb = 0, cab = 0, cc = 0;

  for (int i = n-1; i >= 0; --i) {
    if (cntc > 0 && c >= f[i]) cntc--;
    else if (cntb > 0 && b >= f[i]) cntb--;
    else if (cnta > 0 && a >= f[i]) cnta--;
    else if (f[i] <= a) ca++;
    else if (f[i] <= b) cb++;
    else if (f[i] <= ab) cab++;
    else cc++;
  }

  int best = n;
  for (int k = 0; k <= n; ++k)
    best = min(best, calc(a, b, c, k, ca, cb, cab, cc));
  ans += best;

  printf("%d\n", ans);
  return 0;
}