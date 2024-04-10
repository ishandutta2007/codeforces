#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2005, inf = 1e9 + 5;

int n;
int d[MAXN];
int e[MAXN][MAXN];

void quit() {
  cout << "NO";
  exit(0);
}

void check() {
  REP(i, n) {
    if(e[i][i]) {
      quit();
    }
    REP(j, n) {
      if(e[i][j] != e[j][i]) {
        quit();
      }
      if(i != j && e[i][j] == 0) {
        quit();
      }
    }
  }
}

int par[MAXN], root;

vector<int> ed[MAXN];

void dfs(int u, int v) {
  if(e[v][root] != d[v]) {
    quit();
  }
  for(auto w: ed[v]) {
    if(u != w) {
      d[w] = d[v] + e[v][w];
      dfs(v, w);
    }
  }
}

void solve() {
  FOR(i, 1, n) {
    d[i] = e[0][i];
  }

  REP(i, n - 1) {
    int mn = inf, ind = 0;
    REP(j, n) {
      if(d[j] && d[j] < mn) {
        mn = d[j];
        ind = j;
      }
    }
    if(mn <= 0 || mn == inf) {
      quit();
    }
    REP(j, n) {
      if(d[j] - d[ind] == e[ind][j] && ind != j) {
        par[j] = ind;
        d[j] -= d[ind];
      }
    }
    d[ind] = 0;
  }

  FOR(i, 1, n) {
    ed[i].push_back(par[i]);
    ed[par[i]].push_back(i);
  }

  REP(i, n) {
    d[i] = 0;
    root = i;
    dfs(i, i);
  }

  cout << "YES";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) REP(j, n) {
    cin >> e[i][j];
  }

  solve();
}