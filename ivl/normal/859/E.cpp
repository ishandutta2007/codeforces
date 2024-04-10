#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define next nextblatruc

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int Mod = 1000000007;
int add(int a, int b){a += b; return a < Mod ? a : a-Mod;}
int mul(int a, int b){return (int)((ll)a*b%Mod);}

int n;
pii e[100005];

int next[200005];
vector<int> inv[200005];
set<int> nodes;
int in[200005];
int out[200005];

int dfs(int id){
  if (!nodes.count(id)) return 0;
  nodes.erase(id);
  int sol = 1 + dfs(next[id]);
  for (auto t : inv[id]) sol += dfs(t);
  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> e[i].x >> e[i].y;

  int sol = 1;

  REP(i,n){
    nodes.insert(e[i].x);
    nodes.insert(e[i].y);
    next[e[i].x] = e[i].y;
    inv[e[i].y].pb(e[i].x);
    ++in[e[i].y];
    ++out[e[i].x];
  }

  {
    vector<int> starts;
    for (auto t : nodes) if (out[t] == 0) starts.pb(t);
    for (auto t : starts) sol = mul(sol, dfs(t));
  }

  {
    while (!nodes.empty()){
      int id = *nodes.begin();
      dfs(id);
      set<int> S;
      while (!S.count(id)) S.insert(id), id = next[id];
      if (id != next[id]) sol = mul(sol, 2);
    }
  }

  cout << sol << endl;
  
  return 0;
}