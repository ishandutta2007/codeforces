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

template<class T>
class MinOp{
public:
  T operator () ( T a , T b ){ return min( a , b ); }
};
template<class T>
class MaxOp{
public:
  T operator () ( T a , T b ){ return max( a , b ); }
};
template<class T>
class GcdOp{
public:
  T operator () ( T a , T b ){ return __gcd( a , b ); }
};


template<typename T, typename OpFunc>
struct SparseTable{
  OpFunc op;
  int size;
  vi lg;
  vector<vector<T> > table;
  void init( vector<T> array, OpFunc opfunc ){
    int n = array.size();
    op = opfunc;
    
    lg.assign( n + 1 , 0 );
    for( int i = 1; i <= n; i++ ){
      lg[i] = 31 - __builtin_clz( i );
    }

    table.assign( lg[n] + 1, array );
    for( int i = 1; i <= lg[n]; i++ ){
      for( int j = 0; j < n; j++ ){
        if( j + PW(i-1) < n ){
          table[i][j] = op( table[i-1][j] , table[i-1][j+PW(i-1)] );
        } else {
          table[i][j] = table[i-1][j];
        }
      }
    }
  }
  T query( int l , int r ){
    return op( table[ lg[r-l] ][l], table[ lg[r-l] ][r-PW(lg[r-l])] );
  }
};

int n, q;

ll a[100010];
ll b[100010];

unordered_map<ll,ll> ma;

SparseTable<pl,MaxOp<pl> > table;

inline ll p( ll l , ll r ){
  return l * 100010 + r;
}

ll calc( ll l , ll r ){
  if( r - l <= 0 ){
    return 0;
  }
  if( ma.find( p( l , r ) ) != ma.end() ){
    return ma[ p( l , r ) ];
  }
  pl res = table.query( l , r );

  ll chl = calc( l , res.se );
  ll chr = calc( res.se + 1 , r );
  ll cur = ( res.se - l + 1 ) * ( r - res.se ) * res.fi;
  
  return ma[ p( l , r ) ] = chl + chr + cur;
}

int main(){
  
  n = in();
  q = in();

  REP( i , n ){
    a[i] = in();
  }
  REP( i , n-1 ){
    b[i] = abs( a[i+1] - a[i] );
  }

  vector<pl> ar(n-1);
  REP( i , n-1 ){
    ar[i] = pl( b[i] , i );
  }

  table.init( ar , MaxOp<pl>() );
  
  REP( i , q ){
    int l = in() - 1;
    int r = in() - 1;
    printf( "%lld\n" , calc( l , r ) );
  }
  
  return 0;
}