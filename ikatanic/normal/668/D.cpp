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

const int MAX = 1001000;

int L[MAX];

int SZ;

int sum(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

void add(int x, int v) {
  for (++x; x < SZ; x += x&-x)
    L[x] += v;
}

int a[MAX], t[MAX], x[MAX];
int ans[MAX];
vector<int> q[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d %d", &a[i], &t[i], &x[i]);

  vector<int> v(x, x + n);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  
  REP(i, n) {
    x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
    q[x[i]].push_back(i);
  }

  REP(i, (int)v.size()) {
    int m = q[i].size();
    vector<int> w(m);
    REP(j, m) w[j] = t[q[i][j]];
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    SZ = w.size() + 1;
    REP(j, SZ + 1) L[j] = 0;

    REP(j, m) {
      int idx = q[i][j];
      int tt = lower_bound(w.begin(), w.end(), t[idx]) - w.begin();
      if (a[idx] == 1) add(tt, +1);
      else if (a[idx] == 2) add(tt, -1);
      else ans[idx] = sum(tt);
    }
  }

  REP(i, n) if (a[i] == 3) printf("%d\n", ans[i]);
  return 0;
}