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

const int off = 1<<17;

struct Tournament {
  llint T[2*off][10];
  int S[2*off][10];


  Tournament() {
    REP(i, 2*off) REP(j, 10) S[i][j] = j;
  }
  
  void add(int x, int j, int v) {
    for (x += off; x; x /= 2) {
      T[x][j] += v;
    }
  }

  void mapNode(int i, int x, int y) {
    if (x == y) return;
    REP(j, 10)
      if (S[i][j] == x) S[i][j] = y;
    T[i][y] += T[i][x];
    T[i][x] = 0;
  }

  void prop(int i) {
    FOR(k, i*2, i*2+2) {
      static int nS[10];
      static llint nT[10];
      REP(l, 10) nS[l] = 0, nT[l] = 0;
      REP(l, 10) {
        nS[l] = S[i][ S[k][l] ];
        nT[ S[i][l] ] += T[k][l];
      }
      REP(l, 10) S[k][l] = nS[l], T[k][l] = nT[l];
    }
    REP(j, 10) S[i][j] = j;
  }
  
  void map(int i, int lo, int hi, int a, int b, int x, int y) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) {
      mapNode(i, x, y);
      return;
    }

    prop(i);
    map(i*2, lo, (lo+hi)/2, a, b, x, y);
    map(i*2+1, (lo+hi)/2, hi, a, b, x, y);
    REP(j, 10) T[i][j] = T[i*2][j] + T[i*2+1][j];
  }

  llint sum(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return 0;
    if (lo >= a && hi <= b) {
      llint ret = 0;
      REP(j, 10) ret += T[i][j] * j;
      return ret;
    }

    prop(i);
    return
      sum(i*2, lo, (lo+hi)/2, a, b) + 
      sum(i*2+1, (lo+hi)/2, hi, a, b);
  }
  
  void map(int x, int y, int l, int r) {
    if (x == y) return;
    map(1, 0, off, l, r, x, y);
  }

  llint sum(int x, int y) {
    return sum(1, 0, off, x, y);
  }
} T;

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) {
    int x;
    scanf("%d", &x);

    llint pw = 1;
    while (x > 0) {
      T.add(i, x%10, pw);
      x /= 10;
      pw *= 10;
    }
  }

  while (q--) {
    int tip, l, r;
    scanf("%d %d %d", &tip, &l, &r); --l;
    
    if (tip == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      T.map(x, y, l, r);
    } else {
      printf("%lld\n", T.sum(l, r));
    }
  }
      
  return 0;
}