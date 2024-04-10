#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb emplace_back

using namespace std;

typedef int64_t ll;
typedef long double ld;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-11;

template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

typedef pair<ll,ll> P;
#define fi first
#define se second

struct Unionfind{
  vector<int> size;
  vector<int> par;

  Unionfind( int n ) :  size(n,1), par(n){
    iota( par.begin() , par.end() , 0 );
  }
  
  int find( int x ){
    if( par[x] == x ) return x;
    return par[x] = find( par[x] );
  }

  bool unite( int x , int y ){
    x = find(x);
    y = find(y);
    if( x == y ) return false;

    if( size[y] < size[x] ) swap( x , y );

    par[x] = y;
    size[y] += size[x];

    return true;
  }

  bool same( int x , int y ){
    return find(x) == find(y);
  }
};

const int MAX_N = 300010;
ll dist[MAX_N];

struct edge{
  ll fr, to, co, id;
  edge(){}
  edge( ll fr , ll to , ll co , ll id ) : fr(fr) , to(to) , co(co) , id(id) {}
  bool operator <( const edge &a ) const{
    if( dist[fr]+co != dist[a.fr]+a.co ) return dist[fr]+co > dist[a.fr]+a.co;
    return co > a.co;
  }
};


vector<edge> G[MAX_N];

ll dijkstra( int s , int t ){
  REP( i , MAX_N )
    dist[i] = INFLL;
  dist[s] = 0;
  
  priority_queue<P,vector<P>,greater<P> > que;
  que.push( P( 0 , s ) );
  
  while( !que.empty() ){
    ll d = que.top().fi;
    int p = que.top().se;
    que.pop();
    if( d > dist[p] ) continue;
    REP( i , G[p].size() ){
      int to = G[p][i].to;
      ll co = G[p][i].co;
      if( d+co < dist[to] ){
	dist[to] = d+co;
	que.push( P( dist[to] , to ) );
      }
    }
  }

  return dist[t];
}



vector<int> ans;
ll ansv;

int main(){

  int n, m;
  cin >> n >> m;

  Unionfind uni(n+1);
  
  REP( i , m ){
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].pb( edge( a , b , c , i+1 ) );
    G[b].pb( edge( b , a , c , i+1 ) );
  }

  int u;
  cin >> u;

  dijkstra( u , 0 );

  priority_queue<edge> que;
  REP( i , G[u].size() )
    que.push( G[u][i] );

  FOR( i , 1 , n ){
    edge e;
    while( 1 ){
      e = que.top();
      if( !uni.same( u , e.to ) && dist[e.fr]+e.co == dist[e.to] ) break;
      que.pop();
    }
    uni.unite( u , e.to );
    ans.pb( e.id );
    ansv += e.co;
    REP( i , G[e.to].size() )
      que.push( G[e.to][i] );
  }

  cout << ansv << endl;
  REP( i , n-1 ){
    if( i != 0 ) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  
  return 0;
}