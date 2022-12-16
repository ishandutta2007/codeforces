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

const ll MAX_N = 200010;

ll n;
ll a[MAX_N];

bool dp[MAX_N][5];
pl pr[MAX_N][5];

int main(){

  scanf( "%lld" , &n ); n++;
  FOR( i , 1 , n ) scanf( "%lld" , &a[i] );
  FOR( i , 1 , n ) if( a[i] == 0 ) a[i] = -1;

  dp[0][4] = true;
  ll p = 0;
  FOR( i , 1 , n ){
    if( a[i] == -1 ) continue;
    
    if( a[p] == a[i] ){
      REP( j , 5 ) if( j-(i-p) >= 0 && dp[p][j-(i-p)] ) dp[i][j] = true, pr[i][j] = pl( p , j-(i-p) );
    } else if( a[p] > a[i] ){
      printf( "-1\n" );
      return 0;
    } else {
      REP( j , 5 ) REP( k , 5 ) if( dp[p][k] ){
	ll hatena = i-p-1;
	hatena -= j;
	ll aida = a[i]-a[p]-1;
	ll minv = aida * 2 + ( k == 0 ? 1 : 0 );
	ll maxv = aida * 5 + ( 4 - k );
	if( minv <= hatena && hatena <= maxv ) dp[i][j] = true, pr[i][j] = pl( p , k );
      }
    }
    p = i;
  }


  ll q = -1;
  REP( i , p==n-2?4:5 ) if( dp[p][i] ) q = i;
  if( q == -1 || ( q == 0 && p == n-1 ) ){
    printf( "-1\n" );
    return 0;
  }
  
  ll fp = p, fq = q;

  while( p != 0 ){
    ll np = pr[p][q].fi;
    ll nq = pr[p][q].se;
    REP( i , q ) a[p-1-i] = a[p];
    ll end = p - q;
    ll ite = np+1;
    ll curn = a[np];
    ll cnt = nq+1;
    while( ite < end ){
      while( cnt < 5 && (end-ite) > (a[p]-curn-1)*2 ) a[ite] = curn, ite++, cnt++;
      curn++;
      cnt = 0;
    }
    p = np;
    q = nq;
  }

  if( q == 0 ) a[fp+1] = a[fp], fp++;
  FOR( i , fp+1 , n ) a[i] = (i>=2?a[i-2]:0)+1;
  if( a[n-1] != a[n-2] ) a[n-1] = a[n-2];

  printf( "%lld\n" , a[n-1] );
  FOR( i , 1 , n ) printf( "%lld%c" , a[i] , i==n-1?'\n':' ' );
  
  return 0;
}