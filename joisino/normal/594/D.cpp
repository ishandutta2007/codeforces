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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

  
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



const int MAX_N = 200010;
const int MAX_A = 1000010;
const int SQRT_MAX_A = 1010;

int size;
Mod bit[MAX_N*2];
void init( int n ){
  size = 1;
  while( size < n ) size *= 2;
  REP( i , size+1 ) bit[i] = 1;
}
void add( int k , Mod x ){
  for( int i = k+1; i <= size; i += i & -i ) bit[i] *= x;
}
Mod sum( int k ){
  Mod res = 1;
  for( int i = k; i > 0; i -= i & -i ) res *= bit[i];
  return res;
}


bool is_p[SQRT_MAX_A];
vi ps;

int n, m;
int a[MAX_N];

Mod prod[MAX_N], ans[MAX_N], rs[MAX_N];

vpi qs[MAX_N];

int nex[MAX_A];

Mod rt[MAX_A];

int qa[MAX_N], qb[MAX_N];

vi fact( int x ){
  vi res(0);
  YYS( w , ps ) if( x % w == 0 ){
    res.pb( w );
    while( x % w == 0 ) x /= w;
  }
  if( x != 1 ) res.pb( x );
  return res;
}

int main(){

  FOR( i , 2 , SQRT_MAX_A ) is_p[i] = true;
  FOR( i , 2 , SQRT_MAX_A ) if( is_p[i] ){
    ps.pb( i );
    for( int j = i*2; j < SQRT_MAX_A; j += i ) is_p[j] = false;
  }
  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  init( n );
  
  prod[0] = 1;
  REP( i , n ) prod[i+1] = prod[i] * a[i];

  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%d %d" , &qa[i] , &qb[i] ); qa[i]--;
    ans[i] = prod[qb[i]] / prod[qa[i]];
    qs[qa[i]].pb( qb[i] , i );
  }

  
  REP( i , MAX_A ) nex[i] = -1;
  
  for( int i = n-1; i >= 0; i-- ){
    vi fs = fact( a[i] );
    
    YYS( w , fs ) rt[w] = Mod(w-1) / Mod(w);
    
    rs[i] = 1;
    YYS( w , fs ) rs[i] *= rt[w];

    YYS( w , fs ){
      if( nex[w] != -1 ) add( nex[w] , rt[w] );
      nex[w] = i;
    }

    YYS( q , qs[i] ){
      ans[q.se] /= sum( q.fi );
    }
  }

  prod[0] = 1;
  REP( i , n ) prod[i+1] = prod[i] * rs[i];

  REP( i , m ) ans[i] *= prod[qb[i]] / prod[qa[i]];

  REP( i , m ){
    printf( "%d\n" , (int)ans[i].n );
  }
  
  return 0;
}