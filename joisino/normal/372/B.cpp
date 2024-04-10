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

const int MAX_N = 60;

int n, m, q;

char s[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
vi v[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
int c[MAX_N][MAX_N];
int ans[MAX_N][MAX_N][MAX_N][MAX_N];

void inc( int y , int x  , int k ){
  REP( i , v[y][x].size() ){
    b[y+i][x] -= k;
    b[y+i][x+v[y][x][i]] += k;
  }
}

int main(){

  scanf( "%d %d %d" , &n , &m , &q );
  REP( i , n ) scanf( "%s" , s[i] );
  
  REP( i , n ) for( int j = m-1; j >= 0; j-- ) if( s[i][j] == '0' ) a[i][j] = a[i][j+1]+1;

  REP( i , n ) REP( j , m ){
    int x = a[i][j];
    for( int k = 0; i+k < n; k++ ){
      chmin( x , a[i+k][j] );
      v[i][j].pb( x );
    }
  }

  REP( i , n ) REP( j , m ) inc( i , j , 1 );
  
  REP( i , n ){
    REP( k , n ) REP( l , m+1 ) c[k][l] = b[k][l];
    
    REP( j , m ){
      REP( k , n ) REP( l , m+1 ) ans[i][j][k][l] = b[k][l];
      REP( k , n ) for( int l = m; l >= 0; l-- ) ans[i][j][k][l] += ans[i][j][k][l+1];
      REP( k , n ) REP( l , m+1 ) ans[i][j][k][l] = ans[i][j][k][l+1];
      REP( k , n ) REP( l , m ) ans[i][j][k][l+1] += ans[i][j][k][l];
      REP( k , n ) REP( l , m ) ans[i][j][k+1][l] += ans[i][j][k][l];
      FOR( k , i , n ) inc( k , j , -1 );
    }
    REP( i , n ) REP( j , m+1 ) b[i][j] = c[i][j];
    REP( j , m ) inc( i , j , -1 );
  }

  REP( i , q ){
    int x1, x2, y1, y2;
    scanf( "%d %d %d %d" , &x1 , &y1 , &x2 , &y2 ); x1--; y1--; x2--; y2--;
    printf( "%d\n" , ans[x1][y1][x2][y2] );
  }
  
  return 0;
}