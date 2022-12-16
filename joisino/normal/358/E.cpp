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

const ll MAX_N = 1010;
const ll dx[] = { 1 , 0 , -1 , 0 };
const ll dy[] = { 0 , -1 , 0 , 1 };

vl divisor( ll x ){
  vl res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}


ll n, m;
ll a[MAX_N][MAX_N];

bool used[MAX_N][MAX_N];

ll degodd;

vl xs, ys;

ll ans;

void bfs( ll sy , ll sx ){
  queue<pl> que;
  que.push( pl( sy , sx ) );
  used[sy][sx] = true;
  while( !que.empty() ){
    ll y = que.front().fi;
    ll x = que.front().se;
    que.pop();
    REP( i , 4 ){
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if( a[ny][nx] == 1 && !used[ny][nx] ){
	used[ny][nx] = true;
	que.push( pl( ny , nx ) );
      }
    }
  }
}

bool connect_check(){
  FOR( i , 1 , n+1 ) FOR( j , 1 , m+1 ) if( a[i][j] == 1 ){
    bfs( i , j );
    FOR( i , 1 , n+1 ) FOR( j , 1 , m+1 ) if( a[i][j] == 1 && !used[i][j] ) return false;
    return true;
  }
  return true;
}

int ng(){
  printf( "-1\n" );
  return 0;
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &a[i+1][j+1] );

  if( !connect_check() ) return ng();
  
  FOR( i , 1 , n+1 ) FOR( j , 1 , m+1 ) if( a[i][j] == 1 ){
    ll deg = 0;
    REP( k , 4 ) if( a[i+dy[k]][j+dx[k]] == 1 ){
      deg++;
      if( a[i+dy[(k+1)%4]][j+dx[(k+1)%4]] == 1 || a[i+dy[(k+3)%4]][j+dx[(k+3)%4]] == 1 ) ys.pb( i ), xs.pb( j );
    }
    if( deg % 2 == 1 ){
      ys.pb( i ), xs.pb( j );      
      degodd++;
    }
    if( deg == 0 ) return ng();
  }

  if( degodd > 2 ) return ng();

  SORT( xs ); UNIQUE( xs );
  SORT( ys ); UNIQUE( ys );

  if( SZ( xs ) >= 2 ) ans = xs[1] - xs[0];
  else if( SZ( ys ) >= 2 ) ans = ys[1] - ys[0];

  FOR( i , 1 , SZ(xs) ) ans = __gcd( ans , xs[i] - xs[0] );
  FOR( i , 1 , SZ(ys) ) ans = __gcd( ans , ys[i] - ys[0] );

  if( ans == 1 ) return ng();
  
  vl v = divisor( ans );
  SORT( v );
  FOR( i , 1 , SZ(v) ) printf( "%lld%c" , v[i] , i==SZ(v)-1?'\n':' ' );
  
  return 0;
}