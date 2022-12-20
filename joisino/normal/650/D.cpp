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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

int n, m;

int a[400010];
int dp[400010];

int lis;
int len[400010];

bool used[400010];

map<int,vi> ma;
bool uni[400010];

vpi q[400010];

int qs[400010];

int p[400010], b[400010];

int mx[400010];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , m ){
    scanf( "%d %d" , &p[i] , &b[i] ); p[i]--;
    q[ p[i] ].pb( b[i] , i );
  }
  
  REP( i , 400010 ) dp[i] = INF;
  REP( i , n ){
    int *ite = lower_bound( dp , dp+400010 , a[i] );
    *ite = a[i];
    len[i] = ite - dp + 1;
    chmax( lis , len[i] );
  }
  
  for( int i = n-1; i >= 0; i-- ){
    if( len[i] == lis || mx[len[i]+1] > a[i] ){
      used[i] = true;
      ma[ len[i] ].pb( i );
      chmax( mx[len[i]] , a[i] );
    }
  }

  YYS( w , ma ) if( SZ(w.se) == 1 ) uni[ w.se[0] ] = true;

  REP( i , 400010 ) dp[i] = INF;
  REP( i , n ){
    YYS( w , q[i] ){
      qs[ w.se ] += lower_bound( dp , dp+400010 , w.fi ) - dp;
    }
    *lower_bound( dp , dp+400010 , a[i] ) = a[i];
  }

  REP( i , 400010 ) dp[i] = INF;
  for( int i = n-1; i >= 0; i-- ){
    YYS( w , q[i] ){
      qs[ w.se ] += lower_bound( dp , dp+400010 , -w.fi ) - dp;
    }
    *lower_bound( dp , dp+400010 , -a[i] ) = -a[i];
  }

  REP( i , m ){
    int ans = lis-1;
    if( !uni[ p[i] ] || !used[ p[i] ] ) ans = lis;
    chmax( ans , qs[i] + 1 );
    printf( "%d\n" , ans );
  }
  
  return 0;
}