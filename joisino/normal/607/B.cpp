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

int n;
int a[512];

int dp[512][512][2];
bool used[512][512][2];

int rec( int l , int r , int t ){
  if( l == r ){
    return 0;
  }
  if( r - l == 1 ){
    if( t == 0 ){
      return 1;
    } else if( t == 1 ){
      return 0;
    }
  }
  if( used[l][r][t] ){
    return dp[l][r][t];
  }
  used[l][r][t] = true;
  int res = INF;
  FOR( p , l+1 , r ){
    chmin( res , rec( l , p , t ) + rec( p , r , 0 ) );
    chmin( res , rec( l , p , 0 ) + rec( p , r , t ) );
  }
  if( a[l] == a[r-1] ){
    if( t == 0 ){
      chmin( res , rec( l+1, r-1, 1 ) + 1 );
    } else {
      chmin( res , rec( l+1, r-1, 1 ) );
    }
  }
  return dp[l][r][t] = res;
}

int main(){

  n = in();
  REP( i , n ){
    a[i] = in();
  }

  printf( "%d\n" , rec( 0 , n , 0 ) );

  return 0;
}