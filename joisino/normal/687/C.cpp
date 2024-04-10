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

bool dp[512][512][512];
int a[512];

int n, m;

int main(){

  n = in();
  m = in();

  REP( i , n ){
    a[i] = in();
  }
  
  REP( i , 512 ){
    REP( j , 512 ){
      REP( k , 512 ){
        dp[i][j][k] = false;
      }
    }
  }

  dp[0][0][0] = true;

  REP( i , n ){
    REP( j , m+1 ){
      REP( l , j+1 ){
        if( !dp[i][j][l] ){
          continue;
        }
        dp[i+1][j][l] = true;
        int nj = j + a[i];
        int nl = l + a[i];
        if( nj > m ){
          continue;
        }
        dp[i+1][nj][l] = true;
        dp[i+1][nj][nl] = true;
      }
    }
  }

  vi ans(0);
  REP( i , m+1 ){
    if( dp[n][m][i] ){
      ans.pb( i );
    }
  }

  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , ans[i] );
  }
  printf( "\n" );
  
  return 0;
}