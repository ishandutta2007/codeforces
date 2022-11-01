#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
bool mat[405][405];
int dis[405];

int main(){
  cin >> n >> m;
  REP(i,m){
    int a, b;
    cin >> a >> b, --a, --b;
    mat[a][b] = mat[b][a] = true;
  }
  if (mat[0][n-1]) REP(i,n) REP(j,i) mat[i][j] = mat[j][i] = !mat[i][j];

  memset(dis, -1, sizeof dis);
  queue < int > Q;
  Q.push(0);
  dis[0] = 0;

  while (!Q.empty()){
    int id = Q.front(); Q.pop();
    REP(i,n) if (mat[id][i] && dis[i] == -1) dis[i] = dis[id]+1, Q.push(i);
  }

  cout << dis[n-1] << endl;
  return 0;
}