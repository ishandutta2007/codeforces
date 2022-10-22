#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 1e5+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;
vi g[mn],w[mn];
ll dis[mn];
bool vis[mn];

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};


void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back(b);
    g[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  memset(dis,0x3f,sizeof(dis));
  dis[1]=0;
  auto dijkstra = [&](){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)pq.push({dis[i],i});
    while(pq.size()){
      auto [d,x] = pq.top();
      pq.pop();
      if(vis[x])continue;
      vis[x]=1;
      dis[x]=d;
      for(int i=0;i<g[x].size();i++){
        pq.push({d+w[x][i],g[x][i]});
      }
    }
  };
  auto heelp = [&](){
    LineContainer lc;
    for(int i=1;i<=n;i++){
      if(dis[i]==inf)continue;
      lc.add(2*i,-(ll(i)*i+dis[i]));
    }
    for(int i=1;i<=n;i++){
      dis[i]=-lc.query(i)+ll(i)*i;
      //cerr<<i<<" "<<dis[i]<<endl;
    }
  };
  dijkstra();
  
  for(int i=0;i<k;i++){
    heelp();
    //cerr<<dis[1]<<endl;
    dijkstra();
  }
  for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
  printf("\n");
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc=1;
  //cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}