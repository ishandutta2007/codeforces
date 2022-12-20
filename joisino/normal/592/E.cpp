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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ld PI = atan2l( 0 , -1 );

const int MAX_N = 1200010;

int n;
int c, d;
int r[MAX_N], w[MAX_N];
ld a[MAX_N];
int b[MAX_N];

ll add, ans, ans2;

int main(){

  scanf( "%d %d %d" , &n , &c , &d );
  REP( i , n ){
    scanf( "%d %d" , &r[i] , &w[i] );
    a[i] = atan2l( w[i] - d , r[i] - c );
  }
  sort( a , a+n );

  REP( i , 2*n ) a[i+n] = a[i] + 2 * PI;
  REP( i , 2*n ) b[i] = lower_bound( a , a+3*n , a[i] + PI - EPSLD ) - a;

  int p = 1;
  REP( i , n ){
    int np = b[i];
    if( i != 0 ) add -= ll( np - p ) * ll( p - i );
    FOR( j , p , np ) add += b[j] - np;
    p = np;
    ans += add;
  }

  REP( i , n ){
    ans -= ll( lower_bound( a , a+3*n , a[i] + PI + EPSLD ) - lower_bound( a , a+3*n , a[i] + PI - EPSLD ) ) * ll( lower_bound( a , a+3*n , a[i] + PI - EPSLD ) - lower_bound( a , a+3*n , a[i] + EPSLD ) );
  }
  
  printf( "%lld\n" , ans / 3 );
  
  return 0;
}