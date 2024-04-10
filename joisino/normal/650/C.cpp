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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

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

Unionfind uf;

int n, m;

int ans[1000010];
bool used[1000010];

vi Ga[1000010];
vi G[1000010];

mi a;

int p( int y , int x ){
  return y * m + x;
}

void dfs( int x ){
  used[x] = true;
  ans[x] = 1;
  YYS( w , G[x] ){
    if( !used[w] ){
      dfs( w );
    }
    chmax( ans[x] , ans[w] + 1 );
  }
}

int main(){

  n = in();
  m = in();
  a.assign( n , vi(m) );
  REP( i , n ){
    REP( j , m ){
      a[i][j] = in();
    }
  }

  uf.init( n * m );
  
  REP( i , n ){
    vpi v(0);
    REP( j , m ){
      v.pb( a[i][j], p( i , j ) );
    }
    SORT( v );
    REP( i , m-1 ){
      if( v[i].fi == v[i+1].fi ){
        uf.unite( v[i].se, v[i+1].se );
      } else {
        Ga[ v[i+1].se ].pb( v[i].se );
      }
    }
  }

  REP( j , m ){
    vpi v(0);
    REP( i , n ){
      v.pb( a[i][j], p( i , j ) );
    }
    SORT( v );
    REP( i , n-1 ){
      if( v[i].fi == v[i+1].fi ){
        uf.unite( v[i].se, v[i+1].se );
      } else {
        Ga[ v[i+1].se ].pb( v[i].se );
      }
    }
  }

  REP( i , n*m ){
    YYS( w , Ga[i] ){
      if( uf.find( i ) != uf.find( w ) ){
        G[ uf.find( i ) ].pb( uf.find( w ) );
      }
    }
  }
  
  REP( i , n*m ){
    if( !used[ uf.find(i) ] ){
      dfs( uf.find( i ) );
    }
  }

  REP( i , n ){
    REP( j , m ){
      if( j != 0 ){
        printf( " " );
      }
      printf( "%d" , ans[ uf.find( p( i , j ) ) ] );
    }
    printf( "\n" );
  }

  return 0;
}