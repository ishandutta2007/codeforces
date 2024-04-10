#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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

int x[8], y[8];

vi v;

int check( int a , int b , int c , int d ){
  int dx1 = x[b] - x[a];
  int dy1 = y[b] - y[a];
  int dx2 = x[c] - x[a];
  int dy2 = y[c] - y[a];

  if( dx1 * dx2 + dy1 * dy2 != 0 ) return 0;
    
  if( x[c] + dx1 != x[d] ) return 0;
  if( y[c] + dy1 != y[d] ) return 0;
  if( x[b] + dx2 != x[d] ) return 0;
  if( y[b] + dy2 != y[d] ) return 0;

  if( dx1 * dx1 + dy1 * dy1 == dx2 * dx2 + dy2 * dy2 ) return 1;
  return 2;
}

int main(){

  REP( i , 8 ) scanf( "%d %d" , &x[i] , &y[i] );

  REP( i , 8 ) v.pb( i );
  
  do{
    int res1 = check( v[0] , v[1] , v[2] , v[3] );
    int res2 = check( v[4] , v[5] , v[6] , v[7] );    

    if( res1 == 1 && ( res2 == 2 || res2 == 1 ) ){
      printf( "YES\n" );
      printf( "%d %d %d %d\n" , v[0]+1 , v[1]+1 , v[2]+1 , v[3]+1 );
      printf( "%d %d %d %d\n" , v[4]+1 , v[5]+1 , v[6]+1 , v[7]+1 );
      return 0;
    }
    
  } while( next_permutation( ALL(v) ) );

  printf( "NO\n" );
  
  return 0;
}