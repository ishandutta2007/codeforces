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

struct Bitran{
  Bit bita , bitb;
  void init( int n ){
    bita.init( n );
    bitb.init( n );
  }
  void addran( int a , int b , ll x ){
    bita.add( a , x );
    bita.add( b , -x );
    bitb.add( a , -(a-1)*x );
    bitb.add( b , (b-1)*x );
  }
  void add( int a , ll x ){
    bitb.add( a , x );
  }
  ll sum( int k ){
    return k*bita.sum(k) + bitb.sum(k);
  }
  ll get( int k ){
    return sum(k)-sum(k-1);
  }
};

const int MAX_N = 200010;

Bitran bit[2];
int cnt[2];
int in[MAX_N], out[MAX_N], in2[MAX_N], out2[MAX_N], dep[MAX_N];
int a[MAX_N];
int n, m;
int b, c, t, x, val;
vi G[MAX_N];

void dfs( int x , int p , int d ){
  bit[d].add( cnt[d] , a[x] );
  dep[x] = d;
  in[x] = cnt[d]++; in2[x] = cnt[1-d];
  YYS( w , G[x] ) if( w != p ) dfs( w , x ,1-d );
  out[x] = cnt[d]; out2[x] = cnt[1-d];
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , 2 ) bit[i].init( n );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n-1 ){
    scanf( "%d %d" , &b , &c ); b--; c--;
    G[b].pb( c );
    G[c].pb( b );
  }
  dfs( 0 , -1 , 0 );
  REP( i , m ){
    scanf( "%d %d" , &t , &x ); x--;
    if( t == 1 ){
      scanf( "%d" , &val );
      bit[ dep[x] ].addran( in[x] , out[x] , val );
      bit[ 1 - dep[x] ].addran( in2[x] , out2[x] , -val );      
    } else if( t == 2 ){
      printf( "%lld\n" , bit[ dep[x] ].get( in[x] ) );
    }
  }
  
  return 0;
}