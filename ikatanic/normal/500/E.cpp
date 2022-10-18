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
typedef pair<int, int> par;

const int MAXN = 200100;
const int LG = 20;

int f[MAXN], w[MAXN];
int p[MAXN], l[MAXN];
int r[MAXN];
int L[MAXN][LG];
llint C[MAXN][LG];

par loga[MAXN];

void update(int x, par p) {
  for (++x; x < MAXN; x += x&-x)
    loga[x] = max(loga[x], p);
}

par getmaks(int x) {
  par r = {0, 0};
  for (++x; x; x -= x&-x)
    r = max(r, loga[x]);
  return r;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", p+i, l+i);
  
  p[n] = 1e9, l[n] = 0;
  f[n] = n, w[n] = 0;
  r[n] = 1e9;

  for (int i = n-1; i >= 0; --i) {
    int j = lower_bound(p + i, p + n, p[i] + l[i] + 1) - p - 1;
    assert(i <= j && j < n && p[j] <= p[i] + l[i]);
    par next = getmaks(j);

    if (next.first >= p[i]+l[i]) {
      update(i, next);
      f[i] = next.second;
      w[i] = 0;
      r[i] = next.first;
    } else {
      update(i, {p[i] + l[i], i});
      r[i] = p[i] + l[i];
      f[i] = j + 1;
      w[i] = p[j+1] - (p[i] + l[i]);
    }
  }
  
  REP(i, n+1) L[i][0] = f[i], C[i][0] = w[i];
  FOR(j, 1, LG) REP(i, n+1) {
      L[i][j] = L[ L[i][j-1] ][j-1];
      C[i][j] = C[i][j-1] + C[ L[i][j-1] ][j-1];
    }

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;

    llint ans = 0;
    for (int j = LG-1; j >= 0; --j) {
      int k = L[x][j];
      if (r[k] < p[y]) {
        ans += C[x][j];
        x = L[x][j];
      }
    }

    if (r[x] < p[y]) ans += w[x];
    printf("%lld\n", ans);
  }
  return 0;
}