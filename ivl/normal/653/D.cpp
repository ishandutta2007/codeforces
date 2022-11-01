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

int n, m, x;
int mat[55][55];
int cnt[55][55];

double d[55][55];
double dis[55];
bool done[55];
int par[55];
double DD[1<<20];

void run(){
  REP(i,n) REP(j,n){
    if (cnt[i][j] > 0) d[i][j] = 1e9;
    else d[i][j] = (double)mat[i][j] * DD[-cnt[i][j]+1];
  } memset(done, 0, sizeof done);
  REP(i,n) dis[i] = -1;
  dis[0] = 1e9; //TRACE(111);
  REP(ttt,n){
    int id;
    REP(i,n) if (!done[i]) id = i;
    REP(i,n) if (!done[i] && dis[i] > dis[id]) id = i; //TRACE(id);
    done[id] = true;
    REP(i,n) if (!done[i]){
      double cd = dis[id];
      if (cd > d[id][i]) cd = d[id][i];
      if (cd < dis[i]) continue;
      dis[i] = cd;
      par[i] = id; //TRACE(i _ id);
    }
  }
  int id = n-1;
  while (id != 0){
    ++cnt[id][par[id]];
    --cnt[par[id]][id];
    id = par[id];
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  FOR(i,1,1<<20) DD[i] = 1./i;

  cin >> n >> m >> x;
  REP(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    mat[a][b] += c;
  }

  REP(ttt,x) run();

  double r = 1e9;
  REP(i,n) REP(j,n) if (cnt[i][j] < 0) r = min(r, (double)mat[i][j] / -cnt[i][j]);
  cout << setprecision(30) << x*r << endl;

  return 0;
}