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

const int MAXN = 500500;
const int MAXK = 55;

struct DSU {
  int dad[MAXN];
  int rank[MAXN];
  int color[MAXN];

  struct Change {
    int* ptr;
    int old, t;
  };

  stack<Change> S;

  void init(int n) {
    REP(i, n) dad[i] = i, rank[i] = color[i] = 0;
  }

  void set(int* p, int val, int t) {
    if (val != *p) {
      S.push({p, *p, t});
      *p = val;
    }
  }

  void undo(int t) {
    while (!S.empty() && S.top().t == t) {
      *S.top().ptr = S.top().old;
      S.pop();
    }
  }

  int findset(int x, int t) {
    if (x == dad[x]) return x;
    int ndad = findset(dad[x], t);
    set(&color[x], color[x]^color[dad[x]], t);
    set(&dad[x], ndad, t);
    return dad[x];
  }

  void merge(int x, int y, int t) {
    findset(x, t), findset(y, t);
    int ncolor = color[x] ^ color[y] ^ 1;
    x = dad[x], y = dad[y];
    if (x == y) return;

    if (rank[x] > rank[y]) swap(x, y);
    set(&dad[x], y, t);
    set(&color[x], ncolor, t);
    if (rank[x] == rank[y]) set(&rank[y], rank[y] + 1, t);
  }

  int getColor(int x, int t) {
    findset(x, t);
    return color[x];
  }

  int connected(int x, int y, int t) {
    return findset(x, t) == findset(y, t);
  }
} f[MAXK];

const int off = 1<<19;

int a[MAXN], b[MAXN];
int e[MAXN], c[MAXN];
int nxt[MAXN], lst[MAXN];
int color[MAXN];
bool ans[MAXN];
int n, m, q, k;

vector<pair<int, int>> T[2*off];

void add(int i, int lo, int hi, int a, int b, pair<int, int> p) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    T[i].push_back(p);
    return;
  }
  add(i*2, lo, (lo+hi)/2, a, b, p);
  add(i*2+1, (lo+hi)/2, hi, a, b, p);
}

void traverse(int i) {
  for (auto& p: T[i])
    f[p.second].merge(a[p.first], b[p.first], i);

  if (i >= off) {
    int j = i-off;
    if (j < q) {
      ans[j] = !(f[c[j]].connected(a[e[j]], b[e[j]], i) && f[c[j]].getColor(a[e[j]], i) == f[c[j]].getColor(b[e[j]], i));
      if (ans[j]) {
        add(1, 0, off, j + 1, nxt[j] + 1, {e[j], c[j]});
        color[e[j]] = c[j];
      } else {
        if (color[e[j]] != -1) add(1, 0, off, j + 1, nxt[j] + 1, {e[j], color[e[j]]});
      }
      f[c[j]].undo(i);
    }
  } else {
    traverse(i*2);
    traverse(i*2+1);
  }

  for (auto& p: T[i])
    f[p.second].undo(i);
}

int main(void) {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  REP(i, m) {
    scanf("%d %d", &a[i], &b[i]); 
    --a[i], --b[i];
  }
  REP(i, q) {
    scanf("%d %d", &e[i], &c[i]);
    --e[i], --c[i];
  }

  REP(i, m) lst[i] = q, color[i] = -1;
  for (int i = q-1; i >= 0; --i) {
    nxt[i] = lst[ e[i] ];
    lst[ e[i] ] = i;
  }

  REP(i, k) f[i].init(n);
  traverse(1);
  REP(i, q) puts(ans[i] ? "YES" : "NO");
  return 0;
}