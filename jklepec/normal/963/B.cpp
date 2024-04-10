#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

vector<int> e[MAXN];
vector<point> vv;

int bio[MAXN];

void dfs2(int u, int v) {
  if(bio[v]) return;
  bio[v] = 1;
  cout << v + 1 << endl;

  for(auto w: e[v]) {
    if(w != u) {
      dfs2(v, w);
    }
  }
}

int dfs(int u, int v) {

  int ret = 1;

  for(auto w: e[v]) {
    if(w != u) {
      if(dfs(v, w)) {
        ret ^= 1;
      }
      else {
        vv.push_back({v, w});
      }
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) {
    int x; cin >> x;
    if(x != 0) {
      e[i].push_back(x - 1);
      e[x - 1].push_back(i);
    }
  }



  if(dfs(0, 0)) {
    cout << "YES\n";
    vv.push_back({0, 0});
    for(auto p: vv) {
      dfs2(p.first, p.second);
    }
  }
  else {
    cout << "NO\n";
  }
}