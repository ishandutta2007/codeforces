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

int dp[60010][310];

void go( vi v ){
  int m = SZ(v);
  assert( SZ(v) == m );
  assert( SZ(v) < 60010 );
  REP( i , 60010 ){
    REP( j , 310 ){
      dp[i][j] = 0;
    }
  }
  REP( i , m ){
    REP( j , 310 ){
      if( v[i] >= j ){
        chmax( dp[i+1][ v[i] ] , dp[i][j] + 1 );
      }
      chmax( dp[i+1][j] , dp[i][j] );
    }
  }
}

void back( vi v ){
  int m = SZ(v);
  assert( SZ(v) == m );
  assert( SZ(v) < 60010 );
  REP( i , 60010 ){
    REP( j , 310 ){
      dp[i][j] = 0;
    }
  }
  REP( i , m ){
    REP( j , 310 ){
      if( v[i] <= j ){
        chmax( dp[i+1][ v[i] ] , dp[i][j] + 1 );
      }
      chmax( dp[i+1][j] , dp[i][j] );
    }
  }
}

int n, t;

int a[128];

int cnt[310];

int med[310];

int main(){

  n = in();
  t = in();
  REP( i , n ){
    a[i] = in();
    cnt[ a[i] ]++;
  }
  
  if( t <= 600 ){
    vi v(0);
    REP( i , t ){
      REP( j , n ){
        v.pb( a[j] );
      }
    }
    go( v );
    int ans = 0;
    REP( j , 310 ){
      chmax( ans , dp[SZ(v)][j] );
    }
    printf( "%d\n" , ans );
    return 0;
  }

  vi v(0);
  REP( i , 300 ){
    REP( j , n ){
      v.pb( a[j] );
    }
  }
  go( v );
  t -= 600;
  int cur = 0;
  REP( j , 310 ){
    chmax( cur , dp[SZ(v)][j] );
    med[j] = cur + cnt[j] * t;
  }
  v.clear();
  REP( i , 300 ){
    for( int j = n-1; j >= 0; j-- ){
      v.pb( a[j] );
    }
  }
  back( v );
  int ans = 0;
  cur = 0;
  for( int j = 309; j >= 0; j-- ){
    chmax( cur , dp[SZ(v)][j] );
    chmax( ans , med[j] + cur );
  }

  printf( "%d\n" , ans );

  return 0;
}