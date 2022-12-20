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

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

// Miller Test
struct IsPrime{
  const vl v = { 2 , 7 , 61 }; // < 4,759,123,141
  // vl v = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 }; ??
  
  vl e;
  ll modpow( ll x , ll k , ll mo ){
    ll res = 1;
    while( k ){
      if( k & 1 ) res = ( res * x ) % mo;
      k /= 2;
      x = ( x * x ) % mo;
    }
    return res;
  }
  IsPrime(){
    e = vl( 63 , 1 );
    FOR( i , 1 , 63 ) e[i] = e[i-1] * 2;
  }
  bool check( ll n ){
    if( n < 2 ) return false;
    
    ll d = n - 1, s = 0;
    while( d % 2 == 0 ) d /= 2, s++;

    YYS( a , v ){
      if( a == n ) return true;
      if( modpow( a , d , n ) != 1 ){
	bool ok = true;
	REP( r , s ) if( modpow( a , d * e[r] , n ) == n-1 ) ok = false;
	if( ok ) return false;
      }
    }
    
    return true;
  }
};

const int TH = 1000010;

bool bp[TH];
IsPrime isp;

pi ans[TH];

int n;

int main(){
  for( int j = 3; j < TH; j += 2 ) bp[j] = isp.check( j );

  ans[4] = pi( 2 , 2 );
  for( int i = 6; i < TH; i += 2 ){
    for( int j = 3; j < TH; j += 2 ) if( bp[j] && bp[i-j] ){
	ans[i] = pi( j , i-j );
	break;
      }
  }

  scanf( "%d" , &n );

  for( int i = n; i >= 0; i -= 2 ){
    if( isp.check( i ) ){
      if( i == n ) printf( "1\n%d\n" , i );
      else if( i == n-2 ) printf( "2\n%d %d\n" , i , 2 );
      else printf( "3\n%d %d %d\n" , i , ans[n-i].fi , ans[n-i].se );
      break;
    }
  }
  
  return 0;
}