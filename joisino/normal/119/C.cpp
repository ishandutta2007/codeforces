#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

typedef pair<pl,pl> plpl;

ll n, m, par;

ll dp[MAX_N][MAX_N][MAX_N];
pl pr[MAX_N][MAX_N][MAX_N];
plpl subject[MAX_N];

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &par );
  REP( i , m ) scanf( "%lld %lld %lld" , &subject[i].se.fi , &subject[i].se.se , &subject[i].fi.fi );
  REP( i , m ) subject[i].fi.se = i+1;
  sort( subject , subject+m );

  REP( i , MAX_N ) REP( j , MAX_N ) REP( k , MAX_N ) dp[i][j][k] = -INFLL;
  REP( i , m ) REP( j , subject[i].se.se - subject[i].se.fi + 1 ){
    dp[1][i][j] = subject[i].se.fi + j;
    pr[1][i][j] = pl( -1 , -1 );
  }

  FOR( i , 1 , n ) REP( j , m ) REP( k , MAX_N ) FOR( l , j+1 , m ){
    ll cur_task = subject[j].se.fi + k;
    if( subject[l].fi.fi > subject[j].fi.fi ){
      ll next_task = cur_task + par;
      if( subject[l].se.fi <= next_task && next_task <= subject[l].se.se ){
	if( dp[i+1][l][ next_task - subject[l].se.fi ] < dp[i][j][k] + next_task ){
	  dp[i+1][l][ next_task - subject[l].se.fi ] = dp[i][j][k] + next_task;
	  pr[i+1][l][ next_task - subject[l].se.fi ] = pl( j , k );
	}
      }

      next_task = cur_task * par;
      if( subject[l].se.fi <= next_task && next_task <= subject[l].se.se ){
	if( dp[i+1][l][ next_task - subject[l].se.fi ] < dp[i][j][k] + next_task ){
	  dp[i+1][l][ next_task - subject[l].se.fi ] = dp[i][j][k] + next_task;
	  pr[i+1][l][ next_task - subject[l].se.fi ] = pl( j , k );
	}
      }
    }
  }

  ll res = -1;
  pl p = pl( -1 , -1 );
  REP( j , m ) REP( k , MAX_N ) if( res < dp[n][j][k] ){
    res = dp[n][j][k];
    p = pl( j , k );
  }

  if( res < 0 ) return puts( "NO" );

  vpl ans(0);
  while( p != pl( -1 , -1 ) ){
    ans.pb( subject[ p.fi ].fi.se , subject[ p.fi ].se.fi + p.se );
    p = pr[ n-- ][ p.fi ][ p.se ];
  }
  REVERSE( ans );
  
  printf( "YES\n" );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi , w.se );
  
  return 0;
}