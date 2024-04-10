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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

vi compress( vi a ){
  vi ord = a, res;
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

struct Bit{
  vi bit;
  int size;
  void init( int n ){
    n++;
    size = 1;
    while( size < n ) size *= 2;
    bit = vi( size+1 , 0 );
  }
  Bit( int n ){
    init( n );
  }
  void add( int k , int x ){
    k++;
    while( k <= size ){
      bit[k] += x;
      k += k & -k;
    }
  }
  int sum( int k ){
    k++;
    int res = 0;
    while( k > 0 ){
      res += bit[k];
      k -= k & -k;
    }
    return res;
  }
};

int n;
vi a;

const int MAX_N = 1000010;

int cnt[MAX_N];
int fl[MAX_N];

Bit bit( MAX_N );

ll ans = 0;

int main(){

  scanf( "%d" , &n );
  a.resize( n );
  REP( i , n ) scanf( "%d" , &a[i] );
  a = compress( a );

  REP( i , n ){
    cnt[ a[i] ]++;
    fl[i] = cnt[ a[i] ];
  }

  REP( i , MAX_N ) cnt[i] = 0;

  for( int i = n-1; i >= 0; i-- ){
    ans += bit.sum( fl[i] - 1 );
    cnt[ a[i] ]++;
    bit.add( cnt[ a[i] ] , 1 );
  }


  printf( "%lld\n" , ans );

  return 0;
}