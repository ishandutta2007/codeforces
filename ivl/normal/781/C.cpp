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
typedef pair<int, int> pii;

int gr[200005];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);};
void join(int x, int y){
  if (rand()%2) swap(x, y);
  gr[un(x)] = un(y);
}

int n, m, k;
vector<int> E[200005];

vector<int> order;
void dfs(int id, int p){
  for (auto t : E[id]) if (t != p){
      order.pb(id);
      dfs(t, id);
    } order.pb(id);
}

int main(){
  ios_base::sync_with_stdio(false);

  iota(gr, end(gr), 0);

  cin >> n >> m >> k;
  REP(i,m){
    int u, v;
    cin >> u >> v;
    if (un(u) == un(v)) continue;
    E[u].pb(v);
    E[v].pb(u);
    join(u, v);
  }

  dfs(1, 1);
  int limit = (2*n+k-1) / k;
  REP(i,k){
    vector<int> tmp;
    while (!order.empty() && (int)tmp.size() < limit) tmp.pb(order.back()), order.pop_back();
    if (tmp.empty()) tmp = {1};
    cout << tmp.size() << " ";
    for (auto t : tmp) cout << t << " "; cout << endl;
  }
  
  return 0;
}