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
typedef pair<llint, int> par;
#define s first
#define x second

const int MAXN = 1010;
const int MAXK = 1000100;

int a[MAXN][MAXN];
llint fr[MAXK], fc[MAXK];

typedef set<par, greater<par>> pq;
pq sr, sc;

void solve(pq &sr, llint fr[MAXK], int k, int p, int m) {
  fr[0] = 0;
  for (int i = 1; i <= k; ++i) {
    fr[i] = fr[i-1];
    auto w = *sr.begin(); sr.erase(sr.begin());
    fr[i] += w.s;
    w.s -= m*p;
    sr.insert(w);
  }
}

int main(void) {
  int n, m, k, p;
  scanf("%d %d %d %d", &n, &m, &k, &p);
  REP(i, n) REP(j, m) scanf("%d", a[i]+j);
  REP(i, n) {
    llint s = 0;
    REP(j, m) s += a[i][j];
    sr.insert({s, i});
  }
  REP(j, m) {
    llint s = 0;
    REP(i, n) s += a[i][j];
    sc.insert({s, j});
  }
  
  solve(sr, fr, k, p, m);
  solve(sc, fc, k, p, n);

  llint ans = -1e18;
  REP(A, k+1) {
    int B = k-A;
    ans = max(ans, fr[A] + fc[B] - llint(A)*B*p);
  }

  cout << ans << endl;
  return 0;
}