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
#define SHOW(x) cout << #x << " = " << x << endl
 
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
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
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
Mod operator - ( Mod a ){ return Mod( MOD - a.n ); }
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
ll extgcd( ll a , ll b , ll &x , ll &y ){
  ll d = a;
  if( b != 0 ){
    d = extgcd( b , a % b , y , x );
    y -= a / b * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}
Mod inv( Mod a ){ ll x, y; assert( extgcd( a.n , MOD , x , y ) == 1 ); return Mod( x ); }
// Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }

typedef vector<Mod> vm;


struct Factorial{
  vector<Mod> v;
  Factorial( int max_n ){
    v = vector<Mod>( max_n , 1 );
    FOR( i , 1 , max_n ) v[i] = v[i-1] * i;
  }
  int size(){
    return v.size();
  }
  Mod operator [] ( int id ){
    return v[id];
  }
};

struct Factorial_inv{
  vector<Mod> v;
  Factorial_inv( Factorial &f ){
    v = vector<Mod>( f.size() );
    REP( i , f.size() ) v[i] = inv( f[i] );
  }
  Mod operator [] ( int id ){
    return v[id];
  }
};

struct Combination{
  Factorial *f;
  Factorial_inv *finv;
  Combination( Factorial &arg_f , Factorial_inv &arg_finv ){
    f = &arg_f;
    finv = &arg_finv;
  }
  Mod operator () ( int a , int b ){
    return (*f)[a] * (*finv)[b] * (*finv)[a-b];
  }
};


Factorial fact(1000010);
Factorial_inv finv( fact );
Combination comb( fact , finv );

typedef pair<pi,int> st;

char cs[1000010];
string stin(){ scanf( "%s" , cs ); return cs; }

int m;
string s;

Mod pw[100010];

Mod dp[100010];

vector<st> vs;
vpi ans;

int calc( int l ){
  REP( i , l ){
    dp[i] = 0;
  }
  dp[l] = 1;
  FOR( i , l , 100009 ){
    dp[i+1] = dp[i] * 26 + comb( i , l-1 ) * pw[i+1-l];
  }
}

int main(){

  pw[0] = 1;
  REP( i , 100009 ){
    pw[i+1] = pw[i] * 25;
  }
  
  m = in();
  s = stin();

  REP( cm , m ){
    int t = in();
    if( t == 1 ){
      s = stin();
    } else {
      int n = in();
      vs.pb( pi( SZ(s) , n ) , cm );
    }
  }

  SORT( vs );

  int prv = -1;
  YYS( w , vs ){
    int l = w.fi.fi;
    int n = w.fi.se;
    int id = w.se;
    
    if( l != prv ){
      calc( l );
      prv = l;
    }

    ans.pb( id , dp[n].n );
  }

  SORT( ans );
  YYS( w , ans ){
    printf( "%d\n" , w.se );
  }
  
  return 0;
}