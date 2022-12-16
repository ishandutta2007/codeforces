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

const ll MAX_N = 200010;
const ll B = 512;

ll n, m, q;

set<int> ss[MAX_N], is[MAX_N];
map<int,vi> G[MAX_N];
ll deg[MAX_N];

set<int> usedc[MAX_N];

set<int> used;

map<int,vi> ans;

void dfs( int x , int c ){
  used.insert( x );
  YYS( w , G[x][c] ) if( used.find( w ) == used.end() ) dfs( w , c );
}

void dfs2( int x , int c , int p ){
  usedc[x].insert( c );
  used.insert( x );
  is[x].insert( p );
  ss[p].insert( x );
  YYS( w , G[x][c] ) if( used.find( w ) == used.end() ) dfs2( w , c , p );
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , m ){
    ll a, b, c;
    scanf( "%lld %lld %lld" , &a , &b , &c ); a--; b--;
    G[a][c].pb( b );
    G[b][c].pb( a );
    deg[a]++; deg[b]++;
  }
  
  REP( i , n ) if( deg[i] > B ){
    ans[i] = vi( n , 0 );
    YYS( v , G[i] ){
      used.clear();
      dfs( i , v.fi );
      YYS( w , used ) ans[i][w]++;
    }
  }

  used.clear();
  ll p = 0;
  REP( i , n ) YYS( v , G[i] ) if( usedc[i].find( v.fi ) == usedc[i].end() ){
    used.clear();
    dfs2( i , v.fi , p++ );
  }

  scanf( "%lld" , &q );
  REP( i , q ){
    ll a, b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    if( deg[a] > B ){
      printf( "%d\n" , ans[a][b] );
    } else if( deg[b] > B ){
      printf( "%d\n" , ans[b][a] );
    } else {
      if( SZ(is[a]) > SZ(is[b]) ) swap( a , b );
      int res = 0;
      YYS( w , is[a] ) if( ss[w].find( b ) != ss[w].end() ) res++;
      printf( "%d\n" , res );
    }
  }

  return 0;
}