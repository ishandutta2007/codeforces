#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const ll INF = 1e9+10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct Unionfind{
  vi size, par;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n ) par[i] = i;
  }
  void init( int n ){
    size = vi( n , 1 );
    par.resize( n );
    REP( i , n ) par[i] = i;
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

const int MAX_N = 100010;

int n;
vl ds[MAX_N];
vpl dist;

int qs;
ll l;

bool used[MAX_N];

vpl G[MAX_N];

Unionfind uf;

ll dfs1( int x , int p ){
  ds[x].pb( 0 );
  YYS( w , G[x] ) if( w.fi != p ) ds[x].pb( dfs1( w.fi , x ) + w.se );
  return *max_element(ALL(ds[x]));
}

void dfs2( int x , int p , ll d ){
  ds[x].pb( d );
  SORT( ds[x] ); REVERSE( ds[x] );
  dist.pb( ds[x][0] , x );
  YYS( w , G[x] ) if( w.fi != p ){
    if( *max_element(ALL(ds[w.fi])) + w.se == ds[x][0] ) dfs2( w.fi , x , ds[x][1] + w.se );
    else dfs2( w.fi , x , ds[x][0] + w.se );
  }
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    ll x, y, z;
    scanf( "%lld %lld %lld" , &x , &y , &z ); x--; y--;
    G[x].pb( y , z );
    G[y].pb( x , z );
  }

  dfs1( 0 , -1 );
  dfs2( 0 , -1 , 0 );

  SORT( dist ); REVERSE( dist );
  
  scanf( "%d" , &qs );
  REP( query_cnt , qs ){
    scanf( "%lld" , &l );
    
    uf.init( n );
    REP( i , n ) used[i] = false;
    
    int ans = 0;
    int p = 0;
    REP( i , n ){
      while( p < n && dist[p].fi >= dist[i].fi - l ){
	YYS( w , G[dist[p].se] ) if( used[w.fi] ) uf.unite( dist[p].se , w.fi );
	chmax( ans , uf.size[uf.find(dist[p].se)] );
	used[dist[p].se] = true;
	p++;
      }
      uf.size[uf.find(dist[i].se)]--;
    }
    printf( "%d\n" , ans );
  }
  
  return 0;
}