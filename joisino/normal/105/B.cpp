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

const int MAX_N = 72;

int n, k, a;
int b[MAX_N], l[MAX_N];

int nb[MAX_N];

double ans = 0;

void dfs( int p , int rest ){
  if( p == n ){
    double res = 0.0;
    REP( mask , PW(n) ){
      double prob = 1.0;
      int sum = 0;
      REP( i , n ){
	if( mask & PW(i) ){
	  prob *= (double)nb[i] / 100.0;
	} else{
	  prob *= (double)( 100 - nb[i] ) / 100.0;
	  sum += l[i];
	}
      }
      int approve = __builtin_popcount( mask );
      if( approve * 2 > n ) res += prob;
      else res += prob * ( (double)a / double( a + sum ) );
    }
    chmax( ans , res );
    return;
  }
  
  REP( i , rest+1 ){
    nb[p] = min( b[p] + i * 10 , 100 );
    dfs( p+1 , rest - i );
  }
}

int main(){

  scanf( "%d %d %d" , &n , &k , &a );
  REP( i , n ) scanf( "%d %d" , &l[i] , &b[i] );

  dfs( 0 , k );

  printf( "%.18lf\n" , ans );
  
  return 0;
}