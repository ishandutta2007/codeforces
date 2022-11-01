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

namespace Mcmf{
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const ll oo = 1e18;

  int V, E;
  int last[MAXV], curr[MAXV], bio[MAXV]; double pi[MAXV];
  int next[MAXE], adj[MAXE]; ll cap[MAXE]; double cost[MAXE];

  void init(int n){
    V = n;
    E = 0;
    REP(i,V) last[i] = -1;
    REP(i,V) pi[i] = 0;
  }

  void edge(int x, int y, ll c, double w){
    adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  const double eps = 1e-9;
  bool lt(double a, double b){return a+eps < b;}
  bool eq(double a, double b){return !lt(a, b) && !lt(b, a);}

  ll push(int x, int sink, ll flow){
    if (x == sink) return flow;
    if (bio[x]) return 0;
    bio[x] = true;

    for (int &e = curr[x]; e != -1; e = next[e]){
      int y = adj[e];

      if (cap[e] && eq(pi[x], pi[y] + cost[e]))
	if (ll f = push(y, sink, min(flow, cap[e])))
	  return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }
  
  pair < double, ll > run(int src, int sink){
    double total = 0;
    ll flow = 0;

    for (;;){
      REP(i,V) bio[i] = false;
      REP(i,V) curr[i] = last[i];

      while (ll f = push(src, sink, oo)){
	total += pi[src] * (double)f;
	flow += f;
	REP(i,V) bio[i] = false;
      }

      double inc = (double)oo;
      REP(x,V) if (bio[x]){
	for (int e = last[x]; e != -1; e = next[e]){
	  int y = adj[e];
	  if (cap[e] && !bio[y]) inc = min(inc, pi[y] + cost[e] - pi[x]);
	}
      }
      if (inc == (double)oo) break;

      REP(i,V) if (bio[i]) pi[i] += inc;
    }
    return {total, flow};
  }
  
}

int n;
pii s[405];

double d(pii a, pii b){
  a.x -= b.x;
  a.y -= b.y;
  return sqrt(a.x*a.x+a.y*a.y);
}

int main(){

  cin >> n;
  REP(i,n) cin >> s[i].x >> s[i].y;

  Mcmf::init(2*n+2);

  REP(i,n) Mcmf::edge(0, i+1, 1, 0);
  REP(i,n) Mcmf::edge(i+1+n, 2*n+1, 2, 0);
  REP(i,n) REP(j,n) if (s[i].y < s[j].y) Mcmf::edge(i+1, j+n+1, 1, d(s[i], s[j]));

  auto R = Mcmf::run(0, 2*n+1);
  if (R.y != n-1) cout << -1 << endl;
  else cout << setprecision(25) << R.x << endl;
  
  return 0;
}