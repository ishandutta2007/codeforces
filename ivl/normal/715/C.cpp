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

int n, m, phi;
vector < pii > E[100005];

int mul(int a, int b){return (int)(((ll)a*b)%m);}
int add(int a, int b){a += b; if (a >= m) return a-m; return a;}
int pot(int a, int x){
  int r = 1;
  while (x){
    if (x&1) r = mul(r, a);
    a = mul(a, a), x >>= 1;
  } return r;
}
int inv(int a){return pot(a, phi-1);}

ll sol = 0;

bool forbidden[100005];
int sz[100005];
int maks[100005];
vector < int > all;
int dfs(int id, int p){
  all.pb(id);
  sz[id] = 1;
  maks[id] = -1;
  for (auto t : E[id])
    if (t.x != p && !forbidden[t.x]){
      sz[id] += dfs(t.x, id);
      maks[id] = max(maks[id], sz[t.x]);
    }
  return sz[id];
}

void grupa(int id, int p, int a, int b, vector < pii > &out){
  out.pb({a, b});
  for (auto t : E[id])
    if (t.x != p && !forbidden[t.x])
      grupa(t.x, id, mul(10, a), add(b, mul(a, t.y)), out);
}

void grupa2(int id, int p, int a, int b, vector < pii > &out){
  out.pb({a, b});
  for (auto t : E[id])
    if (t.x != p && !forbidden[t.x])
      grupa2(t.x, id, mul(10, a), add(t.y, mul(10, b)), out);
}

void solve(int root){
  vector < vector < pii > > Vall = {{{1, 0}}};
  vector < vector < pii > > Vall2 = {{{1, 0}}};
  for (auto t : E[root]) if (!forbidden[t.x]){
      Vall.pb(vector < pii >());
      grupa(t.x, root, 10%m, t.y, Vall.back());
      Vall2.pb(vector < pii >());
      grupa2(t.x, root, 10%m, t.y, Vall2.back());
    }

  bool d = false;//root==0;
  if (d) TRACE(sol);

  if (d) for (auto V : Vall){
      for (auto Vt : V) TRACE(Vt.x _ Vt.y);
      cout << endl;
    }

  map < int, int > M;
  for (auto V : Vall2) for (auto t : V) ++M[mul(m-t.y, inv(t.x))];
  if (d) for (auto Mt : M) TRACE(Mt.x _ Mt.y);
  for (auto V : Vall) for (auto t : V) sol += M[t.y];
  if (d) TRACE(sol);
  int tmp = 0;
  for (auto V : Vall){
    M.clear();
    for (auto t : Vall2[tmp]) ++M[mul(m-t.y, inv(t.x))];
    for (auto t : V) sol -= M[t.y];
    ++tmp;
  }

  if (d) TRACE(sol);
  
}

void centroid(int node, int debug = 0){
  all.clear();
  dfs(node, node);
  if (sz[node] == 1) return;
  for (auto t : all) maks[t] = max(maks[t], sz[node]-sz[t]);
  int best = node;
  for (auto t : all) if (maks[t] < maks[best]) best = t;

  //REP(i,debug) cout << " "; cout << best << endl;

  solve(best);
  forbidden[best] = true;
  for (auto t : E[best]) if (!forbidden[t.x]) centroid(t.x, debug+1);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n-1){int u, v, w; cin >> u >> v >> w; w %= m; E[u].pb({v, w}); E[v].pb({u, w});}

  {
    int tmp = m;
    phi = 1;
    for (int i = 2; i*i <= tmp; ++i) if (tmp%i == 0){
	phi *= i-1;
	tmp /= i;
	while (tmp%i == 0) tmp /= i, phi *= i;
      }
    if (tmp != 1) phi *= tmp-1;
  } //TRACE(phi);

  centroid(0);
  cout << sol << endl;

  return 0;
}