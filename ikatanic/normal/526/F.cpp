#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;
#define x first
#define idx second

const int MAXN = 1<<19;
const int off = 1<<19;
const int inf = 1e9;

struct data {
  int mini, cnt, s;

  void prop(int d) {
    s += d;
    mini += d;
  }
};

data operator + (const data &a, const data &b) {
  int nmini = min(a.mini, b.mini);
  return {nmini, (a.mini == nmini)*a.cnt + (b.mini == nmini)*b.cnt, 0};
}

data T[2*off];
int a[MAXN];
int n;

void inc(int i, int lo, int hi, int a, int b, int v) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    T[i].prop(v);
    return;
  }
  
  if (T[i].s) {
    T[i*2].prop(T[i].s);
    T[i*2+1].prop(T[i].s);
    T[i].s = 0;
  }

  inc(i*2, lo, (lo+hi)/2, a, b, v);
  inc(i*2+1, (lo+hi)/2, hi, a, b, v);
  T[i] = T[i*2] + T[i*2+1];
}

llint brute() {
  llint ans = 0;
  REP(i, n) {
    int maks = 0, mini = n;
    for (int j = i; j < n; ++j) {
      maks = max(maks, a[j]);
      mini = min(mini, a[j]);
      if (maks-mini-j <= -i) ans++;
    }
  }
  return ans;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    int r, c;
    scanf("%d %d", &r, &c); --r, --c;
    a[r] = c;
  }
  
  REP(i, off) T[off+i] = {n, 1, 0};
  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] + T[i*2+1];

  llint ans = 0;

  static stack<par> Smin, Smax;
  Smin.push({-inf, n});
  Smax.push({+inf, n});
  
  for (int i = n-1; i >= 0; --i) {
    inc(1, 0, off, i, i+1, -n-i);

    while (a[i] <= Smin.top().x) {
      int val = Smin.top().x;
      int idx = Smin.top().idx; Smin.pop();
      inc(1, 0, off, idx, Smin.top().idx, +val);
    }
    inc(1, 0, off, i, Smin.top().idx, -a[i]);
    Smin.push({a[i], i});
    
    while (a[i] >= Smax.top().x) {
      int val = Smax.top().x;
      int idx = Smax.top().idx; Smax.pop();
      inc(1, 0, off, idx, Smax.top().idx, -val);
    }
    inc(1, 0, off, i, Smax.top().idx, +a[i]);
    Smax.push({a[i], i});

    if (T[1].mini == -i) ans += T[1].cnt;
  }
  
  //  printf("%lld\n", brute());
  printf("%lld\n", ans);
  return 0;
}