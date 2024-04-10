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

const int MAX_N = 256;

int x, n, ip;
ld p;

int a[MAX_N];

ld dp[2][MAX_N][MAX_N];
ld dp2[2][MAX_N];

ld ans;

int main(){

  scanf( "%d %d %d" , &x , &n , &ip );
  p = (ld)ip / 100.0;
  int nx = x;

  int it = 0;
  while( x > 0 ){
    a[it++] = x % 2;
    x /= 2;
  }

  if( nx % 256 == 0 ){
    FOR( i , 8 , MAX_N ){
      if( a[i] == 1 ){
	dp2[0][i-8] = 1.0;
	break;
      }
    }
  } else {
    FOR( i , 8 , MAX_N ){
      if( a[i] == 0 ){
	dp[0][i-8][nx%256] = 1.0;
	break;
      }
    }
  }

  REP( i , n ){
    REP( j , MAX_N ) REP( k , MAX_N ) dp[(i+1)%2][j][k] = 0.0;
    REP( j , MAX_N ) dp2[(i+1)%2][j] = 0.0;
    
    REP( j , MAX_N ) REP( k , MAX_N ) if( dp[i%2][j][k] > EPSLD ){
      // +1
      int nk = k + 1;
      if( nk == 256 ){
	dp2[(i+1)%2][j] += dp[i%2][j][k] * (1.0-p);
      } else {
	dp[(i+1)%2][j][nk] += dp[i%2][j][k] * (1.0-p);
      }
      
      // *2
      if( k / 128 == 1 ){
	if( k % 128 == 0 ){
	  dp2[(i+1)%2][0] += dp[i%2][j][k] * p;
	} else {
	  dp[(i+1)%2][j+1][(k*2)%256] += dp[i%2][j][k] * p;
	}
      } else {
	dp[(i+1)%2][0][(k*2)%256] += dp[i%2][j][k] * p;
      }
    }

    REP( j , MAX_N ) if( dp2[i%2][j] > EPSLD ){
      // +1
      dp[(i+1)%2][0][1] += dp2[i%2][j] * (1.0-p);
      
      // *2
      dp2[(i+1)%2][j+1] += dp2[i%2][j] * p;
    }
  }


  REP( j , MAX_N ) REP( k , MAX_N ) if( dp[n%2][j][k] > EPSLD ){
    int nk = k;
    int res = 0;
    while( nk % 2 == 0 ){
      res++;
      nk /= 2;
    }
    ans += dp[n%2][j][k] * res;
  }

  REP( j , MAX_N ) if( dp2[n%2][j] > EPSLD ){
    ans += dp2[n%2][j] * ( 8 + j );
  }

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}