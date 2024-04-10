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
typedef pair < int, ll > pii;

const int Mod = 1000000007;
int add(int x, int y){x += y; if (x >= Mod) return x-Mod; return x;}
int mul(int x, int y){return (int)((ll)x*y%Mod);}
int pot(int x, int y){
  int r = 1;
  while (y){
    if (y&1) r = mul(r, x);
    x = mul(x, x), y >>= 1;
  } return r;
}
int f(ll n){return (int)(n*(n-1)/2%Mod);}

int n, m;
vector < pii > E[100005];

int gr[100005];
int root;
int bio[100005];
vector < ll > all[100005];
vector < ll > comp[100005];
ll xd[100005];
int dep[100005];

void dfs(int id, int p){
  comp[root].pb(xd[id]);
  gr[id] = root;
  bio[id] = 1;
  for (auto e : E[id]){
    if (e.x == p) continue;
    if (bio[e.x] == 0){
      dep[e.x] = 1+dep[id];
      xd[e.x] = xd[id]^e.y;
      dfs(e.x, id);
    } else if (bio[e.x] == 1){
      all[root].pb(xd[id]^xd[e.x]^e.y);
    } else if (bio[e.x] == 2){
      
    }
  }
  bio[id] = 2;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,m){int u, v; ll t; cin >> u >> v >> t; --u, --v; E[u].pb({v, t}); E[v].pb({u, t});}

  int sol = 0;
  
  REP(i,n) if (!bio[i]){
    root = i;
    dfs(i, i);
    vector < ll > &cv = all[i];
    vector < ll > gen;
    for (int d = 60; d >= 0; --d){
      ll tmp = -1;
      REP(ii,cv.size()) if ((cv[ii]>>d)&1) tmp = cv[ii];
      if (tmp == -1) continue;
      gen.pb(tmp);
      for (auto &t : cv) if (t > (t^tmp)) t ^= tmp;
    }

    REP(d,60){
      bool sym = false;
      for (auto t : gen) if ((t>>d)&1) sym = true;
      int cnt[2] = {0, 0};
      for (auto t : comp[root]) ++cnt[(t>>d)&1];
      if (sym){
	sol = add(sol, mul(pot(2, d), mul(pot(2, (int)gen.size()-1), f(cnt[0]+cnt[1]))));
      } else {
	sol = add(sol, mul(pot(2, d), mul(pot(2, (int)gen.size()), mul(cnt[0], cnt[1]))));
      }
    }
  } cout << sol << endl;

  return 0;
}