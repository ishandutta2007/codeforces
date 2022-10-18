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

const llint inf = 1e18;

const int MAX = 110000;
const int K = 300;

struct line {
  llint k, l;
  int i;
  friend bool operator < (const line& a, const line& b) {
    if (a.k != b.k) return a.k < b.k;
    return a.i < b.i;
  }
  llint eval(llint x) { return k*x + l; }
};

llint ccw(const line& a, const line& b, const line& c) {
  llint w = 0;
  w += a.k * (b.l - c.l);
  w += b.k * (c.l - a.l);
  w += c.k * (a.l - b.l);
  return w < 0 ? -1 : w > 0;
}

int a[MAX];
vector<line> v[MAX / K];
vector<line> h[MAX / K];
int x[MAX / K];
llint y[MAX / K];
int p[MAX / K];

void hull(int j) {
  vector<line>& a = v[j];
  vector<line>& b = h[j];

  b.clear();
  for (line& p: a) {
    while (b.size() >= 2 && ccw(b[b.size()-2], b.back(), p) >= 0) b.pop_back();
    b.push_back(p);
  }

  p[j] = 0;
  while (p[j] + 1 < (int)b.size() && b[p[j]].eval(x[j]) < b[p[j]+1].eval(x[j])) p[j]++;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int g = (n + K - 1) / K;
  REP(i, n) {
    scanf("%d", &a[i]);
    v[i/K].push_back({a[i], 0, i});
  }

  REP(i, g) {
    sort(v[i].begin(), v[i].end());
    hull(i);
    x[i] = 1;
  }

  llint ans = 0;
  llint cur = 0;
  REP(i, n) {
    llint best = -inf;
    int who = -1;
    REP(j, g) {
      if (h[j].size() == 0) continue;
      while (p[j] + 1 < (int)h[j].size() && h[j][p[j]].eval(x[j]) < h[j][p[j]+1].eval(x[j])) p[j]++;

      llint score = h[j][p[j]].eval(x[j]) + y[j];
      if (score > best) {
        best = score;
        who = j;
      }
    }

    assert(who != -1);
    
    cur += best;
    ans = max(ans, cur);
    int idx = h[who][p[who]].i;
    REP(j, who) y[j] += a[idx];
    FOR(j, who + 1, g) x[j]++;

    int vidx = -1;
    REP(k, (int)v[who].size()) {
      if (v[who][k].i < idx) v[who][k].l += a[idx];
      if (v[who][k].i > idx) v[who][k].l += v[who][k].k;
      if (v[who][k].i == idx) vidx = k;
    }
    v[who].erase(v[who].begin() + vidx);
    hull(who);
  }

  printf("%lld\n", ans);
  return 0;
}