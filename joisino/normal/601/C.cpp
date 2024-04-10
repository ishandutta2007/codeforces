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

int n, m;

int a[110];
int sum;

ld dp[110][100010];
ld s[100010];

int main(){

  n = in();
  m = in();

  REP( i , n ){
    a[i] = in() - 1;
    sum += a[i];
  }

  if( m == 1 ){
    puts( "1.0" );
    return 0;
  }

  dp[0][0] = 1.0;
  
  REP( i , n ){
    s[0] = 0.0;
    REP( j , ( i + 1 ) * ( m - 1 ) + 1 ){
      s[j+1] = s[j] + dp[i][j];
    }
    REP( j , ( i + 1 ) * ( m - 1 ) + 1 ){
      dp[i+1][j] = s[j+1];
      if( j+1-m >= 0 ){
        dp[i+1][j] -= s[j+1-m];
      }
      if( j-a[i] >= 0 ){
        dp[i+1][j] -= dp[i][j-a[i]];
      }
      dp[i+1][j] /= ( m - 1 );
    }
  }

  double ans = 0;
  REP( i , sum ){
    ans += dp[n][i];
  }

  ans *= ( m - 1 );
  ans += 1.0;

  printf( "%.18lf\n" , ans );
  
  return 0;
}