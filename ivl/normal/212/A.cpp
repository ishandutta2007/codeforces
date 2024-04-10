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

namespace flow{

  const int SOURCE = 0;
  const int SINK = 1;
  map < int, int > M[405];
  map < int, int > M2[405];
  
  vector < int > st;
  bool bio[405][3];
  bool dfs(int id, int lim){
    if (bio[id][lim]++) return false;
    st.pb(id);
    if (id == SINK) return true;
    for (auto t : M[id]) if (t.y && dfs(t.x, lim)) return true;
    if (lim) for (auto t : M2[id]) if (t.y && dfs(t.x, lim-1)) return true;
    st.pop_back();
    return false;
  }

  bool dfsControl(int id){
    REP(i,3){
      memset(bio, 0, sizeof bio);
      st.clear();
      if (dfs(id, i)) return true;
    } return false;
  }

  int run(){
    int r = 0;
    while (dfsControl(SOURCE)){ ++r;
      REP(i,st.size()-1){
	if (M[st[i]][st[i+1]]) --M[st[i]][st[i+1]], ++M[st[i+1]][st[i]];
	else --M2[st[i]][st[i+1]], ++M2[st[i+1]][st[i]];
      }
    } return r;
  }

  void reset(){
    REP(i,405) M[i].clear();
    REP(i,405) M2[i].clear();
  }

  void edge(int x, int y, int c){
    M[x][y] += c;
  }

  void edge2(int x, int y, int c){
    M2[x][y] += c;
  }
  
}

using namespace flow;

int n, m, k, t;
pii E[5005];

int cnt[5005];
int output[5005];

int main(){

  cin >> n >> m >> k >> t;
  REP(i,k) cin >> E[i].x >> E[i].y, --E[i].x, --E[i].y;
  REP(i,k) ++cnt[E[i].x], ++cnt[n+E[i].y];

  int R = 0;
  int check = 0;
  int tt = t;

  REP(i,n+m) R += !!(cnt[i]%t);
  
  REP(blatruc,t){
    reset();
    REP(i,k) if (!output[i]) edge(2+E[i].x, 2+n+E[i].y, 1);
    REP(i,n) edge(SOURCE, 2+i, cnt[i]/tt);
    REP(i,m) edge(2+n+i, SINK, cnt[n+i]/tt);
    REP(i,n) edge2(SOURCE, 2+i, (cnt[i]+tt-1)/tt - cnt[i]/tt);
    REP(i,m) edge2(2+n+i, SINK, (cnt[n+i]+tt-1)/tt - cnt[n+i]/tt);
    check += run();
    REP(i,k) if (!output[i]){
      if (M[2+n+E[i].y][2+E[i].x]){
	output[i] = blatruc+1;
	++M[2+n+E[i].y][2+E[i].x];
	--cnt[E[i].x], --cnt[n+E[i].y];
	continue;
      }
      if (M2[2+n+E[i].y][2+E[i].x]){
	output[i] = blatruc+1;
	++M2[2+n+E[i].y][2+E[i].x];
	--cnt[E[i].x], --cnt[n+E[i].y];
	continue;
      }
    } --tt;
  } assert(check == k);

  cout << R << endl;
  REP(i,k) cout << output[i] << " "; cout << endl;
  
  return 0;
}