#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
vector < int > E[1<<20];

double DFS(int id, int p, int dep){
  double R = 1./dep;
  for (auto t : E[id]) if (t != p) R += DFS(t, id, dep+1);
  return R;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1){
    int a, b;
    cin >> a >> b;
    E[a].pb(b), E[b].pb(a);
  } cout << setprecision(25) << DFS(1, 1, 1) << endl;

  return 0;
}