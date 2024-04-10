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

const ll MAX_N = 72;

ll memo[MAX_N][MAX_N];
ll n, t;

ll solve( ll x , ll a ){
  if( x == 1 ){
    if( a == 0 ) return 1;
    else return 0;
  }
  if( memo[x][a] != -1 ) return memo[x][a];
  ll res = solve( x - 1 , a ) + solve( x - 1 , a - 1 );
  return memo[x][a] = res;
}

ll solve2( ll x , ll r , ll a ){
  if( x == 1 ){
    if( r == 1 && a == 0 ) return 1;
    else return 0;
  }
  if( r < PW(x-1) ) return solve2( x-1 , r , a );
  else return solve2( x-1 , r-PW(x-1) , a-1 ) + solve( x , a );
}

int main(){

  REP( i , MAX_N ) REP( j , MAX_N ) memo[i][j] = -1;

  scanf( "%lld %lld" , &n , &t );
  n += 2;
  
  ll a = 0;
  while( PW(a) < t ) a++;
  if( PW(a) != t ){
    printf( "0\n" );
    return 0;
  }

  ll x = 0;
  while( PW(x+1) <= n ) x++;

  ll ans = solve2( x , n - PW(x) , a );
  FOR( i , 1 , x+1 ) ans += solve( i , a );

  if( a == 0 ) ans--;

  printf( "%lld\n" , ans );
  
  return 0;
}