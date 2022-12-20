#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
ll a[MAX_N];
ll sum[MAX_N];

typedef pair<vpl,ll> re;

re rec( int l , int r ){
  if( r-l == 0 ) return re( vpl(0) , INFLL );
  if( r-l == 1 ) return re( vpl(1,pl(sum[l],l)) , INFLL );

  ll md = (l+r)/2;
  re res1 = rec( l , md );
  re res2 = rec( md , r );
  ll res = min( res1.se , res2.se );
  
  vpl ys( r-l );
  merge( ALL(res1.fi) , ALL(res2.fi) , ys.begin() );

  double fres = sqrt( res ) + 1;
  
  vpl ps;
  REPR( w , ys ){
    int i = w.se; ll s = w.fi;
    if( abs( md - i ) > fres ) continue;
    auto ite = lower_bound( ALL(ps) , pl( s - fres , -INFLL ) );
    for( ; ite != ps.end(); ite++ ){
      if( (*ite).se != i ) chmin( res , ( i - (*ite).se ) * ( i - (*ite).se ) + ( s - (*ite).fi ) * ( s - (*ite).fi ) );
      if( (*ite).fi > s + sqrt( res ) + 1 ) break;
    }
    ps.pb( w );
  }
  return mp( ys , res );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) sum[i+1] = sum[i] + a[i];

  printf( "%lld\n" , rec( 1 , n+1 ).se );
  
  return 0;
}