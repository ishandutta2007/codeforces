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

const ll MAX_N = 2010;

typedef pair<ll,pl> ed;

ll n;
ll d[MAX_N][MAX_N];

vector<ed> edges;

vpl G[MAX_N];

Unionfind uf;

ll dist[MAX_N];

int ng(){
  printf( "NO\n" );
  return 0;
}

void dfs( ll x , ll p , ll d ){
  dist[x] = d;
  YYS( w , G[x] ) if( w.fi != p ) dfs( w.fi , x , d + w.se );
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) REP( j , n ) scanf( "%lld" , &d[i][j] );

  REP( i , n ) REP( j , n ) if( i != j ) edges.pb( d[i][j] , pl( i , j ) );
  SORT( edges );

  uf.init( n );
  YYS( w , edges ){
    if( !uf.same( w.se.fi , w.se.se ) ){
      if( w.fi == 0 ) return ng();
      uf.unite( w.se.fi , w.se.se );
      G[w.se.fi].pb( w.se.se , w.fi );
      G[w.se.se].pb( w.se.fi , w.fi );
    }
  }

  REP( i , n ){
    REP( j , n ) dist[j] = 0;
    dfs( i , -1 , 0 );
    REP( j , n ) if( dist[j] != d[i][j] ) return ng();
  }

  printf( "YES\n" );
  
  return 0;
}