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

struct KMP{
  vl fail;
  string s;
  void init( string arg_s ){
    s = arg_s;
    fail.resize( SZ(s) );
    fail[0] = -1, fail[1] = 0;
    ll p = 0;
    FOR( q , 2 , SZ(s) ){
      while( p >= 0 && s[q-1] != s[p] ) p = fail[p];
      fail[q] = ++p;
    }
  }
  vl query( string t ){
    ll p = 0, q = 0;
    vl res(0);
    while( p + q < SZ(t) ){
      if( s[q] == t[p+q] ){
	if( q == SZ(s)-1 ) res.pb( p ), p += q - fail[q], q = fail[q];
	else q++;
      } else {
	p += q - fail[q];
	if( q > 0 ) q = fail[q];
      }
    }
    return res;
  }
};

const ll MAX_N = 5010;

char s[MAX_N];

KMP kmp;

ll ans;

int main(){
  kmp.init( "bear" );

  scanf( "%s" , s );
  ll n = strlen( s );
  vl res = kmp.query( s );

  REP( i , n ){
    auto ite = lower_bound( ALL(res) , i );
    if( ite != res.end() ) ans += n - ( (*ite) + 3 );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}