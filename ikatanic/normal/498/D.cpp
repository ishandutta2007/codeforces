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

const int MAXN = 200200;
const int off = 1<<17;
const int M = 60;

struct data {
  int sum[M];
};

data T[2*off];
int a[MAXN];

data dummy, tmp;
data ans[22];

data one(int ax) {
  data d;
  REP(j, M) d.sum[j] = 1 + (j%ax == 0);
  return d;
}

void merge(data &a, data &b, data &c) {
  REP(start, M)
    c.sum[start] = a.sum[start] + b.sum[ (start + a.sum[start])%M ];
}

void solve(int i, int lo, int hi, int a, int b, int id) {
  if (lo >= b || hi <= a) {
    ans[id] = dummy;
    return;
  }

  if (lo >= a && hi <= b) {
    ans[id] = T[i];
    return;
  }

  solve(i*2, lo, (lo + hi)/2, a, b, id+1);
  ans[id] = ans[id+1];
  solve(i*2+1, (lo + hi)/2, hi, a, b, id+1);
  tmp = ans[id];
  merge(tmp, ans[id+1], ans[id]);
}
    
int main(void) {
  REP(j, M) dummy.sum[j] = 0;

  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  REP(i, n) T[off+i] = one(a[i]); 
  for (int i = off-1; i > 0; --i) 
    merge(T[i*2], T[i*2+1], T[i]);
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    char tip[5];
    int x, y;
    scanf("%s %d %d", tip, &x, &y);

    if (tip[0] == 'A') {
      --x, --y;
      solve(1, 0, off, x, y, 0);
      printf("%d\n", ans[0].sum[0]);
    }

    if (tip[0] == 'C') {
      --x;
      T[x += off] = one(y);
      for (x /= 2; x; x /= 2)
        merge(T[x*2], T[x*2+1], T[x]);
    }
  }

  return 0;
}