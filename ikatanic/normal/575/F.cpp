#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 10100;
const llint inf = 1e18;

llint f[MAX];
llint fp[MAX], fn[MAX];
int l[MAX], r[MAX];

int cost(int i, int pos) {
  if (pos < l[i]) return l[i] - pos;
  if (pos > r[i]) return pos - r[i];
  return 0;
}

int main(void) {
  int n, x;
  scanf("%d %d", &n, &x);
  REP(i, n) scanf("%d %d", &l[i], &r[i]);
  vector<int> v = {x};
  REP(i, n) {
    v.push_back(l[i]);
    v.push_back(r[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int m = v.size();
  REP(j, m) f[j] = (v[j] == x ? 0 : inf);

  REP(i, n) {
    // fp[i] = min (f[j]+v[j]), j >= i
    // fn[i] = min (f[j]-v[j]), j <= i
    llint cur = inf;
    REP(j, m)
      fn[j] = cur = min(cur, f[j] - v[j]);
    cur = inf;
    for (int j = m-1; j >= 0; --j)
      fp[j] = cur = min(cur, f[j] + v[j]);

    REP(j, m)
      f[j] = cost(i, v[j]) + min(fn[j] + v[j], fp[j] - v[j]);
  }

  llint ans = *min_element(f, f + m);
  printf("%lld\n", ans);
  return 0;
}