#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 101000;
const int B = 300;

const int N = MAX / B;

const llint inf = 1e10;

struct Bucket {
  int v[B];
  llint as[B+1];
  llint vs[B+1];
  llint h[B];
  int alive[B];
  bool changed[B];
  
  llint m;
  int ptr, cnt;

  void calcPrefixSums() {
    vs[0] = 0;
    as[0] = 0;
    REP(i, B) {
      vs[i + 1] = vs[i] + alive[v[i]] * h[v[i]];
      as[i + 1] = as[i] + alive[v[i]];
    }
  }
  
  void fix() {
    static int ta[B];
    static int tb[B];

    int tasz = 0, tbsz = 0;
    REP(i, B) {
      int x = v[i];
      h[x] = min(h[x], m);
      
      if (changed[x]) {
        ta[tasz++] = x;
        changed[x] = false;
      } else {
        tb[tbsz++] = x;
      }
    }

    int ia = 0, ib = 0;
    while (ia < tasz || ib < tbsz) {
      if (ib == tbsz) v[ia+ib] = ta[ia], ia++;
      else if (ia == tasz) v[ia+ib] = tb[ib], ib++;
      else if (h[ta[ia]] < h[tb[ib]]) v[ia+ib] = ta[ia], ia++;
      else v[ia+ib] = tb[ib], ib++;
    }

    calcPrefixSums();
    ptr = B-1, cnt = 0;
  }

  void init() {
    REP(i, B) {
      v[i] = i;
      h[i] = inf;
      alive[i] = false;
    }

    m = inf;
    calcPrefixSums();
    ptr = B-1, cnt = 0;
  }
  
  void add(int i) {
    alive[i] = true;
    fix();
  }

  void update(int w) {
    if (w < m) {
      m = w;
      while (ptr >= 0 && h[v[ptr]] > m) ptr--;
    }
  }

  void updateI(int i, int w) {
    if (w < h[i]) {
      changed[i] = true;
      h[i] = w;
    }
  }

  llint getSum() {
    return vs[ptr + 1] + (as[B] - as[ptr + 1]) * 1LL * m;
  }

  llint getOne(int i) {
    return alive[i] * min(m, h[i]);
  }
} v[2][N];

int main(void) {
  REP(j, 2) REP(i, N) v[j][i].init();
  
  int q;
  scanf("%d", &q);

  set<int> nothing, onlyUp, onlyDown, both;

  auto moveSets = [&] (int l, int r, set<int>& A, set<int>& B) {
    while (A.size()) {
      auto it = A.lower_bound(l);
      if (it != A.end() && *it < r) {

        B.insert(*it);
        A.erase(it);
      } else break;
    }
  };
  
  auto addUp = [&] (int l, int r) {
    moveSets(l, r, nothing, onlyUp);
    moveSets(l, r, onlyDown, both);

    for (int x: both) REP(j, 2) v[j][x / B].add(x % B);
    both.clear();
  };

  auto addDown = [&] (int l, int r) {
    moveSets(l, r, nothing, onlyDown);
    moveSets(l, r, onlyUp, both);

    for (int x: both) REP(j, 2) v[j][x / B].add(x % B);
    both.clear();
  };

  REP(i, MAX) nothing.insert(i);
  
  while (q--) {
    int type;
    scanf("%d", &type);
    
    if (type == 1) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      --l, --r;
      
      int idx = 0;
      if (k < 0) {
        k = -k;
        idx = 1;
      }

      int tl = l, tr = r;
      
      if (l % B) {
        int id = l / B;
        while (l % B && l < r) v[idx][id].updateI(l % B, k), l++;
        v[idx][id].fix();
      }

      while (l + B <= r) {
        v[idx][l / B].update(k);
        l += B;
      }

      if (l < r) {
        int id = l / B;
        while (l < r) v[idx][id].updateI(l % B, k), l++;
        v[idx][id].fix();
      }


      if (idx == 0) addUp(tl, tr);
      if (idx == 1) addDown(tl, tr);
    }
    
    if (type == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      --l, --r;
      
      llint ret = 0;
      
      if (l % B) {
        int id = l / B;
        while (l % B && l < r) ret += v[0][id].getOne(l % B) + v[1][id].getOne(l % B), l++;
      }

      while (l + B <= r) {
        ret += v[0][l / B].getSum() + v[1][l / B].getSum();
        l += B;
      }

      if (l < r) {
        int id = l / B;
        while (l < r) ret += v[0][id].getOne(l % B) + v[1][id].getOne(l % B), l++;
      }

      printf("%lld\n", ret);
    }
  }
  
  return 0;
}