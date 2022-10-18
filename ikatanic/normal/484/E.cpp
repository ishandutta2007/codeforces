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

const int MAXN = 1<<18;
const int offset = 1<<17;

struct data {
  int l, r, m, all;
  data() { l = r = m = all = 0; };
};

int h[MAXN];
int p[MAXN], qp[MAXN];
int qa[MAXN], qb[MAXN];
int ans[MAXN], w[MAXN];
data T[MAXN];

int n;

void merge(data &a, data &b, data &c) {
  c.m = max( max(a.m, b.m), a.r + b.l);
  c.l = a.l + a.all*b.l;
  c.r = b.r + b.all*a.r;
  c.all = a.all * b.all;
}

void update(int x, int p) {
  x += offset;
  T[x].l = T[x].r = T[x].m = T[x].all = p;
  for (x /= 2; x; x /= 2)
    merge(T[x*2], T[x*2+1], T[x]);
}

data dummy;

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return dummy;
  if (lo >= a && hi <= b) return T[i];
  data l = query(i*2, lo, (lo+hi)/2, a, b);
  data r = query(i*2+1, (lo+hi)/2, hi, a, b);
  data c;
  merge(l, r, c);
  return c;
}


int tmp1[MAXN], tmp2[MAXN];

void solve(int l, int r, int ql, int qr, int lo, int hi) {
  if (lo >= hi) {
    FOR(i, ql, qr) {
      ans[qp[i]] = lo;
    }
    return;
  }

  if (ql >= qr) return;

  int mid = (lo + hi + 1)/2;
  
  FOR(i, l, r)
    if (h[p[i]] >= mid) update(p[i], 1);
  
  int n1 = 0, n2 = 0;
  FOR(i, ql, qr) {
    int qq = query(1, 0, offset, qa[qp[i]], qb[qp[i]]).m; 
    if (qq < w[qp[i]]) tmp1[n1++] = qp[i]; else
      tmp2[n2++] = qp[i];
  }

  REP(i, n1) qp[ql+i] = tmp1[i];
  REP(i, n2) qp[ql+n1+i] = tmp2[i];
  int qm = ql + n1;

  n1 = 0, n2 = 0;
  FOR(i, l, r)
    if (h[p[i]] < mid) tmp1[n1++] = p[i]; else
      tmp2[n2++] = p[i];
  
  REP(i, n1) p[l+i] = tmp1[i];
  REP(i, n2) p[l+n1+i] = tmp2[i];
  int m = l + n1;

  solve(l, m, ql, qm, lo, mid-1);
  
  FOR(i, m, r)
    update(p[i], 0);

  solve(m, r, qm, qr, mid, hi);
}

int main(void) {
  dummy.all = 1;

  int q;
  scanf("%d",  &n);
  REP(i, n) {
    scanf("%d", h+i);
    p[i] = i;
  }

  scanf("%d", &q);
  REP(i, q) {
    scanf("%d %d %d", qa+i, qb+i, w+i);
    --qa[i];
    qp[i] = i;
  }

  solve(0, n, 0, q, 0, 1e9);
  REP(i, q) printf("%d\n", ans[i]);
  return 0;
}