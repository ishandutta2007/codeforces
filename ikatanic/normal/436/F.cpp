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

const int MAXN = 100100;
const int K = 300;
const int MAXB = MAXN/K + 10;
const llint inf = 1e18;

struct Line {
  llint k, l, id;
  llint eval(llint x) {
    return k * x + l;
  }
};

int ccw(const Line &a, const Line &b, const Line &c) {
  llint w = 0;
  w += a.k * (b.l - c.l);
  w += b.k * (c.l - a.l);
  w += c.k * (a.l - b.l);
  return w < 0 ? -1 : w > 0;
}

struct User {
  int p, c;
  friend bool operator < (const User &a, const User &b) {
    return a.p > b.p;
  }
} a[MAXN];

vector<int> e[MAXN];
pair<llint, llint> ans[MAXN];
vector<Line> V[MAXB], H[MAXB];
llint x[MAXB];
int ptr[MAXB];
int m;

void sweep(int i) {
  while (ptr[i]+1 < (int)H[i].size() && H[i][ptr[i]].eval(x[i]) < H[i][ptr[i] + 1].eval(x[i])) ptr[i]++;
}

void rebuild(int i) {
  vector<Line> &h = H[i];
  h.clear();
  for (Line &l: V[i]) {
    while (h.size() >= 2 && ccw(h[(int)h.size()-2], h.back(), l) <= 0) h.pop_back();
    h.push_back(l);
  }
  ptr[i] = 0;
  sweep(i);
}

void remove(int i) {
  int idx = -1;
  vector<Line> &v = V[i / K];
  REP(j, (int)v.size())
    if (v[j].id == i) idx = j; else
      if (idx != -1) v[j].l -= v[j].k;
  
  assert(idx != -1);
  v.erase(v.begin() + idx);
  rebuild(i / K);

  FOR(j, i/K+1, m) {
    x[j]--;
    sweep(j);
  }
}

pair<llint, llint> get_best() {
  pair<llint, llint> ans = {0LL, 0LL};
  REP(j, m) {
    if (H[j].size() == 0) continue;
    ans = max(ans, {H[j][ptr[j]].eval(x[j]), a[H[j][ptr[j]].id].p});
  }
  return ans;
}

int main(void) {
  int n, w;
  scanf("%d %d", &n, &w);
  REP(i, n) scanf("%d %d", &a[i].p, &a[i].c);  

  sort(a, a + n);
  REP(i, n) {
    e[a[i].c].push_back(i);
    V[i / K].push_back({a[i].p, llint(i+1) * a[i].p, i});
    x[i / K] = 0;
  }
  
  m = (n-1)/K + 1;
  REP(i, m)
    rebuild(i);
  
  int L = 0;
  REP(i, n) L = max(L, a[i].c + 1);
  
  int free_cnt = 0;
  for (int c = L; c >= 0; --c) {
    for (int i: e[c]) {
      remove(i);
      free_cnt++;
    }
    
    ans[c] = get_best();
    ans[c].first += llint(free_cnt) * c * w;
  }

  REP(c, L+1)
    printf("%lld %lld\n", ans[c].first, ans[c].second);
  return 0;
}