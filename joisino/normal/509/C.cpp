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

const int MAX_N = 1024;

int n;

int b[MAX_N];

int d[MAX_N];
int ans[MAX_N][MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &b[i+1] );

  FOR( i , 1 , n+1 ){
    int res = b[i];
    for( int j = d[i-1]-1; j >= 0; j-- ){
      int add = ans[i-1][j];
      chmin( add , res );
      if( add == res ){
	int p = j+1;
	while( ans[i][p] == 9 ){
	  ans[i][p] = 0;
	  res += 9;
	  p++;
	}
	ans[i][p]++;
	res--;
	break;
      } else {
	ans[i][j] = ans[i-1][j];
	res -= add;
      }
    }
    REP( j , INF ){
      int add = 9 - ans[i][j];
      chmin( add , res );
      ans[i][j] += add;
      res -= add;
      if( res == 0 ) break;
    }
    for( int j = MAX_N-1; j >= 0; j-- ){
      if( ans[i][j] != 0 ) break;
      d[i] = j;
    }
    for( int j = d[i]-1; j >= 0; j-- ) printf( "%d" , ans[i][j] );
    printf( "\n" );
  }

  return 0;
}