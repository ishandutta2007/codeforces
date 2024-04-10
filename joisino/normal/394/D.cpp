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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll MAX_N = 1024;

ll n;
ll a[MAX_N];

ll ansv = INFLL;
ll anss = 0, ansi = 0;

ll b, st;

ll get( ll x ){
  return st * x + b;
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  sort( a , a+n );
  
  REP( i , INFLL ){
    if( i >= ansv ) break;
    
    REP( swap_swap , 2 ){
      b = a[0] + i;

      ll max_step = 0;
      REP( j , n ) if( j != 0 ) chmax( max_step , ( a[j] - b ) / j );

      REP( j , max_step + 2 ){
	st = j;
	if( get(n-1) - a[n-1] >= ansv ) break;
	
	ll res = 0;
	REP( k , n ){
	  chmax( res , abs( a[k] - get(k) ) );
	  if( res >= ansv ) break;
	}
	
	if( res < ansv ){
	  ansv = res;
	  anss = st;
	  ansi = b;
	}
      }
      
      i *= -1;
    }
    
  }

  printf( "%lld\n" , ansv );
  printf( "%lld %lld\n" , ansi , anss );
  
  return 0;
}