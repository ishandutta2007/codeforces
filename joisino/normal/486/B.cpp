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

const int MAX_N = 128;

int n, m;
int b[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int c[MAX_N][MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%d" , &b[i][j] );

  REP( i , n ) REP( j , m ) a[i][j] = 1;
  REP( i , n ) REP( j , m ) if( b[i][j] == 0 ){
    REP( k , n ) a[k][j] = 0;
    REP( k , m ) a[i][k] = 0;
  }

  REP( i , n ) REP( j , m ){
    REP( k , n ) c[i][j] |= a[k][j];
    REP( k , m ) c[i][j] |= a[i][k];
  }

  REP( i , n ) REP( j , m ) if( b[i][j] != c[i][j] ) return puts( "NO" );

  printf( "YES\n" );
  REP( i , n ) REP( j , m ) printf( "%d%c" , a[i][j] , j==m-1?'\n':' ' );
  
  return 0;
}