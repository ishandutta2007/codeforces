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

const int MAX = 1000100;
const int off = 1<<20;
const int inf = 2e9;

struct data {
  int op, cl;
};

data operator + (const data &a, const data &b) {
  int m = min(a.op, b.cl);
  return {a.op + b.op - m, a.cl + b.cl - m};
}

data T[2*off];
vector<int> E[MAX], C[MAX];
int h[MAX], s[MAX];
int v[MAX], u[MAX];

void dfs(int x, int dad, int m1, int m2, int idx) {
  if (h[x] <= m1) {
    m2 = m1;
    m1 = h[x], idx = x;
  } else
    if (h[x] < m2) m2 = h[x];
  
  C[idx].push_back(x);
  h[x] = m1;
  u[x] = m2;
  
  for (int y: E[x])
    if (y != dad) dfs(y, x, m1, m2, idx);
}

void add(int x, int v) {
  x += off;
  if (v == -1) {
    T[x].cl == 0 ? T[x].op++ : T[x].cl--;
  } else {
    T[x].op > 0 ? T[x].op-- : T[x].cl++;
  }
  for (x /= 2; x; x /= 2)
    T[x] = T[x*2] + T[x*2+1];
}

bool test(int i, int m) {
  for (int j: C[i]) add(min(u[j], m), +1);
  bool ans = T[1].op == 0 && T[1].cl == 0;
  for (int j: C[i]) add(min(u[j], m), -1);
  return ans;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", h+i);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  int k;
  scanf("%d", &k);
  REP(i, k) scanf("%d", s+i);
  
  int m = 0;
  REP(i, n) v[m++] = s[i];
  REP(i, n) v[m++] = h[i];
  
  sort(v, v + m);
  m = unique(v, v + m) - v;

  REP(i, n) {
    h[i] = lower_bound(v, v + m, h[i]) - v;
    s[i] = lower_bound(v, v + m, s[i]) - v;
  }

  dfs(0, -1, m-1, m-1, -1);

  REP(i, n) T[off + s[i]].op++;
  REP(i, n) T[off + h[i]].cl++;
  FOR(i, off, 2*off) {
    int m = min(T[i].op, T[i].cl);
    T[i].op -= m, T[i].cl -= m;
  }
  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] + T[i*2+1];


  int ans = inf;
  REP(i, n) {
    if (C[i].size() == 0) continue;

    for (int j: C[i]) add(h[j], -1);

    int lo = h[i], hi = m - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (test(i, mid)) hi = mid; else
        lo = mid + 1;
    }
    
    if (test(i, lo)) ans = min(ans, v[lo] - v[h[i]]);
    for (int j: C[i]) add(h[j], +1);
  }

  if (ans >= inf) ans = -1;
  printf("%d\n", ans);
  return 0;
}