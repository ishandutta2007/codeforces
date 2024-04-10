#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int off = 1<<19;
const int MAX = 300300;
const int K = 5;

struct data {
  pair<int, int> v[K];
  int sz = 0;

  void fix() {
    if (sz == K) {
      int min_cnt = v[0].second;
      REP(i, sz) min_cnt = min(min_cnt, v[i].second);
      REP(i, sz) {
        v[i].second -= min_cnt;
        if (v[i].second == 0) {
          swap(v[i], v[sz-1]);
          sz--;
          i--;
        }
      }
    }
  }

  friend data operator + (const data& a, const data& b) {
    data c = a;
    REP(i, b.sz) {
      bool found = false;
      REP(j, c.sz) {
        if (b.v[i].first == c.v[j].first) {
          c.v[j].second += b.v[i].second;
          found = true;
          break;
        }
      }
      
      if (!found) {
        c.v[c.sz++] = b.v[i];
        c.fix();
      }
    }
    return c;
  }
};

data empty;

data T[2*off];
vector<int> pos[MAX];

int count(int l, int r, int x) {
  return upper_bound(pos[x].begin(), pos[x].end(), r-1) - lower_bound(pos[x].begin(), pos[x].end(), l);
}

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return empty;
  if (lo >= a && hi <= b) return T[i];
  return query(i*2, lo, (lo+hi)/2, a, b) + query(i*2+1, (lo+hi)/2, hi, a, b);
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    pos[x].push_back(i);
    T[off + i].v[T[off + i].sz++] = {x, 1};
  }

  for (int i = off-1; i > 0; --i) {
    T[i] = T[2*i] + T[2*i+1];
  }
  
  REP(i, q) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);

    --l;

    data d = query(1, 0, off, l, r);
    int ans = -1;
    REP(i, d.sz) {
      int x = d.v[i].first;
      if (count(l, r, x) * k > r-l) {
        if (ans == -1 || x < ans) ans = x;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}