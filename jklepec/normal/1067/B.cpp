#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int mod = 998244353;

const int MAXN = 1e5 + 5;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}

int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

void fail() {
  cout << "No";
  exit(0);
}

vector<int> e[MAXN];

int dis[MAXN];
int ok[MAXN];

int k;

int dfs(int u, int v, int dub) {
  dis[v] = dub;

  int mx = dub;
  for(auto w: e[v]) {
    if(u != w) mx = max(mx, dfs(v, w, dub + 1));
  }

  if(mx == 2 * k) {
    ok[v] = 1;
  }

  return mx;
}

void check(int u, int v, int dub) {
  if(e[v].size() == 1) {
    if(dub != k) fail();
    return;
  }
  if(u != v) {
    if(e[v].size() < 4) fail();
  }

  for(auto w: e[v]) {
    if(u != w) check(v, w, dub + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n >> k;

  REP(i, n - 1) {
    int x, y; cin >> x >> y;
    x --; y --;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  dfs(0, 0, 0);

  int mx = 0, j = 0;
  REP(i, n) {
    if(dis[i] > mx) {
      j = i;
      mx = dis[i];
    }
  }

  memset(ok, 0, sizeof ok);
  dfs(j, j, 0);

  mx = 0, j = 0;
  REP(i, n) {
    if(dis[i] > mx) mx = dis[i];
  }

  if(mx != 2 * k) fail();

  j = -1;
  REP(i, n) {
    if(dis[i] == mx / 2 && ok[i]) {
      if(j != -1) {
        fail();
      }
      j = i;
    }
  }

  if(e[j].size() < 3) fail();
  check(j, j, 0);

  cout << "Yes";
}