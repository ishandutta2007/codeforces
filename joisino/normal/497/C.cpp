#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 200010;

typedef pair<pi,int> pii;
typedef pair<pi,pi> pipi;
typedef vector<pii> vpii;
typedef vector<pipi> vpipi;

int n, m;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N], k[MAX_N];

vpii ps;
vpipi as;
multiset<pipi> ss;

int ans[MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%d %d" , &a[i] , &b[i] );
    ps.pb( pii( pi( a[i], b[i] ) , i ) );
  }
  sort( ALL(ps) );

  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%d %d %d" , &c[i] , &d[i] , &k[i] );
    as.pb( pipi( pi( c[i] , d[i] ) , pi( k[i] , i ) ) );
  }
  sort( ALL(as) );

  int q = 0;
  REPR( p , ps ){
    while( q < m && as[q].fi.fi <= p.fi.fi ){
      ss.insert( pipi( pi( as[q].fi.se , as[q].fi.fi ) , as[q].se ) );
      q++;
    }
    auto ite = ss.lower_bound( pipi( pi( p.fi.se , -INF ) , pi( -INF , -INF ) ) );
    if( ite == ss.end() ){
      printf( "NO\n" );
      return 0;
    }
    pipi x = *ite;
    ss.erase( ite );
    ans[p.se] = x.se.se+1;
    x.se.fi--;
    if( x.se.fi > 0 ) ss.insert( x );
  }

  printf( "YES\n" );
  REP( i , n ){
    if( i != 0 ) printf( " " );
    printf( "%d" , ans[i] );
  }
  printf( "\n" );
  
  return 0;
}