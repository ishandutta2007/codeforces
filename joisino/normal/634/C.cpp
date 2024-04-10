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

struct BIT{
  vl bit;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
  }
  void add( int k , ll v ){
    for( int i = k+1; i <= size; i += i & -i ) bit[i-1] += v;
  }
  ll sum( int k ){ // [0,k)
    ll res = 0;
    for( int i = k; i > 0; i -= i & -i ) res += bit[i-1];
    return res;
  }
  ll sum( int l , int r ){ // [l,r)
    return sum( r ) - sum( l );
  }
  ll get( int k ){
    return sum( k+1 ) - sum( k );
  }
  ll update( int k , ll x ){
    add( k , x - get(k) );
  }
};

BIT bita, bitb;

ll n, k, a, b, q;

ll c[200010];

int main(){

  n = in();
  k = in();
  a = in();
  b = in();
  q = in();

  bita.init( n );
  bitb.init( n );

  REP( qc , q ){
    int t = in();
    if( t == 1 ){
      ll x = in() - 1;
      ll y = in();
      c[x] += y;
      bitb.update( x , min( b , c[x] ) );
      bita.update( x , min( a , c[x] ) );
    } else if( t == 2 ){
      ll x = in() - 1;
      ll bb = bitb.sum( x );
      ll aa = bita.sum( n ) - bita.sum( x + k );
      ll ans = aa + bb;
      printf( "%lld\n" , ans );
    } else {
      assert( false );
    }
  }
  
  return 0;
}