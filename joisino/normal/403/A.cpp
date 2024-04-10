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

const int MAX_N = 100010;

typedef vector<vb> mb;

int t;
int n, p;

int main(){

  scanf( "%d" , &t );
  while( t-- ){
    scanf( "%d %d" , &n , &p );
    mb used( n , vb( n , false ) );
    REP( i , n ) printf( "%d %d\n%d %d\n" , i+1 , (i+1)%n+1 , (i+1) , (i+2)%n+1 );
    REP( i , n ) used[i][(i+1)%n] = used[(i+1)%n][i] = used[i][(i+2)%n] = used[(i+2)%n][i] = true;
    REP( i , n ){
      FOR( j , i+1 , n ){
	if( p == 0 ) break;
	if( !used[i][j] ){
	  printf( "%d %d\n" , i+1 , j+1 );
	  p--;
	}
      }
    }
  }
  
  return 0;
}