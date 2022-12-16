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

struct SCC{
  int n, k;
  mi G, rG;
  vi vs, cmp;
  vb used;
  void init( int size ){
    n = size;
    G = rG = mi( n );
    cmp = vi( n );
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    rG[b].pb( a );
  }
  void dfs( int x ){
    used[x] = true;
    YYS( w , G[x] ) if( !used[w] ) dfs( w );
    vs.pb( x );
  }
  void rdfs( int x ){
    used[x] = true;
    cmp[x] = k;
    YYS( w , rG[x] ) if( !used[w] ) rdfs( w );
  }
  int scc(){
    used = vb( n , false );
    REP( i , n ) if( !used[i] ) dfs( i );
    used = vb( n , false );
    REVERSE( vs );
    k = 0;
    YYS( w , vs ) if( !used[w] ) rdfs( w ), k++;
    return k;
  }
};

const int MAX_N = 100010;

int n, m;
ll a[MAX_N];

vi G[MAX_N];

SCC scc;

ll minv[MAX_N], cnt[MAX_N];

ll sum;
Mod ans = 1;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  scc.init( n );
  scanf( "%d" , &m );
  REP( i , m ){
    int x, y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    scc.add_edge( x , y );
  }

  int k = scc.scc();

  REP( i , k ) minv[i] = INFLL;
  
  REP( i , n ){
    int b = scc.cmp[i];
    if( minv[b] > a[i] ){
      minv[b] = a[i];
      cnt[b] = 1;
    } else if( minv[b] == a[i] ){
      cnt[b]++;
    }
  }

  REP( i , k ) ans *= cnt[i];
  REP( i , k ) sum += minv[i];

  printf( "%lld %d\n" , sum , (int)ans.n );
  
  return 0;
}