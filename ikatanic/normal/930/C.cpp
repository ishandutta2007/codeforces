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

const int MAX = 100100;

int L[MAX];

void update(int x, int v) {
  for (++x; x < MAX; x += x&-x) {
    L[x] = max(L[x], v);
  }
}

int query(int x) {
  int r = 0;
  for (++x; x > 0; x -= x&-x) {
    r = max(r, L[x]);
  }
  return r;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<int> f(m+1, 0);
  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    f[a]++, f[b+1]--;
  }

  vector<int> a(m);
  int s = 0;
  REP(i, m) {
    s += f[i];
    a[i] = s;
  }

  vector<int> fl(m);
  REP(i, m) {
    fl[i] = query(a[i]) + 1;
    update(a[i], fl[i]);
  }

  REP(i, MAX) L[i] = 0;
  vector<int> fr(m);
  for (int i = m-1; i >= 0; --i) {
    fr[i] = query(a[i]) + 1;
    update(a[i], fr[i]);
  }

  int ans = 0;
  REP(i, m) ans = max(ans, fl[i] + fr[i] - 1);
  printf("%d\n", ans);
  return 0;
}