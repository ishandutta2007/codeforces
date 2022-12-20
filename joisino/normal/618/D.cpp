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

vi G[200010];

int n;
ll x, y;

int dp[200010][2];

void dfs( int x , int p ){
  // cout << x << " " << p << endl;
  vi ch(0);
  YYS( w , G[x] ){
    if( w == p ){
      continue;
    }
    dfs( w , x );
    ch.pb( w );
  }
  if( SZ(ch) == 0 ){
    dp[x][0] = 0;
    dp[x][1] = 1;
    return;
  }
  mi cd(SZ(ch)+1,vi(3,-INF));
  cd[0][0] = 0;
  REP( i , SZ(ch) ){
    int c = ch[i];
    REP( j , 3 ){
      REP( k , 2 ){
        int nj = j + k;
        if( nj >= 3 ){
          continue;
        }
        chmax( cd[i+1][nj], cd[i][j] + dp[c][k] );
      }
    }
  }
  dp[x][0] = max( { cd[SZ(ch)][0] , cd[SZ(ch)][1], cd[SZ(ch)][2] } );
  dp[x][1] = max( cd[SZ(ch)][0] , cd[SZ(ch)][1] ) + 1;
}

int main(){

  n = in();
  x = in();
  y = in();

  REP( i , n-1 ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }
  
  if( x > y ){
    bool f = false;
    REP( i , n ){
      if( SZ(G[i]) == n - 1 ){
        f = true;
        break;
      }
    }
    if( f ){ // uni
      printf( "%lld\n" , y * ( n - 2 ) + x );
    } else {
      printf( "%lld\n" , y * ( n - 1 ) );
    }
    return 0;
  }
  
  dfs( 0 , -1 );

  ll ux = max( dp[0][0], dp[0][1] - 1 );
  ll uy = n-1-ux;
  ll ans = ux * x + uy * y;
  printf( "%lld\n" , ans );

  return 0;
}