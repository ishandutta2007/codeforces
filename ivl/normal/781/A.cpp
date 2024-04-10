#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> E[200005];

int clr[200005];

void dfs(int id, int p){
  int curr = 0;
  for (auto t : E[id]) if (t != p){
      if (curr == clr[id]) ++curr;
      if (curr == clr[p]) ++curr;
      if (curr == clr[id]) ++curr;
      if (curr == clr[p]) ++curr;
      clr[t] = curr++;
      dfs(t, id);
    }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1){int u, v; cin >> u >> v; --u; --v; E[u].pb(v); E[v].pb(u);}

  clr[0] = 0;
  dfs(0, 0);

  int maks = 0;
  REP(i,n) maks = max(maks, clr[i]);
  cout << maks+1 << endl;
  REP(i,n) cout << clr[i]+1 << " "; cout << endl;

  return 0;
}