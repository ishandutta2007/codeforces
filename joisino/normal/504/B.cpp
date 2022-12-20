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

struct Bit{
  vl bit;
  int size;
  void init( int n ){
    n++;
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size+1 , 0 );
  }
  void add( int k , ll x ){
    k++;
    while( k <= size ){
      bit[k] += x;
      k += k & -k;
    }
  }
  ll sum( int k ){
    k++;
    ll res = 0;
    while( k > 0 ){
      res += bit[k];
      k -= k & -k;
    }
    return res;
  }
  ll get( int k ){
    return sum(k)-sum(k-1);
  }
  ll update( int k , ll x ){
    add( k , x-get(k) );
  }
};


const int MAX_N = 200010;

int n;
int a[MAX_N], b[MAX_N];

int ri[MAX_N];

Bit sa, sb;

int cl;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) scanf( "%d" , &b[i] );

  sa.init( MAX_N );
  sb.init( MAX_N );

  sa.add( a[n-1] , 1 );
  sb.add( b[n-1] , 1 );

  for( int i = n-2; i >= 0; i-- ){
    int p = sa.sum( a[i] );
    sa.add( a[i] , 1 );
    int q = sb.sum( b[i] );
    sb.add( b[i] , 1 );
    ri[i] = ( p + q + cl ) % (n-i);
    cl = ( p + q + cl ) / (n-i);
  }

  /*
  REP( i , n ) cout << ri[i] << " ";
  cout << endl;
  */

  sa.init( MAX_N );
  REP( i , MAX_N-1 ) sa.add( i , 1 );
  
  REP( i , n ){
    int lb = -1, ub = MAX_N;
    while( ub - lb > 1 ){
      int md = ( lb + ub ) / 2;
      if( sa.sum( md ) <= ri[i] ) lb = md;
      else ub = md;
    }
    sa.add( lb+1 , -1 );
    printf( "%d%c" , lb+1 , (i==n-1?'\n':' ') );
  }
  
  return 0;
}