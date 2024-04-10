#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int oo = 1e9;

void imp(){cout << -1 << endl; exit(0);}

int d[55][55];
vector<int> N[55];
int calc(int n, vector<pii> E){
  REP(i,n) REP(j,n) d[i][j] = oo;
  REP(i,n) N[i].clear();
  for (auto t : E) N[t.x].pb(t.y), N[t.y].pb(t.x);
  REP(i,n){
    d[i][i] = 0;
    queue<int> Q;
    Q.push(i);
    while (!Q.empty()){
      int id = Q.front(); Q.pop();
      for (int x : N[id]) if (d[i][x] == oo) d[i][x] = 1+d[i][id], Q.push(x);
    }
  }
  int sol = 0;
  REP(i,n) REP(j,i) if (d[i][j] == oo) return -1; else sol = max(sol, d[i][j]);
  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  if (k >= n) imp();
  if (k == 1) imp();
  if (n <= 3) imp();

  if (k == 2 && n != 4 || n == 4 && k == 3){
    cout << n-1 << endl;
    REP(i,n-1) cout << i+1 << " " << i+2 << endl;
    return 0;
  }

  if (n == 4) imp();

  if (k == 3){
    cout << n-1 << endl;
    FOR(i,2,n) cout << 1 << " " << i << endl;
    cout << 2 << " " << n << endl;
    return 0;
  }

  // set<int> S;
  // vector<pii> E;
  // REP(i,n) REP(j,i) E.pb({i, j});
  // REP(i,1<<(E.size()-1)){
  //   vector<pii> A, B;
  //   REP(j,E.size()) if ((i>>j)&1) A.pb(E[j]); else B.pb(E[j]);
  //   int d = min(calc(n, A), calc(n, B));
  //   if (S.count(d)) continue;
  //   TRACE(d); S.insert(d);
  //   for (pii t : A) TRACE(t.x _ t.y);
  // }

  imp();
  return 0;
}