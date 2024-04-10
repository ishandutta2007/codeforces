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
typedef pair < int, int > pii;

int n;
int par[200005];
vector < int > E[200005];
int dep[200005];

int LCA[20][200005];

int lca(int a, int b){
  if (dep[a] < dep[b]) swap(a, b);
  int t = dep[a] - dep[b];
  REP(i,20) if ((t>>i)&1) a = LCA[i][a];
  for (int i = 19; i >= 0; --i)
    if (LCA[i][a] != LCA[i][b])
      a = LCA[i][a], b = LCA[i][b];
  if (a == b) return a;
  else return par[a];
}

int d(int a, int b){
  return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int lift(int a, int x){
  REP(i,20) if ((x>>i)&1) a = LCA[i][a];
  return a;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  par[1] = 1;
  FOR(i,2,n+1){int &x = par[i]; cin >> x; E[x].pb(i); dep[i] = 1+dep[x];}

  REP(i,n+1) LCA[0][i] = par[i];
  FOR(i,1,20) REP(j,n+1) LCA[i][j] = LCA[i-1][LCA[i-1][j]];

  int a = 1, b = 1, r = 0, d = 0;
  FOR(t,2,n+1){
    int da = ::d(a, t), db = ::d(b, t);
    if (da > db) swap(a, b), swap(da, db);
    if (da <= r){cout << d << " "; continue;}
    cout << ++d << " ";
    if (a != b){
      b = a;
      ++r;
    } else {
      int l = lca(a, t);
      if (l != a) b = par[a];
      else b = lift(t, dep[t] - dep[a] - 1);
    }
  } cout << endl;
  
  return 0;
}