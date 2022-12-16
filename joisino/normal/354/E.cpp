#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


int t;
ll n;

ll a[64];
map<int,vi> ma;
map<pi,mi> memo;
int used[64][10];
mi ans(6,vi(64));
vi v;

int cnt = 0;

bool dfs( int d , int p ){
  if( d == 64 ) return p == 0;
  if( used[d][p] != -1 ){
    if( used[d][p] ) ans = memo[mp(d,p)];
    return used[d][p];
  }
  for( auto ite = ma.begin(); ite != ma.end(); ite++ ){
    if( (ite->fi + p)%10 == a[d] && dfs( d+1 , (ite->fi + p)/10 ) ){
      vi x = ite->se;
      REP( i , 6 ) ans[i][d] = x[i];
      memo[mp(d,p)] = ans;
      return used[d][p] = 1;
    }
  }
  return used[d][p] = 0;
}

void dfs2( int d , int p , vi va ){
  if( d == 6 ){
    ma[p] = va;
    return;
  }
  YYS( w , v ){
    vi nva = va;
    nva.pb( w );
    dfs2( d+1 , p+w , nva );
  }
}

int main(){

  v.pb( 0 ); v.pb( 4 ); v.pb( 7 );
  dfs2( 0 , 0 , vi(0) );

  scanf( "%d" , &t );
  while( t-- ){
    scanf( "%lld" , &n );
    REP( i , 64 ){
      a[i] = n%10;
      n /= 10;
    }
    REP( i , 64 ) REP( j , 10 ) used[i][j] = -1;
    memo.clear();
    if( dfs( 0 , 0 ) ){
      REP( i , 6 ){
	if( i != 0 ) printf( " " );
	ll ansv = 0;
	for( int j = 63; j >= 0; j-- ) ansv = ansv*10 + ans[i][j];
	printf( "%lld" , ansv );
      }
      printf( "\n" );
    } else {
      printf( "-1\n" );
    }
  }
  
  return 0;
}