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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

vl fact( ll x ){
  vl res;
  for( ll i = 2; i*i <= x; i++ ){
    while( x % i == 0 ){
      res.pb( i );
      x /= i;
    }
  }
  if( x > 1 ) res.pb( x );
  return res;
}

void append( vl &kouho, ll a ){
  vl f = fact( a );
  YYS( w , f ){
    kouho.pb( w );
  }
}

const int N = 64;

int n;
ll x, y;
ll a[1000010];

ll dp[1000010][3];

ll cost( ll s , ll t ){
  if( s % t == 0 ){
    return 0;
  } else if( ( s + 1 ) % t == 0 ){
    return y;
  } else if( ( s - 1 ) % t == 0 ){
    return y;
  }
  return INFLL;
}

int main(){

  n = in();
  x = in();
  y = in();
  REP( i , n ){
    a[i] = in();
  }

  vl kouho(0);
  append( kouho , a[0] );
  append( kouho , a[0]+1 );
  append( kouho , a[0]-1 );
  append( kouho , a[n-1] );
  append( kouho , a[n-1]+1 );
  append( kouho , a[n-1]-1 );

  SORT( kouho );
  UNIQUE( kouho );

  ll ans = INFLL;
  YYS( w , kouho ){
    REP( i , n+1 ){
      REP( j , 3 ){
        dp[i][j] = INFLL;
      }
    }
    dp[0][0] = 0;
    REP( i , n ){
      // 0 not yet
      if( dp[i][0] < INFLL ){
        chmin( dp[i+1][1] , dp[i][0] + x ); // start segment
        chmin( dp[i+1][0] ,dp[i][0] + cost( a[i] , w ) );
      }
      
      // 1 segment
      if( dp[i][1] < INFLL ){
        chmin( dp[i+1][1] , dp[i][1] + x );
        chmin( dp[i+1][2] , dp[i][1] + cost( a[i] , w ) );  // end segment
      }

      // 2 end
      if( dp[i][2] < INFLL ){
        chmin( dp[i+1][2] , dp[i][2] + cost( a[i] , w ) );
      }
    }
    chmin( ans , dp[n][0] );
    chmin( ans , dp[n][1] );
    chmin( ans , dp[n][2] );
    /*
    cout << w << endl;
    REP( i , n+1 ){
      SHOWA( dp[i] , 3 );
    }
    cout << endl;
    */
  }

  cout << ans << endl;
  
  return 0;
}