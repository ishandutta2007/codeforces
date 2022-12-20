#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1010;

ll a, b;

int main(){

  scanf( "%lld %lld" , &a , &b );

  FOR( i , 1 , MAX_N ){
    FOR( j , 1 , MAX_N ){
      if( i * i + j * j == a * a ){
	ld nx = ld( -j * b ) / ld( a );
	ld ny = ld( i * b ) / ld( a );
	int inx = int( (fabs(nx)+0.4) * nx / fabs(nx) );
	int iny = int( (fabs(ny)+0.4) * ny / fabs(ny) );
	if( fabs( nx - inx ) + fabs( ny - iny ) < EPS && inx != i && iny != j ){
	  printf( "YES\n" );
	  printf( "0 0\n" );
	  printf( "%d %d\n" , i , j );
	  printf( "%d %d\n" , inx , iny );
	  return 0;
	}
      }
    }
  }

  puts( "NO" );

  return 0;
}