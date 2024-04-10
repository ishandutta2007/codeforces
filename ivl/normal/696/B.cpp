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
int par[100005];
vector < int > ch[100005];
double out[100005];
int sz[100005];

void InitDFS(int id){
  sz[id] = 1;
  for (auto t : ch[id]) InitDFS(t), sz[id] += sz[t];
}

void CalcDFS(int id, double e){
  out[id] = ++e;
  for (auto t : ch[id]) CalcDFS(t, e + (sz[id] - 1 - sz[t]) / 2.);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1) cin >> par[i+1], --par[i+1];
  REP(i,n-1) ch[par[i+1]].pb(i+1);
  InitDFS(0);
  CalcDFS(0, 0);
  REP(i,n) cout << setprecision(20) << out[i] << " "; cout << endl;

  return 0;
}