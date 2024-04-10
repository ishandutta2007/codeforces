#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

template<typename T>
ostream& operator << (ostream& os, vector<T> v) {
  os << "{";
  bool first = true;
  for (auto val : v) {
    if (first) first = false; else os << ", ";
    os << val;
  }
  return os << "}";
}

typedef long long llint;

const int off = 1<<17;
const int MAX = 1<<17;
const int K = 5;

bool e[MAX][K+1];

bool connected(int x, int y) {
  if (x > y) swap(x, y);
  if (y-x <= K) {
    return e[x][y-x];
  }
  return false;
}

struct data {
  int cnt;
  vector<int> c, v;
} T[2*off];


int dad[MAX];
int idx[MAX];
bool have[MAX];

void merge(int x, int y, int m) {
  if (dad[x] == dad[y]) return;
  int v = dad[x];
  REP(i, m) {
    if (dad[i] == v) dad[i] = dad[y];
  }
}

int canonize(vector<int>& v) {
  int m = *max_element(v.begin(), v.end());
  REP(i, m+1) idx[i] = -1;

  int cnt = 0;
  for (auto& x : v) {
    if (idx[x] == -1) {
      idx[x] = cnt++;
    }
    x = idx[x];
  }
  return cnt;
}

data operator + (const data& a, const data& b) {
  if (a.c.size() == 0) return b;
  if (b.c.size() == 0) return a;

  // TRACE(a.cnt _ b.cnt);
  // TRACE(a.c _ a.v);
  // TRACE(b.c _ b.v);
  
  int alen = a.c.size();
  int blen = b.c.size();
  
  REP(i, alen) dad[i] = a.c[i], idx[i] = a.v[i];
  int m = *max_element(dad, dad + alen) + 1;
  REP(i, blen) dad[alen+i] = m + b.c[i], idx[alen+i] = b.v[i];

  
  REP(i, K) {
    if (i < alen) {
      int x = idx[alen-1-i];
      REP(j, K-i) {
        if (j < blen) {
          int y = idx[alen+j];
          if (connected(x, y)) {
            merge(alen-1-i, alen+j, alen+blen);
          }
        }
      }
    }
  }

  REP(i, alen+blen) {
    have[dad[i]] = true;
  }
  
  
  vector<int> c, v;
  REP(i, alen + blen) {
    if (i < K || i >= alen+blen-K) {
      c.push_back(dad[i]);
      v.push_back(idx[i]);
      have[dad[i]] = false;
    }
  }

  int cnt = a.cnt + b.cnt;
  REP(i, alen+blen) {
    if (have[dad[i]]) {
      have[dad[i]] = false;
      cnt++;
    }
  }

  canonize(c);
  //  TRACE(cnt _ c _ v);
  return {cnt, c, v};
}

data empty = {0, {}, {}};

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return empty;
  if (lo >= a && hi <= b) return T[i];
  return
    query(i*2, lo, (lo+hi)/2, a, b) +
    query(i*2+1, (lo+hi)/2, hi, a, b);
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int m;
  scanf("%d", &m);
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    if (x > y) swap(x, y);
    e[x][y-x] = true;
  }

  
  REP(i, off) {
    T[off+i] = {0, {0}, {i}};
  }
  for (int i = off-1; i > 0; --i) {
    T[i] = T[i*2] + T[i*2+1];
  }
  
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r); --l, --r;

    data d = query(1, 0, off, l, r + 1);
    int ans = d.cnt + canonize(d.c);
    //    TRACE(d.cnt _ d.c _ d.v);
    
    printf("%d\n", ans);
  }
  
  return 0;
}