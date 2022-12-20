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
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct medge{
  int to , cap , rev;
  ld cost;
  medge(){}
  medge( int to , int cap , ld cost , int rev ) : to(to) , cap(cap) , cost(cost) , rev(rev){}
};
struct MinCostFlow{
  int V;
  vector<vector<medge> > G;
  vi prevv, preve;
  vd dist;

  void init( int n ){
    V = n;
    G = vector<vector<medge> >( n , vector<medge>(0) );
    prevv = preve = vi(n,0);
    dist =  vd(n,0);
  }

  void add_edge( int from , int to , int cap , ld cost ){
    G[from].pb( to , cap , cost , G[to].size() );
    G[to].pb( from , 0 , -cost , G[from].size()-1 );
  }

  ld min_cost_flow( int s , int t , int f ){
    ld res = 0;
    while( f > 0 ){
      dist = vd( V , INF );
      dist[s] = 0;
      bool update = true;
      while( update ){
	update = false;
	REP( v , V ){
	  if( dist[v] == INF ) continue;
	  REP( i , G[v].size() ){
	    medge &e = G[v][i];
	    if( e.cap > 0 && dist[e.to] > dist[v] + e.cost ){
	      dist[e.to] = dist[v] + e.cost;
	      prevv[e.to] = v;
	      preve[e.to] = i;
	      update = true;
	    }
	  }
	}
      }

      if( dist[t] == INF ) return -1;

      int d = f;
      for( int v = t; v != s; v = prevv[v] )
	d = min( d , G[prevv[v]][preve[v]].cap );

      f -= d;
      res += d * dist[t];
      for( int v = t; v != s; v = prevv[v] ){
	medge &e = G[prevv[v]][preve[v]];
	e.cap -= d;
	G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

const int MAX_N = 512;

MinCostFlow mcf;

int n;

int x[MAX_N], y[MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d %d" , &x[i] , &y[i] );

  int s = 2*n+1;
  int t = s+1;

  mcf.init( t+1 );

  REP( i , n ) REP( j , n ) if( y[j] < y[i] ) mcf.add_edge( i , j+n , 1 , hypotl( x[i] - x[j] , y[i] - y[j] ) );
  REP( i , n ) mcf.add_edge( s , i , 2 , 0 );
  REP( i , n ) mcf.add_edge( i+n , t , 1 , 0 );

  ld ans = mcf.min_cost_flow( s , t , n-1 );

  if( ans < 0 ) printf( "-1\n" );
  else printf( "%.18lf\n" , (double)ans );

  return 0;
}