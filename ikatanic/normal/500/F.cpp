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

const int MAX = 4040;
const int MAXQ = 20020;

struct query {
  int a, q, id;
  friend bool operator < (const query &a, const query &b) {
    return a.a < b.a;
  }
};

struct item {
  int c, h, t;
  friend bool operator < (const item &a, const item &b) {
    return a.t < b.t;
  }
};

query r[MAXQ];
item a[MAX];
int ans[MAXQ];

int fl[MAX][MAX];
int fr[MAX][MAX];
int n, p;

void solve(int lo, int hi, int loq, int hiq) {
  int mid = (lo + hi) / 2;
  if (lo >= hi || loq >= hiq) return;
  
  int hiqleft = loq;
  while (hiqleft < hiq && r[hiqleft].a < a[mid].t) hiqleft++;
  
  int loqright = hiq;
  while (loqright > loq && r[loqright-1].a >= a[mid].t + p) loqright--;

  solve(mid+1, hi, loqright, hiq);
  solve(lo, mid, loq, hiqleft);

  FOR(i, mid, hi+1) REP(j, MAX) fr[i][j] = 0;
  FOR(i, mid, hi) REP(j, MAX) {
    fr[i+1][j] = max(fr[i+1][j], fr[i][j]);
    if (j + a[i].c < MAX) fr[i+1][j + a[i].c] = max(fr[i+1][j + a[i].c], fr[i][j] + a[i].h);     
  }
  
  FOR(i, lo-1, mid) REP(j, MAX) fl[i][j] = 0;
  for (int i = mid-1; i >= lo; --i) REP(j, MAX) {
      fl[i-1][j] = max(fl[i-1][j], fl[i][j]);
      if (j + a[i].c < MAX) fl[i-1][j + a[i].c] = max(fl[i-1][j + a[i].c], fl[i][j] + a[i].h);
  }
  
  for (int i = hiqleft; i < loqright; ++i) {
    int lb = mid, rb = mid;
    while (rb < hi && a[rb].t <= r[i].a && r[i].a < a[rb].t+p) rb++;
    while (lb >= lo && a[lb].t <= r[i].a && r[i].a < a[lb].t+p) lb--;

    int id = r[i].id;
    REP(j, r[i].q+1)
      ans[id] = max(ans[id], fl[lb][j] + fr[rb][r[i].q - j]);
  }
}

int main(void) {
  scanf("%d %d", &n, &p);
  FOR(i, 1, n+1) scanf("%d %d %d", &a[i].c, &a[i].h, &a[i].t);
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    int a, qq;
    scanf("%d %d", &a, &qq);
    r[i] = {a, qq, i};
  }

  sort(a + 1, a + n+1);
  sort(r, r + q);

  solve(1, n + 1, 0, q);
  
  REP(i, q) printf("%d\n", ans[i]);
  return 0;
}