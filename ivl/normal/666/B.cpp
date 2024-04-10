#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
vector < int > E[3005];

int dis[3005][3005];
void BFS(int st){
  REP(i,n) dis[st][i] = -1;
  dis[st][st] = 0;
  queue < int > Q;
  Q.push(st);
  while (!Q.empty()){
    int id = Q.front(); Q.pop();
    for (auto t : E[id]) if (dis[st][t] == -1) dis[st][t] = 1+dis[st][id], Q.push(t);
  }
}

int maks[3005][2][6];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,m){
    int a, b;
    cin >> a >> b, --a, --b;
    E[a].pb(b);
  }

  REP(i,n) BFS(i);

  REP(i,n){
    REP(a,2) REP(b,5) maks[i][a][b] = -1;
    REP(j,n) for (int k = 5-1; k >= 0; --k)
      if (maks[i][0][k] == -1 || dis[i][maks[i][0][k]] < dis[i][j]) maks[i][0][k+1] = maks[i][0][k], maks[i][0][k] = j;
    REP(j,n) for (int k = 5-1; k >= 0; --k)
      if (maks[i][1][k] == -1 || dis[maks[i][1][k]][i] < dis[j][i]) maks[i][1][k+1] = maks[i][1][k], maks[i][1][k] = j;
  }

  int Best = -1;
  vector < int > sol;
  REP(i,n) REP(j,n) REP(ii,5) REP(jj,5){
    int a = maks[i][1][ii];
    int b = maks[j][0][jj];
    if (a == -1 || b == -1) continue;
    if (a == i || a == j || a == b) continue;
    if (b == i || b == j) continue;
    if (i == j) continue;
    if (dis[i][j] == -1) continue;
    int CB = dis[a][i] + dis[i][j] + dis[j][b];
    if (CB > Best) Best = CB, sol = {a, i, j, b};
  }

  //cout << Best << endl;
  REP(i,4) cout << sol[i]+1 << " "; cout << endl;
  
  return 0;
}