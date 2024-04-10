#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 300300;
const int inf = 1e9 + 1;

struct DSU {
  int dad[MAX];
  int rank[MAX];
  int sz[MAX];
  int cnt_odd;

  struct Change {
    int* ptr;
    int old, t;
  };

  stack<Change> S;

  void init(int n) {
    for (int i = 0; i < n; ++i)
      dad[i] = i, rank[i] = 0, sz[i] = 1;
    cnt_odd = n;
  }

  void set(int* p, int val, int t) {
    if (val != *p) {
      S.push({p, *p, t});
      *p = val;
    }
  }

  void revert(int t) {
    while (!S.empty() && S.top().t == t) {
      *S.top().ptr = S.top().old;
      S.pop();
    }
  }

  int findset(int x, int t) {
    if (x == dad[x]) return x;
    set(&dad[x], findset(dad[x], t), t);
    return dad[x];
  }

  void merge(int x, int y, int t) {
    x = findset(x, t);
    y = findset(y, t);
    if (x == y) return;

    if (rank[x] > rank[y]) swap(x, y);
    set(&dad[x], y, t);
    if (rank[x] == rank[y]) set(&rank[y], rank[y] + 1, t);
    if (sz[x]%2 && sz[y]%2) set(&cnt_odd, cnt_odd - 2, t);
    set(&sz[y], sz[y] + sz[x], t);
  }
} D;

struct Edge {
  int a, b, w, i;
  friend bool operator < (const Edge& a, const Edge& b) {
    return a.w < b.w;
  }
};

int ans[MAX];
Edge E[MAX], W[MAX];
int n, m;

void solve(int l, int r, int lo, int hi) {
  if (l >= r) return;
  if (lo > hi) {
    FOR(i, l, r) ans[i] = inf;
    return;
  }

  int mid = (l + r) / 2;

  static Edge e[2*MAX];
  int c = 0;
  FOR(i, l, mid+1) e[c++] = E[i];
  int fr = lower_bound(W, W + m, (Edge){0, 0, lo + 1, 0}) - W;
  for (int i = fr; i < m && W[i].w <= hi; ++i) 
    if (W[i].i < l) e[c++] = W[i];
  sort(e, e + c);
  
  int i = 0, last = lo;
  while (i < c && D.cnt_odd > 0) {
    D.merge(e[i].a, e[i].b, mid);
    last = max(last, e[i].w);
    i++;
  }

  ans[mid] = D.cnt_odd > 0 ? inf : last;
  D.revert(mid);
  
  for (int i = fr; i < m && W[i].w <= hi; ++i) 
    if (W[i].i < l && W[i].w <= ans[mid]) D.merge(W[i].a, W[i].b, mid);

  solve(l, mid, ans[mid], hi);
  D.revert(mid);

  FOR(i, l, mid+1)
    if (E[i].w <= lo) D.merge(E[i].a, E[i].b, mid);

  solve(mid+1, r, lo, ans[mid]);
  D.revert(mid);
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w); --a, --b;
    E[i] = W[i] = {a, b, w, i};
  }
  sort(W, W + m);

  D.init(n);
  solve(0, m, 0, 1e9);

  REP(i, m) {
    if (ans[i] >= inf) ans[i] = -1;
    printf("%d\n", ans[i]);
  }
  return 0;
}