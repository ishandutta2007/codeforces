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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

struct BIT{
  vi node;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vi( size , 0 );
  }
  void add( int k , int x ){
    for( int i = k+1; i <= size; i += i & -i ) node[i-1] += x;
  }
  int sum( int k ){
    int res = 0;
    for( int i = k; i > 0; i -= i & -i ) res += node[i-1];
    return res;
  }
};

const int MAX_N = 100010;

int n, m;
int a[MAX_N];

BIT bit;

bool is_lucky[MAX_N];

char s[MAX_N];

void dfs( int x ){
  if( x > 10000 ) return;
  is_lucky[x] = true;
  dfs( x * 10 + 4 );
  dfs( x * 10 + 7 );
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &a[i] );

  dfs( 4 ); dfs( 7 );

  bit.init( n );
  REP( i , n ) if( is_lucky[ a[i] ] ) bit.add( i , 1 );
  
  REP( i , m ){
    int l, r, x;
    scanf( "%s" , s );
    if( s[0] == 'c' ){
      scanf( "%d %d" , &l , &r ); l--;
      printf( "%d\n" , bit.sum(r) - bit.sum(l) );
    } else {
      scanf( "%d %d %d" , &l , &r , &x ); l--;
      for( int i = l; i < r; i++ ){
	if( is_lucky[ a[i] ] ) bit.add( i , -1 );
	a[i] += x;
	if( is_lucky[ a[i] ] ) bit.add( i , 1 );
      }
    }
  }
  
  return 0;
}