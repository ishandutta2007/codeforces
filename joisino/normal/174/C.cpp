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

const int MAX_N = 100010;

int n, a;
set<int> fr, to;

vi v[MAX_N];

vpi ans;

void del( int x ){
  bool f = fr.find( x ) != fr.end();
  bool t = to.find( x + 1 ) != to.end();

  if( f ) fr.erase( x );
  if( !t ) fr.insert( x + 1 );

  if( t ) to.erase( x + 1 );
  if( !f ) to.insert( x );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%d" , &a );
    v[a].pb( i );
  }

  fr.insert( 0 );
  to.insert( n );

  REP( i , INF ){
    YYS( w , v[i] ) del( w );
    if( fr.empty() ) break;
    YYS( w , fr ){
      auto ite = to.lower_bound( w );
      ans.pb( w , *ite );
    }
  }

  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%d %d\n" , w.fi+1 , w.se );
  
  return 0;
}