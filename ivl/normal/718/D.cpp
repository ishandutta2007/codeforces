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
vector < int > E[100005];

map < vector < int >, int > _H;
int Hash(vector < int >  V){
  sort(V.begin(), V.end());
  if (_H.count(V) == 0) _H[V] = (int)_H.size();
  return _H[V];
}

vector < int > ch[100005];
int par[100005];
int DH[100005];
int deg[100005];
int UH[100005];

void DownDFS(int id, int p){
  par[id] = p;
  for (auto t : E[id]) if (t != p) ch[id].pb(t), DownDFS(t, id);
  vector < int > v;
  for (auto t : ch[id]) v.pb(DH[t]);
  DH[id] = Hash(v);
  deg[id] = (int)E[id].size();
}

void UpDFS(int id){
  for (auto t : ch[id]){
    vector < int > v;
    if (id != 1) v.pb(UH[id]);
    for (auto u : ch[id]) if (u != t) v.pb(DH[u]);
    UH[t] = Hash(v);
    UpDFS(t);
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1){
    int x, y;
    cin >> x >> y;
    E[x].pb(y);
    E[y].pb(x);
  }

  DownDFS(1, 1);
  UpDFS(1);

  set < int > All;
  FOR(i,1,n+1){
    if (deg[i] == 4) continue;
    vector < int > v;
    if (i != 1) v.pb(UH[i]);
    for (auto t : ch[i]) v.pb(DH[t]);
    v.pb(Hash({}));
    All.insert(Hash(v));
  } cout << All.size() << endl;
  
  return 0;
}