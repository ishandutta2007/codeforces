#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pll pair < ll, ll >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){cout << -1 << endl; exit(0);}

int blabla(int x){
  int r = 0;
  while (x) x /= 10, ++r;
  return r;
}

int n;
int mat[10][10];

vector < int > V[10];
vector < pii > sol;

bool valid(){
  REP(i,10) if (V[i].empty()) REP(j,10) if (mat[i][j]) return false;
  vector < int > v;
  REP(i,10) if (!V[i].empty()) v.pb(i);
  FOR(bit,1,1<<v.size()){
    int Node = 0, Edge = 0;
    vector < int > v2;
    REP(i,10) if ((bit>>i)&1) v2.pb(v[i]);
    for (auto x : v2) Node += (int)V[x].size();
    REP(i,v2.size()) REP(j,i) Edge += mat[v2[i]][v2[j]];
    if (Edge >= Node) return false;
  } return true;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  REP(i,n-1){
    string s1, s2;
    cin >> s1 >> s2;
    ++mat[s1.size()][s2.size()];
    ++mat[s2.size()][s1.size()];
  }
  
  FOR(i,1,n+1) V[blabla(i)].pb(i);

  

  /*n = 4;
    mat[0][1] = mat[1][0] = 1;
    mat[2][1] = mat[1][2] = 1;
    mat[0][2] = mat[2][0] = 1;
    V[0] = {1, 2};
    V[1] = {10};
    V[2] = {100};*/
  
  int cnt = n-1;
  REP(i,10) if (mat[i][i]){ mat[i][i] /= 2;
    if (mat[i][i] >= (int)V[i].size()) imp();
    REP(j,mat[i][i]) sol.pb({V[i].front(), V[i].back()}), V[i].pop_back(), --cnt;
    mat[i][i] = 0;
  }

  if (!valid()) imp();
  //for (auto x : sol) TRACE(x.x _ x.y);

  REP(ttt,cnt){
    //TRACE(mat[1][2] _ V[1].size() _ V[2].size());
    vector < int > v;
    REP(i,10) if (!V[i].empty()) v.pb(i);
    vector < int > bla(10, (1<<v.size())-1);
    FOR(bit,1,1<<v.size()){
      if (__builtin_popcount(bit) <= 1) continue;
      int Node = 0, Edge = 0;
      vector < int > v2;
      REP(i,10) if ((bit>>i)&1) v2.pb(v[i]);
      for (auto x : v2) Node += (int)V[x].size();
      REP(i,v2.size()) REP(j,i) Edge += mat[v2[i]][v2[j]];
      if (Node-Edge == 1){
	//TRACE(bit);
	for (auto x : v2)
	  bla[x] &= bit;
      }
    }
    //TRACE(v.size());
    for (auto x : v){
      //TRACE(x _ bla[x]);
      if (!bla[x]) continue;
      if (V[x].size() == 1){
	int blab = 0;
	for (auto y : v) blab += mat[x][y];
	if (blab != 1) continue;
      }
      //TRACE(x _ bla[x]);
      bool ch = false;
      REP(i,v.size()) if (mat[x][v[i]] && ((bla[x]>>i)&1)){
	int y = v[i];
	sol.pb({V[x].back(), V[y].back()});
	--mat[x][y];
	--mat[y][x];
	V[x].pop_back();
	ch = true;
	break;
      }
      if (ch) break;
    }
  }

  for (auto x : sol) cout << x.x << " " << x.y << endl;
  
  return 0;
}