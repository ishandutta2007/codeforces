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

struct dat{
  int par;
  vi v;
  dat(){}
  dat( int par , vi v ) : par(par), v(v) {}
};

int n, m, q;
vi G[100010];

dat p[100010][20];

ll d[100010];

vi c[100010];

void dfs( int x , int par , int dep = 0 ){
  p[x][0] = dat( par , c[x] );
  d[x] = dep;
  YYS( w , G[x] ){
    if( w == par ){
      continue;
    }
    dfs( w , x , dep+1 );
  }
}

dat merge( dat a , dat b ){
  dat res = dat( b.par , {} );
  int ia = 0;
  int ib = 0;
  while( ( ia < SZ(a.v) or ib < SZ(b.v) ) and SZ(res.v) < 10 ){
    if( ia == SZ(a.v) ){
      res.v.pb( b.v[ib] );
      ib++;
    } else if( ib == SZ(b.v) ){
      res.v.pb( a.v[ia] );
      ia++;
    } else if( a.v[ia] <= b.v[ib] ){
      res.v.pb( a.v[ia] );
      ia++;
    } else {
      res.v.pb( b.v[ib] );
      ib++;
    }
  }
  return res;
}

int main(){

  n = in();
  m = in();
  q = in();
  REP( i , n-1 ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , m ){
    int a = in() - 1;
    c[a].pb( i );
  }

  REP( i , n ){
    SORT( c[i] );
    if( SZ(c[i]) > 10 ){
      c[i].resize( 10 );
    }
  }
  
  dfs( 0 , -1 );

  REP( i , 19 ){
    REP( j , n ){
      if( p[j][i].par == -1 ){
        p[j][i+1] = p[j][i];
      } else {
        p[j][i+1] = merge( p[j][i], p[ p[j][i].par ][i] );
      }
    }
  }

  REP( i , q ){
    ll a = in() - 1;
    ll b = in() - 1;
    ll sz = in();
    if( d[a] > d[b] ){
      swap( a , b );
    }
    // cout << a << " " << b << endl;
    // cout << d[a] << " " << d[b] << endl;
    dat v( -1 , {} );
    REP( i , 20 ){
      if( ( d[b] - d[a] ) & PW(i) ){
        v = merge( v , p[b][i] );
        b = p[b][i].par;
      }
    }
    if( a != b ){
      for( int i = 19; i >= 0; i-- ){
        if( p[a][i].par != p[b][i].par ){
          v = merge( v , p[a][i] );
          a = p[a][i].par;
          v = merge( v , p[b][i] );
          b = p[b][i].par;
        }
      }
      assert( p[a][0].par == p[b][0].par );
      v = merge( v , p[a][0] );
      a = p[a][0].par;
      v = merge( v , p[b][0] );
      b = p[b][0].par;
    }
    v = merge( v , dat( -1 , c[a] ) );
    int k = min( sz , SZ(v.v) );
    // cout << a << endl;
    printf( "%d" , k );
    REP( i , k ){
      printf( " %d" , v.v[i] + 1 );
    }
    printf( "\n" );
    // cout << "------" << endl;
  }
  
  return 0;
}