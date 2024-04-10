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
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

int n, m;
int a[MAX_N][MAX_N];

int r[MAX_N], c[MAX_N];

int rf[MAX_N], cf[MAX_N];

vi ansr, ansc;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%d" , &a[i][j] );

  REP( i , n ) REP( j , m ) r[i] += a[i][j], c[j] += a[i][j];

  while( 1 ){
    int row_or_col = -1;
    int ind = -1;
    int val = 0;
    
    REP( i , n ) if( r[i] < val ) row_or_col = 0, ind = i, val = r[i];
    REP( j , m ) if( c[j] < val ) row_or_col = 1, ind = j, val = c[j];
    
    if( val == 0 ) break;

    if( row_or_col == 0 ){
      rf[ind] ^= 1;
      REP( j , m ){
	int del = -( a[ind][j] + a[ind][j] );
	r[ind] += del;
	c[j] += del;
	a[ind][j] += del;
      }
    } else if( row_or_col == 1 ){
      cf[ind] ^= 1;
      REP( i , n ){
	int del = -( a[i][ind] + a[i][ind] );
	c[ind] += del;
	r[i] += del;
	a[i][ind] += del;
      }
    }
  }

  REP( i , n ) if( rf[i] == 1 ) ansr.pb( i );
  REP( j , m ) if( cf[j] == 1 ) ansc.pb( j );

  printf( "%lld" , SZ(ansr) );
  YYS( w , ansr ) printf( " %d" , w+1 );
  printf( "\n" );

  printf( "%lld" , SZ(ansc) );
  YYS( w , ansc ) printf( " %d" , w+1 );
  printf( "\n" );

  
  return 0;
}