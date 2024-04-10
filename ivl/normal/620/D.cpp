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

#define int ll

const int oo = 1000000000;
const ll ool = (ll)oo * oo;

int n;
int a[2005];
int m;
int b[2005];

void minaj(ll &aa, ll ba){if (aa > ba) aa = ba;}

ll f(ll v){
  v = -v;
  if (v%2 == 0) return v/2;
  if (v > 0) return v/2+1;
  return v/2;
}

vector < pair < ll, pii > > V;
ll v, r;

void GetBest(bool x, bool y){
  REP(i,m) REP(j,x?i:1) V.pb({b[i]+(x?b[j]:0), {i, j}});
  sort(V.begin(), V.end());
  REP(i,n) REP(j,x?i:1){
    ll cv = v-2*a[i]-2*(x?a[j]:0);
    int p = lower_bound(V.begin(), V.end(), pair<ll,pii>{f(cv), {-1, -1}})-V.begin();
    for (int t : {p-1, p, p+1}) if (t >= 0 && t < (int)V.size()){
	ll cr = abs(cv+2*V[t].x);
	if (y && cr == r){
	  cout << 1+x << endl;
	  cout << i+1 << " " << V[t].y.x+1 << endl;
	  if (x) cout << j+1 << " " << V[t].y.y+1 << endl;
	  exit(0);
	} minaj(r, cr);
      }
  } V.clear();
}

#undef int
int main(){
#define int ll
  //ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  cin >> m;
  REP(i,m) cin >> b[i];

  ll sa = 0, sb = 0;
  REP(i,n) sa += a[i];
  REP(i,m) sb += b[i];
  v = sa-sb;
  r = abs(v);

  GetBest(false, false);
  GetBest(true, false);
  
  cout << r << endl;
  if (r == abs(v)){cout << 0 << endl; return 0;}

  GetBest(false, true);
  GetBest(true, true);
  
  return 0;
}