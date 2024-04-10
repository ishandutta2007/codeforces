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

bool is_lucky( int x ){
  while( x > 0 ){
    if( x % 10 != 4 && x % 10 != 7 ) return false;
    x /= 10;
  }
  return true;
}

int n;
vi x, y;
pi a[MAX_N];
int to[MAX_N], fr[MAX_N];

int lp = -1;

vpi ans;

void swa( int s , int t ){
  fr[ to[s] ] = t;
  fr[ to[t] ] = s;
  swap( to[s] , to[t] );
  ans.pb( s , t );
  assert( fr[ to[s] ] == s );
  assert( to[ fr[s] ] == s );
  assert( fr[ to[t] ] == t );
  assert( to[ fr[t] ] == t );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i].fi );
  REP( i , n ) a[i].se = i;
  REP( i , n ) x.pb( a[i].fi );
  REP( i , n ) if( is_lucky( a[i].fi ) ) lp = i;
  sort( a , a+n );
  REP( i , n ) y.pb( a[i].fi );
  REP( i , n ) to[ a[i].se ] = i;
  REP( i , n ) fr[i] = a[i].se;
  if( lp == -1 ){
    if( x == y ) puts( "0" );
    else puts( "-1" );
    return 0;
  }

  REP( i , n ) if( fr[i] != lp ){
    if( i != lp ){
      swa( i , lp );
      lp = i;
    }
    int yuyu = fr[i];
    swa( lp , fr[i] );
    lp = yuyu;
  }

  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%d %d\n" , w.fi+1 , w.se+1 );
  
  return 0;
}