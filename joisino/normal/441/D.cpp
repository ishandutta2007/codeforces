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

const int MAX_N = 3010;

int n;
int p[MAX_N];
int m;
int cm;

vpi ans;

int cnt;
vi pv[MAX_N];

bool used[MAX_N];
int set_pv(){
  REP( i , n ) used[i] = false;
  REP( i , n ) pv[i].clear();
  cnt = 0;
  int res = 0;
  REP( i , n ) if( !used[i] ){
    used[i] = true;
    int it = i;
    pv[cnt].pb( it );
    while( !used[ p[it] ] ){
      it = p[it];
      used[it] = true;
      pv[cnt].pb( it );
    }
    res += (int)pv[cnt].size() - 1;
    cnt++;
  }
  return res;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &p[i] ), p[i]--;
  scanf( "%d" , &m );

  cm = set_pv();
  while( cm != m ){
    if( cm < m ){
      int res = INF;
      REP( i , cnt ){
	bool ok = true;
	int minv = INF;
	YYS( w , pv[i] ){
	  if( w == 0 ) ok = false;
	  chmin( minv , w );
	}
	if( ok ) chmin( res , minv );
      }
      ans.pb( 0 , res );
    } else {
      pi res = pi( INF , INF );
      REP( i , cnt ) if( pv[i].size() >= 2 ){
	pi minv = pi( INF , INF );
	YYS( w , pv[i] ){
	  if( w < minv.fi ){
	    minv.se = minv.fi;
	    minv.fi = w;
	  } else if( w < minv.se ){
	    minv.se = w;
	  }
	}
	if( res > minv ) res = minv;
      }
      ans.pb( res );
    }
    int x = ans.back().fi;
    int y = ans.back().se;
    // cout << x << " " << y << endl;
    swap( p[x] , p[y] );
    cm = set_pv();
  }

  printf( "%d\n" , (int)ans.size() );
  int l = ans.size();
  REP( i , l ){
    printf( "%d %d%c" , ans[i].fi+1 , ans[i].se+1 , i==l-1?'\n':' ' );
  }
  
  return 0;
}