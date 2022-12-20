#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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


ll largest_histgram( vl v , int x ){
  int n = v.size();
  vl l(n,0), r(n,n);
  stack<int> st;
  REP( i , n ){
    while( !st.empty() && v[st.top()] >= v[i] ) st.pop();
    if( !st.empty() ) l[i] = st.top()+1;
    st.push( i );
  }
  while( !st.empty() ) st.pop();
  for( int i = n-1; i >= 0; i-- ){
    while( !st.empty() && v[st.top()] >= v[i] ) st.pop();
    if( !st.empty() ) r[i] = st.top();
    st.push( i );
  }
  ll res = 0;
  REP( i , n ) if( l[i] <= x && x < r[i] ) chmax( res , v[i] * ( r[i] - l[i] ) );
  return res;
}

const int MAX_N = 1010;

int n, m, q;
int a[MAX_N][MAX_N];

int u[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int l[MAX_N][MAX_N];
int r[MAX_N][MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &m , &q ); n += 2; m += 2;
  FOR( i , 1 , n-1 ) FOR( j , 1 , m-1 ) scanf( "%d" , &a[i][j] );

  FOR( i , 1 , n-1 ) FOR( j , 1 , m-1 ){
    u[i][j] = u[i-1][j] + 1;
    if( a[i][j] == 0 ) u[i][j] = 0;
  }
  for( int i = n-2; i >= 1; i-- ) FOR( j , 1 , m-1 ){
      d[i][j] = d[i+1][j] + 1;
      if( a[i][j] == 0 ) d[i][j] = 0;
  }
  FOR( i , 1 , n-1 ) FOR( j , 1 , m-1 ){
    l[i][j] = l[i][j-1] + 1;
    if( a[i][j] == 0 ) l[i][j] = 0;
  }
  FOR( i , 1 , n-1 ) for( int j = m-2; j >= 1; j-- ){
    r[i][j] = r[i][j+1] + 1;
    if( a[i][j] == 0 ) r[i][j] = 0;
  }
  
  REP( query_cnt , q ){
    int t, y, x;
    scanf( "%d %d %d" , &t , &y , &x );
    if( t == 1 ){
      a[y][x] = 1 - a[y][x];
      
      FOR( i , 1 , n-1 ){
	u[i][x] = u[i-1][x] + 1;
	if( a[i][x] == 0 ) u[i][x] = 0;
      }
      for( int i = n-2; i >= 1; i-- ){
	  d[i][x] = d[i+1][x] + 1;
	  if( a[i][x] == 0 ) d[i][x] = 0;
      }
      FOR( j , 1 , m-1 ){
	l[y][j] = l[y][j-1] + 1;
	if( a[y][j] == 0 ) l[y][j] = 0;
      }
      for( int j = m-2; j >= 1; j-- ){
	r[y][j] = r[y][j+1] + 1;
	if( a[y][j] == 0 ) r[y][j] = 0;
      }
    } else if( t == 2 ){
      ll ans = 0;
      vl v; v.clear();
      REP( i , m ) v.pb( u[y][i] );
      chmax( ans , largest_histgram( v , x ) );
      v.clear();
      REP( i , m ) v.pb( d[y][i] );
      chmax( ans , largest_histgram( v , x ) );
      v.clear();
      REP( i , n ) v.pb( l[i][x] );
      chmax( ans , largest_histgram( v , y ) );
      v.clear();
      REP( i , n ) v.pb( r[i][x] );
      chmax( ans , largest_histgram( v , y ) );
      v.clear();
      
      printf( "%lld\n" , ans );
    }
  }
  
  
  return 0;
}