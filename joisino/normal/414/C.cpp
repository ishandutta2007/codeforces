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
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1<<24;

int n, m;
int a[MAX_N], b;
ll res[2][MAX_N];

void rec( int l , int r , int d ){
  if( r-l == 1 ) return;
  
  int m = (l+r)/2;
  rec( l , m , d-1 );
  rec( m , r , d-1 );
  
  FOR( i , l , m ) res[0][d] += lower_bound( a+m , a+r , a[i] ) - (a+m);
  FOR( i , l , m ) res[1][d] += (a+r) - upper_bound( a+m , a+r , a[i] );

  inplace_merge( a+l , a+m , a+r );
}

int main(){

  scanf( "%d" , &n );
  REP( i , 1<<n ) scanf( "%d" , &a[i] );

  rec( 0 , 1<<n , n-1 );
  
  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%d" , &b );
    REP( j , b ) swap( res[0][j] , res[1][j] );
    ll ans = 0;
    REP( j , n ) ans += res[0][j];
    printf( "%lld\n" , ans );
  }
  
  return 0;
}