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
typedef pair<ll, ll> pll;

int n, m, k;
int d[100005];
int f[100005];
int t[100005];
int c[100005];

ll to[1000005], from[1000005];

ll cost[100005];

int main(){

  cin >> n >> m >> k;
  REP(i,m) cin >> d[i] >> f[i] >> t[i] >> c[i];

  {
    FOR(i,1,n+1) cost[i] = 1e12, to[0] += cost[i];
    set<pii> Sp;
    REP(i,m) Sp.insert({d[i], i});
    for (auto p : Sp){
      int i = p.y;
      if (f[i] == 0) continue;
      if (c[i] > cost[f[i]]) continue;
      to[d[i]] -= cost[f[i]] - c[i];
      cost[f[i]] = c[i];
    }
    REP(i,1000001) to[i+1] += to[i];
  }
  
  {
    FOR(i,1,n+1) cost[i] = 1e12, from[1000001] += cost[i];
    set<pii> Sp;
    REP(i,m) Sp.insert({-d[i], i});
    for (auto p : Sp){
      int i = p.y;
      if (t[i] == 0) continue;
      if (c[i] > cost[t[i]]) continue;
      from[d[i]] -= cost[t[i]] - c[i];
      cost[t[i]] = c[i];
    }
    for (int i = 1000000; i >= 0; --i)
      from[i] += from[i+1];
  }

  ll sol = 1e12;
  REP(i,1000001){
    int j = i+k+1;
    if (j > 1000001) break;
    sol = min(sol, to[i] + from[j]);
  }

  if (sol == 1e12) cout << -1 << endl;
  else cout << sol << endl;
  
  return 0;
}