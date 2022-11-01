#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define pb push_back
#define x first
#define y second

typedef long long ll;

const int MAXN = 1010;

int N, M;
vector<int> E[MAXN];

bool bio[MAXN];

void dfs(int x) {
  if (bio[x]) return;
  bio[x] = 1;
  for (int y : E[x]) dfs(y);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M;
  REP(i, M) {
    int u, v; cin >> u >> v; --u; --v;
    E[u].pb(v);
    E[v].pb(u);
  }

  dfs(0);
  
  bool all_connected = true;
  REP(i, N) all_connected &= bio[i];

  if (all_connected && N == M + 1) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0; 
}