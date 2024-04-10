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
typedef pair<llint, int> par;
#define v first
#define i second

const int off = 1<<18;
const llint inf = 1e18;
const int MAXN = 300000;

struct data {
  par p[2];
  par n[2];
} T[2*off];

par dummypar = {-inf, -1};
data dummy = { {dummypar, dummypar}, {dummypar, dummypar} };

data merge(const data &a, const data &b) {
  par p[4] = {a.p[0], a.p[1], b.p[0], b.p[1]};
  par n[4] = {a.n[0], a.n[1], b.n[0], b.n[1]};
  sort(p, p + 4);
  sort(n, n + 4);
  data c;
  c.p[0] = p[3], c.p[1] = p[2];
  c.n[0] = n[3], c.n[1] = n[2];
  return c;
};

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return dummy;
  if (lo >= a && hi <= b) return T[i];
  return merge(
    query(i*2, lo, (lo + hi) / 2, a, b),
    query(i*2+1, (lo + hi) / 2, hi, a, b)
  );
}

int d[MAXN], h[MAXN];
llint s[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) {
    scanf("%d", d+i);
    d[n + i] = d[i];
  }
  REP(i, n) {
    scanf("%d", h+i);
    h[n + i] = h[i];
  }

  REP(i, 2*n)
    s[i+1] = s[i] + d[i];
  
  REP(i, 2*off) T[i] = dummy;

  REP(i, 2*n) {
    T[off + i].p[0] = {2LL*h[i] + s[i], i};
    T[off + i].n[0] = {2LL*h[i] - s[i], i};
  }

  for (int i = off-1; i > 0; --i)
    T[i] = merge(T[i*2], T[i*2+1]);
  
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    if (b < a) b += n;

    data d = query(1, 0, off, b + 1, a + n);

    llint ans = 0;
    REP(i, 2) REP(j, 2)
      if (d.p[i].i != d.n[j].i)
        ans = max(ans, d.p[i].v + d.n[j].v);
    printf("%lld\n", ans);
  }

  return 0;
}