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

const int MAXN = 100100;

int a[MAXN], b[MAXN];
int c[MAXN], w[MAXN];

int n, d;
llint x;

int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}

void initAB() {
  REP(i, n)
    a[i] = i;
  REP(i, n)
    swap(a[i], a[getNextX() % (i + 1)]);
  REP(i, n)
    w[a[i]] = i;
  REP(i, n)
    b[i] = (i < d);
  REP(i, n)
    swap(b[i], b[getNextX() % (i + 1)]);
}

int main(void) {
  cin >> n >> d >> x;
  initAB();
  REP(i, n) c[i] = -1;

  if (d < 1000) {
    vector<int> v;
    REP(i, n)
      if (b[i]) v.push_back(i);
    REP(i, n) REP(j, d)
      if (v[j] <= i) c[i] = max(c[i], a[i - v[j]]);
  } else {
    static set<int> S;
    REP(i, n) S.insert(i);
    for (int x = n-1; x >= 0; --x) {
      int j = w[x];
      static vector<int> v; v.clear();
      for (int i: S)
        if (j <= i && b[i-j]) v.push_back(i);
      for (int i: v) {
        c[i] = x;
        S.erase(i);
      }
    }
  }

  REP(i, n) printf("%d\n", c[i]+1);
  return 0;
}