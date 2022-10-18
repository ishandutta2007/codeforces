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
typedef pair<int, int> par;
#define x first
#define y second

const int MAXN = 200020;
const int off = 1<<18;
const int inf = 1e9;

vector<int> E[MAXN], F[MAXN];
bool ans[MAXN];
par a[MAXN];
par q1[MAXN], q2[MAXN];
int n, m, k, q;

int T[2*off];

int getmax(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return -inf;
  if (lo >= a && hi <= b) return T[i];
  return max(
    getmax(i*2, lo, (lo+hi)/2, a, b),
    getmax(i*2+1, (lo+hi)/2, hi, a, b)
  );
}

void update(int x, int v) {
  T[x += off] = v;
  for (x /= 2; x; x /= 2)
    T[x] = max(T[x*2], T[x*2+1]);
}

void solve() {
  REP(i, m) E[i].clear(), F[i].clear();
  REP(i, k) F[a[i].y].push_back(a[i].x);
  REP(i, q) E[q1[i].y].push_back(i);

  REP(i, 2*off) T[i] = inf;
  for (int i = m-1; i >= 0; --i) {
    for (int x: F[i]) update(x, i);
    for (int j: E[i])
      ans[j] |= getmax(1, 0, off, q1[j].x, q2[j].x+1) <= q2[j].y;
  }
}

int main(void) {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  REP(i, k) {
    scanf("%d %d", &a[i].x, &a[i].y);
    --a[i].x, --a[i].y;
  }

  REP(i, q) {
    scanf("%d %d %d %d", &q1[i].x, &q1[i].y, &q2[i].x, &q2[i].y);
    --q1[i].x, --q1[i].y;
    --q2[i].x, --q2[i].y;
    ans[i] = false;
  }

  solve();
  swap(n, m);
  REP(i, k) swap(a[i].x, a[i].y);
  REP(i, q) {
    swap(q1[i].x, q1[i].y);
    swap(q2[i].x, q2[i].y);
  }
  solve();

  REP(i, q) puts(ans[i] ? "YES" : "NO");
  return 0;
}