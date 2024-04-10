#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, MAX = 3e5 + 105;

int n;
int X[MAXN], Y[MAXN];
unordered_map<int, int> l, r, lo, hi;
unordered_map<int, vector<int>> add, del;

vector<int> evx[MAX][2], evy[MAX][2];

int L[MAX][2];
void upd(int x, int v) {
  x += MAXN + 5;
  int K = x % 2;
  for(; x < MAX; x += x & -x) L[x][K] += v;
}
int get(int x, int K) {
  int ret = 0; x += MAXN + 5;
  for(; x; x -= x & -x) ret += L[x][K];
  return ret;
}

ll SOL;

int k;
void solve() {
  memset(L, 0, sizeof L);
  FOR(x, -MAXN + 1, MAXN) {
    if(add[x].size()) add[x].clear();
    if(del[x].size()) del[x].clear();
  }

  int delta = 0, mn = MAX, mx = -MAX;
  FOR(x, -MAXN + 1, MAXN) {
    for(auto y: evx[x + MAXN][k]) {
      mn = min(mn, y + 1 - delta);
      mx = max(mx, y - 1 + delta);
    }
    l[x] = mn + delta;
    r[x] = mx - delta;
    delta ++;
  }
  delta = 0, mn = MAX, mx = -MAX;
  FOR(xx, -MAXN + 1, MAXN) {
    int x = -xx;
    for(auto y: evx[x + MAXN][k]) {
      mn = min(mn, y + 1 - delta);
      mx = max(mx, y - 1 + delta);
    }
    l[x] = min(l[x], mn + delta);
    r[x] = max(r[x], mx - delta);
    delta ++;
  }

  delta = 0, mn = MAX, mx = -MAX;
  FOR(y, -MAXN + 1, MAXN) {
    for(auto x: evy[y + MAXN][k]) {
      mn = min(mn, x + 1 - delta);
      mx = max(mx, x - 1 + delta);
    }
    lo[y] = mn + delta;
    hi[y] = mx - delta;
    delta ++;
  }
  delta = 0, mn = MAX, mx = -MAX;
  FOR(yy, -MAXN + 1, MAXN) {
    int y = -yy;
    for(auto x: evy[y + MAXN][k]) {
      mn = min(mn, x + 1 - delta);
      mx = max(mx, x - 1 + delta);
    }
    lo[y] = min(lo[y], mn + delta);
    hi[y] = max(hi[y], mx - delta);
    delta ++;
    if(lo[y] <= hi[y]) {
      add[lo[y]].push_back(y);
      del[hi[y] + 1].push_back(y);
    }
  }
  ll sol = 0;
  FOR(x, -MAXN + 1, MAXN) {
    for(auto y: add[x]) upd(y, +1);
    for(auto y: del[x]) upd(y, -1);

    if(l[x] > r[x]) continue;
    int type = 0;
    if(k == 0 && (x + MAXN + 1) % 2 == 0 || k == 1 && (x + MAXN + 1) % 2 == 1) type = 1;
    sol += get(r[x], type) - get(l[x] - 1, type);
  }
  SOL += sol;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;

  REP(i, n) {
    cin >> X[i] >> Y[i];
    evx[X[i] + MAXN][(X[i] + Y[i] + MAX + 1) % 2].push_back(Y[i]);
    evy[Y[i] + MAXN][(X[i] + Y[i] + MAX + 1) % 2].push_back(X[i]);
  }

  k = 1;
  solve();
  k = 0;
  solve();

  cout << SOL;
}