#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') <<  __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

int gr[1005];
int sz[1005];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int x, int y){
  x = un(x), y = un(y);
  if (x == y) return;
  sz[x] += sz[y];
  gr[y] = x;
}

int n, m, k;
int c[1005];

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,1005) sz[i] = 1, gr[i] = i;
  
  cin >> n >> m >> k;
  REP(i,k) cin >> c[i];
  REP(i,m){int u, v; cin >> u >> v; join(u, v);}

  vector < int > home;
  vector < int > none;
  REP(i,k) home.pb(sz[un(c[i])]), join(0, c[i]);
  FOR(i,1,n+1) if (un(i) != 0) none.pb(sz[un(i)]), join(0, i);
  sort(home.begin(), home.end());
  for (auto t : none) home.back() += t;

  ll sol = 0;
  for (auto t : home) sol += (ll)t*(t-1)/2;
  cout << sol-m << endl;
  
  return 0;
}