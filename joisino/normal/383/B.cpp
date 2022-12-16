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


int n, m;

unordered_map<int,vi> ys;
vi xs;

vi r;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b );
    xs.pb( a );
    ys[a].pb( b );
  }
  xs.pb( n );

  SORT( xs );
  UNIQUE( xs );

  int curx = 0;
  r.pb( 1 ); r.pb( 1 );
  YYS( x , xs ){
    if( x != curx + 1 ){
      int top = r[0];
      r.clear();
      r.pb( top );
      r.pb( n );
    }
    
    ys[x].pb( 0 );
    ys[x].pb( n+1 );
    SORT( ys[x] );

    vi nr;
    REP( i , (int)ys[x].size() - 1 ){
      int t = ys[x][i] + 1;
      int b = ys[x][i+1] - 1;
      if( t > b ) continue;
      // cout << t << " " << b << endl;

      int p = lower_bound( ALL( r ) , t ) - r.begin();
      if( p == r.size() ) continue;
      if( p % 2 == 1 ){
	nr.pb( t );
	nr.pb( b );	
      } else if( b >= r[p] ){
	nr.pb( r[p] );
	nr.pb( b );
      }

    }

    if( nr.size() == 0 ) return puts( "-1" );

    /*
    cout << x << " : ";
    YYS( w , nr ) cout << w << " ";
    cout << endl;
    */
    
    r = nr;
    curx = x;
  }

  if( r.back() == n ) printf( "%d\n" , 2 * n - 2 );
  else printf( "-1\n" );

  return 0;
}