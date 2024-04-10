#include <bits/stdc++.h>
  
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
 
#define pb emplace_back
#define fi first
#define se second

using namespace std;
 
typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
 
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head



template<typename T>
struct Dijkstra{
  typedef vector<T> vt;
  typedef pair<int,T> pit;
  typedef pair<T,int> pti;  
  typedef vector<pit> vpit;
  typedef vector<vpit> Graph;
  const T INFT = INFLL;
   
  Graph G;
  vt dist;
  int n;
  void init( int arg_n ){
    n = arg_n;
    G = Graph( n , vpit(0) );
    dist = vt( n );
  }
  void add_biedge( int fr , int to , T co ){
    G[fr].pb( to , co );
    G[to].pb( fr , co );
  }
  void add_edge( int fr , int to , T co ){
    G[fr].pb( to , co );
  }
  T dijkstra( int s , int t = 0 ){
    dist = vt( n , INFT );
    dist[s] = 0;
 
    priority_queue<pti,vector<pti>,greater<pti> > que;
    que.push( pti( 0 , s ) );
 
    while( !que.empty() ){
      T d = que.top().fi;
      int p = que.top().se;
      que.pop();
      if( d > dist[p] ) continue;
      YYS( w , G[p] ){
	int to = w.fi;
	T co = w.se;
	if( d + co < dist[to] ){
	  dist[to] = d + co;
	  que.push( pti( dist[to] , to ) );
	}
      }
    }
 
    return dist[t];
  }
};

typedef pair<pi,ll> ed;

Dijkstra<ll> dij;

int n, m, l, s, t;

vector<ed> G;
vector<pi> ps;

ll calc( int p ){
  dij.init( n );
  YYS( w , G ) dij.add_biedge( w.fi.fi, w.fi.se, w.se );
  REP( i , p ) dij.add_biedge( ps[i].fi, ps[i].se, 1 );
  FOR( i , p , SZ(ps) ) dij.add_biedge( ps[i].fi, ps[i].se, INF );
  return dij.dijkstra( s , t );
}

ll calc2( int p , ll d ){
  dij.init( n );
  YYS( w , G ) dij.add_biedge( w.fi.fi, w.fi.se, w.se );
  REP( i , p-1 ) dij.add_biedge( ps[i].fi, ps[i].se, 1 );
  if( p > 0 ) dij.add_biedge( ps[p-1].fi , ps[p-1].se , d );
  FOR( i , p , SZ(ps) ) dij.add_biedge( ps[i].fi, ps[i].se, INF );
  return dij.dijkstra( s , t );
}


int main(){

  scanf( "%d %d %d %d %d" , &n , &m , &l , &s , &t );

  REP( i , m ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c );

    if( c == 0 ){
      ps.pb( a , b );
    } else {
      G.pb( pi( a , b ) , c );
    }
  }

  if( !( calc(SZ(ps)) <= l && l <= calc(0) ) ){
    puts( "NO" );
    return 0;
  }

  int lb = -1, ub = SZ(ps);
  while( ub - lb > 1 ){
    int md = ( lb + ub ) / 2;
    if( calc( md ) <= l ) ub = md;
    else lb = md;
  }

  int p = ub;

  assert( calc(p) <= l );

  lb = 1; ub = INF;
  while( ub - lb > 1 ){
    int md = ( lb + ub ) / 2;
    if( calc2( p , md ) <= l ) lb = md;
    else ub = md;
  }
  
  assert( calc2( p , lb ) == l );

  printf( "YES\n" );
  YYS( w , G ) printf( "%d %d %lld\n" , w.fi.fi , w.fi.se , w.se );
  REP( i , p-1 ) printf( "%d %d %d\n" , ps[i].fi, ps[i].se, 1 );
  if( p > 0 ) printf( "%d %d %d\n" , ps[p-1].fi , ps[p-1].se , lb );
  FOR( i , p , SZ(ps) ) printf( "%d %d %lld\n" , ps[i].fi, ps[i].se, INF );
  
  return 0;
}