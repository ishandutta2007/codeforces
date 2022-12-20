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


struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


struct BIT{
  vector<Mod> node;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<Mod>( size , 0 );
  }
  void add( int k , Mod x ){
    for( int i = k+1; i <= size; i += i & -i ) node[i-1] += x;
  }
  void add( int a , int b , Mod x ){
    add( a , x );
    add( b , -1 * x );
  }
  Mod get( int k ){
    Mod res = 0;
    for( int i = k+1; i > 0; i -= i & -i ) res += node[i-1];
    return res;
  }
};

const int MAX_N = 300010;

int n, q;

int dep[MAX_N];
vi G[MAX_N];
int in[MAX_N], out[MAX_N];
int cnt = 0;

BIT ti, bit;

void dfs( int x , int d = 0 ){
  in[x] = cnt++;
  dep[x] = d;
  YYS( w , G[x] ) dfs( w , d+1 );
  out[x] = cnt;
}

int main(){

  scanf( "%d" , &n );
  FOR( i , 1 , n ){
    int p;
    scanf( "%d" , &p ); p--;
    G[p].pb( i );
  }

  ti.init( n );
  bit.init( n );

  dfs( 0 );
  
  scanf( "%d" , &q );
  REP( query_cnt , q ){
    int t, v, x, k;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d %d" , &v , &x , &k ); v--;
      ti.add( in[v] , out[v] , k );
      bit.add( in[v] , out[v] , x + (ll)dep[v] * (ll)k );
    } else if( t == 2 ){
      scanf( "%d" , &v ); v--;
      printf( "%d\n" , (int)( bit.get(in[v]) - ti.get(in[v]) * dep[v] ).n );
    }
  }

  return 0;
}