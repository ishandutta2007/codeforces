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
//const ll MOD = 1e9+7;
ll MOD;

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


const ll MUL[3] = { 72727 , 51419 , 79393  };
const ll RHMOD[3] = { 1000000007 , 765876961 , 727272727 };

const int MAX_N = 1000010;

namespace std{
  template<>
  class hash<pi>{
  public:
    size_t operator()( const pi &x ) const {
      return hash<int>()(x.fi ^ hash<int>()(x.se));
    }
  };
}

int n, m;
ll ans;

vi G[MAX_N];

pi hs[2][MAX_N];

void calchs( int a , int x ){
  REP( i , 2 ){
    MOD = RHMOD[i];
    Mod res = 0;
    bool f = false;
    YYS( w , G[a] ){
      if( x == 1 && w > a && !f ){
	res = res * MUL[i] + a+1;
	f = true;
      }
      res = res * MUL[i] + w+1;
    }
    if( x == 1 && !f ) res = res * MUL[i] + a+1;
    
    if( i == 0 ) hs[x][a].fi = res.n;
    else if( i == 1 ) hs[x][a].se = res.n;
  }
}

int a, b;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) SORT( G[i] );
  REP( i , n ) calchs( i , 0 );
  REP( i , n ) calchs( i , 1 );

  sort( hs[0] , hs[0]+n );
  sort( hs[1] , hs[1]+n );

  REP( i , 2 ){
    int p = 0;
    while( p < n ){
      ll res = 0;
      pi x = hs[i][p];
      while( p < n && x == hs[i][p] ) p++, res++;
      ans += res * ( res - 1 ) / 2;
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}