#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m, q;
string mat[205];
pii del[20];

vector < vector < pii > > Cycle;
map < pii, int > which;
vector < int > E[205*205];

pii next(pii t){
  pii nt = {t.x + del[(int)mat[t.x][t.y]].x, t.y + del[(int)mat[t.x][t.y]].y};
  if (nt.x < 0 || nt.y < 0 || nt.x >= n || nt.y >= m) return t;
  return nt;
}

map < pii, int > bio;
map < int, char > znak;
const pii Bad = {-1, -1};
pii CycleDFS(pii t){
  if (bio[t] == 2) return Bad;
  if (bio[t] == 1){
    Cycle.pb({});
    return t;
  }

  bio[t] = 1;
  pii nt = CycleDFS(next(t));
  bio[t] = 2;
  if (nt == Bad) return Bad;
  Cycle.back().pb(t);
  if (nt == t) return Bad;
  return nt;
}

int MakeDFS(pii t){
  if (bio[t]) return bio[t];
  bio[t] = (int)bio.size();
  znak[bio[t]] = (char)(mat[t.x][t.y] + '0');
  E[MakeDFS(next(t))].pb(bio[t]);
  return bio[t];
}

bitset < 15 > Has[205*205];
string in;

bool CheckDFS(int id, int hi, bool flag = false){

  if (flag) while (hi >= 0 && Has[id][in[hi]-'0']) --hi;
  else if (in[hi] == znak[id]) --hi;
  if (hi < 0) return true;

  bool r = false;
  for (auto x : E[id]) r |= CheckDFS(x, hi);
  return r;
  
}

int main(){ //bio[Bad] = (int)bio.size(); cout << bio[Bad] << endl; return 0;
  cin >> n >> m >> q;
  REP(i,n) cin >> mat[i];
  REP(i,10) cin >> del[i].x >> del[i].y;
  REP(i,n) REP(j,m) mat[i][j] = (char)(mat[i][j]-'0');

  REP(i,n) REP(j,m){
    if (bio[{i,j}]) continue;
    CycleDFS({i, j});
  } bio.clear();
  REP(i,Cycle.size()) for (auto x : Cycle[i]){
    which[x] = i+1;
    bio[x] = i+1;
    Has[i+1][(int)mat[x.x][x.y]] = 1;
  }

  REP(i,n) REP(j,m) MakeDFS({i,j});
  
  REP(tt,q){
    cin >> in;
    bool can = false;
    REP(i,Cycle.size()) if (CheckDFS(i+1, (int)in.size()-1, true)) can = true;
    if (can) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}