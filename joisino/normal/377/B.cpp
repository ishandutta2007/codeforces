#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

typedef pair<ll,pl> P;

int n, m;
ll s;
pl a[MAX_N];
P b[MAX_N];
int ans[MAX_N];

bool check( ll d ){
  priority_queue<pl,vpl,greater<pl> > que;
  int c = 0;
  ll co = 0;
  REP( i , (m+d-1)/d ){
    while( i*d < m && c < n && a[i*d].fi <= b[c].fi ) que.push( b[c++].se );
    if( que.empty() ) return false;
    REP( j , d ) if( i*d+j < m ) ans[ a[i*d+j].se ] = que.top().se;
    co += que.top().fi;
    que.pop();
  }
  return co <= s;
}

int main(){

  scanf( "%d %d %lld" , &n , &m , &s );
  REP( i , m ) scanf( "%lld" , &a[i].fi );
  REP( i , m ) a[i].se = i;
  sort( a , a+m ); reverse( a , a+m );
  REP( i , n ) scanf( "%lld" , &b[i].fi );
  REP( i , n ) scanf( "%lld" , &b[i].se.fi );
  REP( i , n ) b[i].se.se = i;
  sort( b , b+n ); reverse( b , b+n );

  ll lb = 0, ub = m+1;
  while( ub-lb > 1 ){
    ll md = (lb+ub)/2;
    if( check(md) ) ub = md;
    else lb = md;
  }

  if( ub == m+1 ) return puts( "NO" );

  check( ub );
  
  printf( "YES\n" );
  REP( i , m ){
    if( i != 0 ) printf( " " );
    printf( "%d" , ans[i]+1 );
  }
  printf( "\n" );
  
  return 0;
}