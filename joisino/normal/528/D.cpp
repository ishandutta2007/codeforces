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

// 167772161, 3
// 469762049, 3
// 1224736769, 3

template< ll mod , ll r >
struct NTT{
  ll size;
  ll modpow( ll x , ll k ){
    ll res = 1;
    while( k > 0 ){
      if( k & 1 ) res = ( res * x ) % mod;
      x = ( x * x ) % mod;
      k >>= 1;
    }
    return res;
  }
  void ntt( vl &a , bool is_reverse = false ){
    ll h = modpow( r , ( mod - 1 ) / size );
    if( is_reverse ) h = modpow( h , mod-2 );

    ll s = 0;
    FOR( t , 1 , size-1 ){
      for( ll i = (size >> 1); i > ( s ^= i ); i >>= 1 );
      if( t < s ) swap( a[s] , a[t] );
    }

    for( s = 1; s < size; s <<= 1 ){
      ll g = modpow( h , size / ( 2 * s ) );
      ll w = 1;
      REP( i , s ){
	for( ll j = i; j < size; j += 2 * s ){
	  ll x = a[j], y = ( a[j+s] * w ) % mod;
	  a[j] = x + y > mod ? x + y - mod : x + y;
	  a[j+s] = x - y < 0 ? x - y + mod : x - y;
	}
	w = ( w * g ) % mod;
      }
    }
  }
  vl conv( vl a , vl b ){
    size = 1;
    while( size < SZ(a) + SZ(b) ) size *= 2;
    
    a.resize( size , 0 ); ntt( a );
    b.resize( size , 0 ); ntt( b );

    REP( i , size ) a[i] = ( a[i] * b[i] ) % mod;

    ntt( a , true );

    ll inv = modpow( size , mod-2 );
    REP( i , size ) a[i] = ( a[i] * inv ) % mod;
    REP( i , size ) if( a[i] < 0 ) a[i] += mod;
    
    return a;
  }
};

const ll MAX_N = 200010;

ll c[256];
ll sum[4][MAX_N];

void yuyu( char *s , ll n , vl *v , ll k ){
  REP( i , n+1 ) REP( j , 4 ) sum[j][i] = 0;
  REP( i , n ){
    sum[ c[ s[i] ] ][max(i-k,0LL)]++;
    sum[ c[ s[i] ] ][min(i+k+1,n)]--;
  }
  REP( i , n ) REP( j , 4 ) sum[j][i+1] += sum[j][i];

  REP( j , 4 ) v[j].resize( n );
  REP( i , n ) REP( j , 4 ) if( sum[j][i] > 0 ) v[j][i] = 1;
}

NTT<167772161,3> ntt;

ll n, m, k;
char s[MAX_N], t[MAX_N];

vl x[4], y[4], res[4];

ll ans;

int main(){

  c['A'] = 0; c['G'] = 1; c['C'] = 2; c['T'] = 3;

  scanf( "%lld %lld %lld" , &n , &m , &k );
  scanf( "%s %s" , s , t );

  yuyu( s , n , x , k );
  yuyu( t , m , y , 0 );
  
  REP( j , 4 ) REVERSE( y[j] );

  REP( i , 4 ) res[i] = ntt.conv( x[i] , y[i] );

  FOR( i , m-1 , n ) if( res[0][i] + res[1][i] + res[2][i] + res[3][i] == m ) ans++;

  printf( "%lld\n" , ans );
  
  return 0;
}