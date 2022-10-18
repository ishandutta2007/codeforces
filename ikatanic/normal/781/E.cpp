#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int off = 1<<17;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

set<int, greater<int>> T[2*off];

int getMax(int x) {
  int ret = -1;
  for (x += off; x; x /= 2) {
    if (T[x].size()) ret = max(ret, *T[x].begin());
  }
  return ret;
}

void update(int i, int lo, int hi, int a, int b, int x, int k) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    if (k > 0) {
      T[i].insert(x);
    } else {
      T[i].erase(x);
    }
    return;
  }
  update(i*2, lo, (lo+hi)/2, a, b, x, k);
  update(i*2+1, (lo+hi)/2, hi, a, b, x, k);
}

struct Barrier {
  int x, l, r, s;
};

int main(void) {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);

  vector<Barrier> barriers;
  vector<pair<int, int>> queries;
  REP(i, n) {
    int u, l, r, s;
    scanf("%d %d %d %d", &u, &l, &r, &s);
    --u, --l, --r;
    barriers.push_back({u, l, r, s});

    if (l > 0) queries.push_back({u, l-1});
    if (r+1 < w) queries.push_back({u, r+1});
  }
  REP(i, w) queries.push_back({h, i});

  sort(barriers.begin(), barriers.end(), [] (const Barrier& a, const Barrier& b) {
      return a.x < b.x;
    }
  );
  
  vector<pair<int, int>> events;
  REP(i, n) {
    events.push_back({barriers[i].x, i});
    events.push_back({barriers[i].x + barriers[i].s + 1, i});
  }
  events.push_back({h+1, -1});
  
  sort(events.begin(), events.end());
  sort(queries.begin(), queries.end());

  map<pair<int, int>, int> g;
  
  auto it = queries.begin();
  for (auto& event: events) {
    while (it != queries.end() && it->first < event.first) {
      g[*it] = getMax(it->second);
      it++;
    }

    if (event.second >= 0) {
      int i = event.second;
      if (barriers[i].x == event.first) {
        update(1, 0, off, barriers[i].l, barriers[i].r+1, i, +1);
      } else {
        update(1, 0, off, barriers[i].l, barriers[i].r+1, i, -1);
      }
    }
  }



  vector<int> f(n, 0);

  auto getF = [&] (int x, int y) {
    assert(g.count({x, y}));
    int i = g[{x, y}];
    return i == -1 ? 1 : f[i];
  };
  
  REP(i, n) {
    f[i] = 0;

    if (barriers[i].l > 0) {
      f[i] = add(f[i], getF(barriers[i].x, barriers[i].l-1));
    } else {
      f[i] = add(f[i], getF(barriers[i].x, barriers[i].r+1));
    }

    if (barriers[i].r+1 < w) {
      f[i] = add(f[i], getF(barriers[i].x, barriers[i].r+1));
    } else {
      f[i] = add(f[i], getF(barriers[i].x, barriers[i].l-1));
    }
  }


  int ans = 0;
  REP(i, w) ans = add(ans, getF(h, i));
  printf("%d\n", ans);
  return 0;
}