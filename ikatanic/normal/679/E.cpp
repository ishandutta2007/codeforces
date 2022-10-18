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

const int K = 12;
const int MAXN = 100100;
const int off = 1<<17;
const llint inf = 1e18;

struct Tournament {
  struct data {
    llint inc, set;
    llint maks;
    int l, r;

    void pset(llint v) {
      inc = 0;
      set = maks = v;
    }

    void pinc(llint v) {
      if (set) {
        set += v;
      } else {
        inc += v;
      }
      maks += v;
    }
  } T[2*off];

  void update(int i) {
    if (T[i*2].maks > T[i*2+1].maks) {
      T[i].maks = T[i*2].maks;
      T[i].l = T[i*2].l;
      T[i].r = T[i*2].r;
    } else if (T[i*2].maks < T[i*2+1].maks) {
      T[i].maks = T[i*2+1].maks;
      T[i].l = T[i*2+1].l;
      T[i].r = T[i*2+1].r;
    } else {
      T[i].maks = T[i*2].maks;
      T[i].l = T[i*2].l;
      T[i].r = T[i*2].r;
      if (T[i*2].r == T[i*2+1].l) T[i].r = T[i*2+1].r;
    }
  }

  void init() {
    REP(i, off) {
      T[off+i].maks = T[off+i].set = -inf;
      T[off+i].l = i;
      T[off+i].r = i + 1;
    }
    for (int i = off-1; i > 0; --i)
      update(i);
  }

  void propagate(int i) {
    if (T[i].set) {
      T[i*2].pset(T[i].set);
      T[i*2+1].pset(T[i].set);
      T[i].set = 0;
    }
    if (T[i].inc) {
      T[i*2].pinc(T[i].inc);
      T[i*2+1].pinc(T[i].inc);
      T[i].inc = 0;
    }
  }

  void inc(llint v, int a, int b, int i = 1, int lo = 0, int hi = off) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) {
      T[i].pinc(v);
      return;
    }
    
    propagate(i);
    inc(v, a, b, i*2, lo, (lo+hi)/2);
    inc(v, a, b, i*2+1, (lo+hi)/2, hi);
    update(i);
  }

  void set(llint v, int a, int b, int i = 1, int lo = 0, int hi = off) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) {
      T[i].pset(v);
      return;
    }
    
    propagate(i);
    set(v, a, b, i*2, lo, (lo+hi)/2);
    set(v, a, b, i*2+1, (lo+hi)/2, hi);
    update(i);
  }

  llint getVal(int idx, int i = 1, int lo = 0, int hi = off) {
    assert(lo <= idx && idx < hi);
    if (T[i].set) return T[i].set;

    assert(i < off);
    if (idx < (lo + hi) / 2) {
      return T[i].inc + getVal(idx, i*2, lo, (lo+hi)/2);
    } else {
      return T[i].inc + getVal(idx, i*2+1, (lo+hi)/2, hi);
    }
  }

  pair<llint, pair<int, int>> getMax() {
    return {T[1].maks, {T[1].l, T[1].r}};
  }
} T[K];

vector<llint> bad;

llint queryGet(int i) {
  llint ans = 0;
  REP(j, K) ans = max(ans, T[j].getVal(i));
  return ans;
}

void querySet(int a, int b, llint v, bool clean = false) {
  if (clean) {
    REP(i, K) T[i].set(-inf, a, b);
  }
  int j = 0;
  while (v >= bad[j + 1]) j++;
  T[j].set(v, a, b);
}

void queryInc(int a, int b, int x) {
  bool ch = true;
  while (ch) {
    ch = false;
    vector<pair<llint, pair<int, int>>> move;
    REP(i, K) {
      T[i].inc(x, a, b);
      while (T[i].getMax().first >= bad[i + 1]) {
        auto p = T[i].getMax();
        T[i].set(-inf, p.second.first, p.second.second);
        move.push_back(p);
      }
    }
    for (auto& p: move) {
      querySet(p.second.first, p.second.second, p.first);
      for (llint b: bad)
        ch |= (b == p.first);
    }
  }
}

int main(void) {
  llint cur = 1;
  REP(i, K) {
    bad.push_back(cur);
    cur *= 42;
  }
  bad.push_back(inf);

  REP(i, K) T[i].init();
  
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) {
    int v;
    scanf("%d", &v);
    querySet(i, i + 1, v);
  }  
  
  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      int idx;
      scanf("%d", &idx); --idx;
      printf("%lld\n", queryGet(idx));
    } else {
      int a, b, x;
      scanf("%d %d %d", &a, &b, &x); --a, --b;
      if (type == 2) {
        querySet(a, b + 1, x, true);
      } else {
        queryInc(a, b + 1, x);
      }
    }
  }
  return 0;
}