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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 310;

int n, m, target;
int tf, tu, td;

int a[MAX_N][MAX_N];
int rsum[MAX_N][MAX_N], lsum[MAX_N][MAX_N];

int ans = INF;
int ansl, ansr, ansu, ansd;

set<pi> ss;

int bars[MAX_N];

int cost( int fr , int to ){
  if( fr == to ) return tf;
  if( fr < to ) return tu;
  if( fr > to ) return td;
}

void upd( int l , int r , int u , int d , int res ){
  if( r-l < 2 || d-u < 2 ) return;
  if( ans > res ){
    ans = res;
    ansl = l;
    ansr = r;
    ansu = u;
    ansd = d;
  }
}

int score( int a , int b ){
  return abs( a - b - target );
}

int main(){

  scanf( "%d %d %d" , &n , &m , &target );
  scanf( "%d %d %d" , &tf , &tu , &td );
  REP( i , n ) REP( j , m ) scanf( "%d" , &a[i][j] );

  REP( i , n ) FOR( j , 1 , m ) rsum[i][j] = rsum[i][j-1] + cost( a[i][j-1] , a[i][j] );
  REP( i , n ) FOR( j , 1 , m ) lsum[i][j] = lsum[i][j-1] + cost( a[i][j] , a[i][j-1] );
  
  REP( i , m ) FOR( j , i+2 , m ){
    int tate_bar = 0;
    ss.clear();
    REP( s , n ){
      bars[s] = tate_bar;
      if( s >= 2 ){
	ss.emplace( bars[s-2] - ( rsum[s-2][j] - rsum[s-2][i] ) , s-2 );

	int bp = tate_bar + lsum[s][j] - lsum[s][i];
	auto ite = ss.lower_bound( pi( bp - target , -1 ) );
	if( ite != ss.end() ){
	  upd( i , j , (*ite).se , s , score( bp , (*ite).fi ) );
	}
	if( ite != ss.begin() ){
	  ite--;
	  upd( i , j , (*ite).se , s , score( bp , (*ite).fi ) );
	}
      }
      tate_bar += cost( a[s+1][i] , a[s][i] ) + cost( a[s][j] , a[s+1][j] );
    }
  }

  printf( "%d %d %d %d\n" , ansu+1 , ansl+1, ansd+1 , ansr+1 );
  
  return 0;
}