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

ll k, m;
ll ss[72];

ll pro;
vl ans;

void dfs( ll p , ll cur ){
  if( p == 4 ){
    cur = abs( cur );
    ll pa = abs( cur - k );
    if( pa < 10000 ){
      ans.pb( pro * 10000 + pa  );
      ans.pb( pa  * 10000 + pro );
    }
  } else {
    dfs( p+1 , ss[p]+cur );
    dfs( p+1 , ss[p]-cur );
    dfs( p+1 , ss[p]*cur );
  }
}

int main(){

  scanf( "%lld %lld" , &k , &m );
  REP( i , 10000 ){
    ll cur = i;
    REP( j , 4 ) ss[j] = cur % 10, cur /= 10;
    pro = i;
    dfs( 1 , ss[0] );
  }

  SORT( ans );
  UNIQUE( ans );

  ans.resize( m );

  YYS( w , ans ) printf( "%08lld\n" , w );
  
  return 0;
}