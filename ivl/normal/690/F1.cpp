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

const int MAXN = 10010;

int N;
vector<int> E[MAXN];



int main(void) {
  ios_base::sync_with_stdio(false);
  
  cin >> N;
  REP(i, N-1) {
    int u, v; cin >> u >> v; --u; --v;
    E[u].pb(v);
    E[v].pb(u);
  }

  ll ans = 0;
  REP(i, N) {
    for (int j : E[i]) {
      ans += E[j].size() - 1;
    }
  }

  cout << ans / 2 << endl;

  return 0; 
}