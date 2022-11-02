#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXA = 300;

struct M {
  M(): vec(MAXA*MAXA, 0) {}
  M(const M& o): vec(o.vec) {}
  M(M&& o): vec(MAXA*MAXA, 0) {
    swap(vec, o.vec);
  }
  M& operator = (const M& o) {
    vec = o.vec;
    return *this;
  }
  M& operator = (M&& o) {
    swap(vec, o.vec);
    return *this;
  }
  int get(int i, int j) const {
    return vec[i*MAXA+j];
  }
  void set(int i, int j, int v) {
    vec[i*MAXA+j] = v;
  }
  vector<int> vec;
};

void combine(const M& m1, const M& m2, M& out) {
  REP(i,MAXA) FOR(j,i,MAXA-1) {
    int v = 0;
    FOR(k,i,j) {
      v = max(v, m1.get(i, k) + m2.get(k,j));
    }
    out.set(i, j, v);
  }
}

void pow(const M& m, int e, M& out) {
  out = M();
  M p(m);
  while (e) {
    if (e & 1) {
      M t;
      combine(out, p, t);
      swap(out, t);
    }
    M t;
    combine(p, p, t);
    swap(p, t);
    e >>= 1;
  }
}

M base(int n) {
  M m;
  REP(i,n+1) m.set(i,n,1);
  return m;
}

int N, T;
int A[120];

int main() {
  scanf("%d%d", &N, &T);
  REP(i,N) scanf("%d", A+i);
  REP(i,N) --A[i];

  vector<M> ms;
  REP(i,N) ms.push_back(base(A[i]));
  
  M cycle = ms[0];
  M nextCycle;
  FOR(i,1,N-1) {
    combine(cycle, ms[i], nextCycle);
    swap(cycle, nextCycle);
  }
  
  pow(cycle, T, nextCycle);
  swap(cycle, nextCycle);
  
  int best = 0;
  REP(i,MAXA) FOR(j,i,MAXA-1) {
    best = max(best, cycle.get(i,j));
  }
  printf("%d\n", best);
  
  return 0;
}