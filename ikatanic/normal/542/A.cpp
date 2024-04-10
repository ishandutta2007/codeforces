#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;

const int MAX = 500200;
const int inf = 1e9;

struct Interval {
  int l, r, c, i;
} x[MAX], y[MAX];

enum {STARTX, ENDX, ENDY};

struct Event {
  int x, tip, i;
  friend bool operator < (const Event &a, const Event &b) {
    if (a.x != b.x) return a.x > b.x;
    return a.tip < b.tip;
  }
};

par L[MAX];

par get_max(int x) {
  par r = {-1, -1};
  for (++x; x; x -= x&-x)
    r = max(r, L[x]);
  return r;
}

void update(int x, par p) {
  for (++x; x < MAX; x += x&-x)
    L[x] = max(L[x], p);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d %d", &x[i].l, &x[i].r);
  REP(i, m) scanf("%d %d %d", &y[i].l, &y[i].r, &y[i].c);
  REP(i, n) x[i].i = i;
  REP(i, m) x[i].i = i;

  llint best = 0;
  int xi, yi;
  
  auto test = [&] (int i, int j) {
    int l = max(x[i].l, y[j].l);
    int r = min(x[i].r, y[j].r);
    if (l >= r) return;

    llint score = llint(r-l) * y[j].c;
    if (score > best) best = score, xi = i, yi = j;
  };

  REP(step, 2) {
    static vector<int> v; v.clear();
    REP(i, n) v.push_back(x[i].r);
    REP(i, m) v.push_back(y[i].r);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    auto get_idx = [&] (int x) {
      return lower_bound(v.begin(), v.end(), x) - v.begin();
    };

    static vector<Event> E; E.clear();
    REP(i, n) {
      E.push_back({x[i].r, STARTX, i});
      E.push_back({x[i].l, ENDX, i});
    }
    
    REP(i, m) {
      E.push_back({y[i].l, ENDY, i});
    }
    
    sort(E.begin(), E.end());
    REP(i, MAX) L[i] = {-1, -1};

    static set<par> S; S.clear();
    for (auto &e: E) {
      if (e.tip == STARTX) S.insert({x[e.i].r, e.i});
      if (e.tip == ENDX) {
        S.erase({x[e.i].r, e.i});
        update(get_idx(x[e.i].r), {x[e.i].r-x[e.i].l, e.i});
      }
      if (e.tip == ENDY) {
        if (S.size()) test((--S.end())->second, e.i);
        auto ins = get_max(get_idx(y[e.i].r));
        if (ins.second != -1) test(ins.second, e.i);
      }
    }

    REP(i, n) {
      swap(x[i].l, x[i].r);
      x[i].l = inf - x[i].l;
      x[i].r = inf - x[i].r;
    }
    REP(i, m) {
      swap(y[i].l, y[i].r);
      y[i].l = inf - y[i].l;
      y[i].r = inf - y[i].r;
    }
  }

  printf("%lld\n", best);
  if (best > 0) printf("%d %d\n", xi+1, yi+1);

  return 0;
}