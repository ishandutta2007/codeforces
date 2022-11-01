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
vector<int> E[100005];
int c[100005];

void imp(){cout << "NO" << endl; exit(0);}

bool dfs(int id, int p){
  for (int x : E[id]) if (x != p){
      if (c[id] != c[x]) return false;
      if (!dfs(x, id)) return false;
    } return true;
}

void check(int id){
  for (int x : E[id]) if (!dfs(x, id)) return;
  cout << "YES" << endl << id+1 << endl;
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1){int u, v; cin >> u >> v; --u, --v; E[u].pb(v); E[v].pb(u);}
  REP(i,n) cin >> c[i];

  check(0);
  REP(i,n) for (int j : E[i]) if (c[i] != c[j]){check(i); check(j); imp();}
  
  return 0;
}