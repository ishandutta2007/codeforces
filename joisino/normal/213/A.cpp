#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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

const int MAX_N = 210;

int n;
vi G[MAX_N];
int c[MAX_N];

bool done[MAX_N];

int main(){
  
  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &c[i] );
  REP( i , n ) c[i]--;
  REP( i , n ){
    int k, a;
    scanf( "%d" , &k );
    REP( j , k ){
      scanf( "%d" , &a ); a--;
      G[i].pb( a );
    }
  }

  int ans = INF;
  REP( start , 3 ){
    int p = start;
    int t = 0;
    int cnt = 0;
    REP( i , n ) done[i] = false;
    while( 1 ){
      REP( i , n ) if( !done[i] && c[i] == p ){
	bool ok = true;
	YYS( w , G[i] ) if( !done[w] ) ok = false;
	if( ok ){
	  done[i] = true;
	  t++;
	  cnt++;
	  i = -1;
	}
      }
      if( cnt == n ) break;
      t++;
      p = ( p + 1 ) % 3;
    }
    chmin( ans , t );
  }

  printf( "%d\n" , ans );

  
  return 0;
}