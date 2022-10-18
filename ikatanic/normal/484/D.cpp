#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;
#define v first
#define i second

const int MAXN = 1<<21;
const int offset = 1<<20;
const int inf = 2e9;

int a[MAXN];
llint T[MAXN], S[MAXN];

stack<par> Smin, Smax;

void propagate(int i) {
  S[i*2] += S[i], T[i*2] += S[i];
  S[i*2+1] += S[i], T[i*2+1] += S[i];
  S[i] = 0;
}

void inc(int i, int lo, int hi, int a, int b, llint k) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) { S[i] += k; T[i] += k; return; }
  if (S[i]) propagate(i);
  inc(i*2, lo, (lo+hi)/2, a, b, k);
  inc(i*2+1, (lo+hi)/2, hi, a, b, k);
  T[i] = max(T[i*2], T[i*2+1]);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  
  Smin.push({-inf, -1});
  Smax.push({+inf, -1});

  REP(i, n) {
    inc(1, 0, offset, i, i+1, T[1]);

    while (Smax.top().v <= a[i]) {
      auto t = Smax.top(); Smax.pop();
      inc(1, 0, offset, Smax.top().i+1, t.i+1, a[i] - t.v);
    }
    Smax.push({a[i], i});
    
    while (Smin.top().v >= a[i]) {
      auto t = Smin.top(); Smin.pop();
      inc(1, 0, offset, Smin.top().i+1, t.i+1, t.v - a[i]);
    }
    Smin.push({a[i], i});
  }

  printf("%lld\n", T[1]);
  return 0;
}