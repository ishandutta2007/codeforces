#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

vector<point> v;

int n, m, q;

vector<int> r[MAXN], c[MAXN];
bool bio[MAXN];
bool upd[MAXN];

void dfs(int x) {
  if(bio[x]) return;
  bio[x] = true;

  for(auto i: r[x]) {
    int y = v[i].second;
    if(y == 1 || upd[y]) continue;

    upd[y] = true;

    for(auto j: c[y]) {
      dfs(v[j].first);
    }
  }
}

int solve() {
  memset(bio, 0, sizeof bio);
  memset(upd, 0, sizeof upd);

  REP(i, max(n, m) + 1) {
    c[i].clear();
    r[i].clear();
  }

  REP(i, q) {
    int x = v[i].first;
    int y = v[i].second;
    r[x].pb(i);
    c[y].pb(i);
  }

  int ret = 0;

  FOR(i, 2, m + 1) {
    if(sz(c[i]) == 0) {
      ret ++;
    }
  }

  int pt = 1;

  for(auto i: c[1]) {
    dfs(v[i].first);
  }

  while(bio[pt]) pt ++;

  while(pt <= n) {
    ret ++;
    dfs(pt);

    while(bio[pt]) pt ++;
  }

  return ret;
}

int main() {
  cin >> n >> m >> q;

  if(n == 1 || m == 1) {
    cout << n * m - q << endl;
    return 0;
  }

  REP(i, q) {
    int x, y; cin >> x >> y;
    v.pb({x, y});
  }

  int ans = MAXN + MAXN;

  REP(k, 2) {
    ans = min(ans, solve());
    if(k == 0) {
      REP(i, q) {
        swap(v[i].first, v[i].second);
      }
      swap(n, m);
    }
  }

  cout << ans << endl;
}