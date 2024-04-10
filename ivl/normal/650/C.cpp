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

int gr[1<<20];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int a, int b){
  gr[un(a)] = un(b);
}

int n, m;
vector < int > mat[1<<20];

int f(int i, int j){return i*m+j;}

vector < int > E[1<<20];
vector < int > E2[1<<20];
int deg[1<<20];
int clr[1<<20];

int main(){
  //ios_base::sync_with_stdio(false);

  REP(i,1<<20) gr[i] = i;

  cin >> n >> m;
  REP(i,n) REP(j,m){
    int t;
    scanf("%d", &t);
    mat[i].pb(t);
  }

  REP(i,n){
    vector < pii > v;
    REP(j,m) v.pb({mat[i][j], f(i,j)});
    sort(v.begin(), v.end());
    REP(t,v.size()-1) if (v[t].x == v[t+1].x) join(v[t].y, v[t+1].y);
  }

  REP(j,m){
    vector < pii > v;
    REP(i,n) v.pb({mat[i][j], f(i,j)});
    sort(v.begin(), v.end());
    REP(t,v.size()-1) if (v[t].x == v[t+1].x) join(v[t].y, v[t+1].y);
  }

  REP(i,n){
    vector < pii > v;
    REP(j,m) v.pb({mat[i][j], f(i,j)});
    sort(v.begin(), v.end());
    REP(t,v.size()-1) if (v[t].x != v[t+1].x) E[un(v[t].y)].pb(un(v[t+1].y));
  }

  REP(j,m){
    vector < pii > v;
    REP(i,n) v.pb({mat[i][j], f(i,j)});
    sort(v.begin(), v.end());
    REP(t,v.size()-1) if (v[t].x != v[t+1].x) E[un(v[t].y)].pb(un(v[t+1].y));
  }

  /*
    REP(i,1<<20) for (auto j : E[i]) TRACE(i _ j);
    REP(i,4) TRACE(i _ un(i));
    REP(i,n) REP(j,m) TRACE(mat[i][j]);
  */

  REP(i,1<<20) for (auto x : E[i]) E2[x].pb(i);
  REP(i,1<<20) deg[i] = (int)E2[i].size();
  queue < int > Q;
  REP(i,1<<20) if (deg[i] == 0) Q.push(i);

  while (!Q.empty()){
    int id = Q.front();
    Q.pop();
    for (auto t : E[id]){
      clr[t] = max(clr[t], clr[id]+1);
      if (--deg[t] == 0) Q.push(t);
    }
  }

  REP(i,n){
    REP(j,m) printf("%d ", 1+clr[un(f(i,j))]);
    cout << endl;
  }

  return 0;
}