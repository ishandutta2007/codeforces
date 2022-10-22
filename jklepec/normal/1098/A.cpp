#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5;

ll sol;

ll a[MAXN], s[MAXN];

void fail() {
  cout << -1 << endl;
  exit(0);
}

vector<int> e[MAXN];

int dfs(int u, int v, int dub = 0) {

  int mn = 1e9 + 5, cnt = 0;
  for(auto w: e[v]) {
    mn = min(mn, dfs(v, w, dub + 1));
    cnt ++;
  }

  if(dub & 1) {
    if(!cnt) s[v] = s[u];
    else {
      s[v] = mn;
    }
  }

  return s[v];
}

void dfs2(int u, int v, int dub) {
  for(auto w: e[v]) {
    dfs2(v, w, dub + 1);
  }
  a[v] = s[v] - s[u];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;

  REP(i, n - 1) {
    int p; cin >> p;
    p --;
    e[p].pb(i + 1);
  }

  REP(i, n) {
    cin >> s[i];
  }

  dfs(0, 0, 0);
  dfs2(0, 0, 0);
  a[0] = s[0];

  REP(i, n) {
    sol += a[i];
    if(a[i] < 0) {
      fail();
    }
  }
  cout << sol << endl;
}