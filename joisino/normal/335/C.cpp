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

bool f[128][2];
int memo[128][128][3][3];

bool isin( int a , int b ){
  return 0 <= a and a < n and 0 <= b and b < 2;
}

vpi cg;
void draw( int a , int b ){
  if( isin( a , b ) and !f[a][b] ){
    cg.pb( a , b );
    f[a][b] = true;
  }
}

void put( int a , int b ){
  cg.clear();
  draw( a , b );
  draw( a-1 , 1-b );
  draw( a , 1-b );
  draw( a+1 , 1-b );
}

int mex( set<int> &x ){
  REP( i , INF ) if( x.find( i ) == x.end() ) return i;
}

int grandy( int t , int b , int tf , int bf ){
  int &res = memo[t][b][tf][bf];
  if( res != -1 ) return res;

  set<int> gs;
  FOR( i , t , b ) REP( j , 2 ) if( !f[i][j] ){
    put( i , j );
    vpi ccg = cg;
    int x = grandy( t , i , tf , j ) ^ grandy( i+1 , b , j , bf );
    gs.insert( x );
    YYS( w , ccg ) f[w.fi][w.se] = false;
  }

  // cout << t << " " << b << " " << tf << " " << bf << " " << mex( gs ) << endl;
  
  return res = mex( gs );
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    put( a , b );
  }
  
  REP( i , 128 ) REP( j , 128 ) REP( k , 3 ) REP( l , 3 ) memo[i][j][k][l] = -1;

  if( grandy( 0 , n , 2 , 2 ) == 0 ) puts( "LOSE" );
  else puts( "WIN" );

  return 0;
}