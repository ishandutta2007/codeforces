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

const ll MAX_N = 1024;

char s[72];
ll m;

ll dp[MAX_N][12][12];
vl ans;

int main(){

  scanf( "%s" , s );
  scanf( "%lld" , &m );

  REP( i , MAX_N ) REP( j , 12 ) REP( k , 12 ) dp[i][j][k] = -1;
  dp[0][0][0] = 0;

  REP( i , m ) REP( j , 12 ) REP( k , 12 ) if( dp[i][j][k] != -1 ){
    FOR( l , 1 , 11 ) if( l != j && l > k && s[l-1] == '1' ) dp[i+1][l][l-k] = j;
  }

  ll a = -1, b = -1;
  REP( j , 12 ) REP( k , 12 ) if( dp[m][j][k] != -1 ) a = j, b = k;

  if( a == -1 ){
    printf( "NO\n" );
    return 0;
  }

  ll c = m;
  while( a != 0 ){
    ans.pb( a );
    ll na = dp[c][a][b];
    ll nb = a - b;
    a = na, b = nb;
    c--;
  }

  REVERSE( ans );
  printf( "YES\n" );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i] , i == SZ(ans)-1 ? '\n' : ' ' );
  
  return 0;
}