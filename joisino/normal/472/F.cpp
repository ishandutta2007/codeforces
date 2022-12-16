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

const ll MAX_N = 10010;

ll n;
ll base[32];
ll x[MAX_N], y[MAX_N];

ll repr[32];

vpl ans, la;

bool is_base[MAX_N];
bool used[32];

vl amari;

vpl bases;

ll nb[32];
ll nrepr[32];

ll p = 0;

ll ix[MAX_N], iy[MAX_N];

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &x[i] );
  REP( i , n ) scanf( "%lld" , &y[i] );

  REP( i , n ) ix[i] = x[i], iy[i] = y[i];

  REP( i , 32 ) base[i] = -1;

  REP( i , n ){
    ll cur = 0;
    REP( j , 32 ) if( x[i] & PW(j) ){
      if( base[j] != -1 ){
	x[i] ^= x[ base[j] ];
	cur ^= repr[j];
      } else {
	base[j] = i;
	repr[j] = cur | PW(j);
	is_base[i] = true;
	bases.pb( j , i );
	break;
      }
    }
  }

  REP( i , n ){
    ll cur = 0;
    REP( j , 32 ) if( y[i] & PW(j) ){
      if( base[j] != -1 ){
	y[i] ^= x[ base[j] ];
	cur ^= repr[j];
      } else {
	printf( "-1\n" );
	return 0;
      }
    }

    if( is_base[i] ){
      amari.pb( cur );
      continue;
    }
    ans.pb( i , i );
    REP( j , 32 ) if( cur & PW(j) ) ans.pb( i , base[j] );
  }

  ll nn = SZ(amari);
  
  REP( i , nn ) REP( j , nn ) if( amari[i] & PW(bases[j].fi) ) nrepr[i] |= PW(j);

  REP( i , nn ){
    FOR( j , i , nn ) if( nrepr[j] & PW(i) ){
      if( i == j ) break;
      la.pb( bases[i].se , bases[j].se );
      la.pb( bases[j].se , bases[i].se );
      la.pb( bases[i].se , bases[j].se );
      swap( nrepr[i] , nrepr[j] );
    }
    if( nrepr[i] & PW(i) ){
      FOR( j , i+1 , nn ) if( nrepr[j] & PW(i) ){
	la.pb( bases[j].se , bases[i].se );
	nrepr[j] ^= nrepr[i];
      }
    }
  }

  REP( i , nn ){
    if( !( nrepr[i] & PW(i) ) ) ans.pb( bases[i].se , bases[i].se );
    FOR( j , i+1 , nn ) if( nrepr[i] & PW(j) ) ans.pb( bases[i].se , bases[j].se );
  }

  REVERSE( la );
  YYS( w , la ) ans.pb( w );
  
  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi+1 , w.se+1 );

  return 0;
}