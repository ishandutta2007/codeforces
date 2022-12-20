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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head


struct Mod{
  unsigned n;
  Mod() : n(0){}
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
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


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
    return v.at(id);
  }
};

struct Factorial_inv{
  vector<Mod> v;
  Factorial_inv( Factorial &f ){
    v = vector<Mod>( f.size() );
    REP( i , f.size() ) v[i] = inv( f[i] );
  }
  Mod operator [] ( int id ){
    return v.at(id);
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

Factorial fact( 1000010 );
Factorial_inv finv( fact );
Combination comb( fact , finv );

int n, m;

vi v, sz;

int main(){

  n = in();
  m = in();

  REP( i , m ){
    v.pb( in() - 1 );
  }
  SORT( v );

  int cur = -1;
  YYS( w , v ){
    sz.pb( w - cur - 1 );
    cur = w;
  }
  sz.pb( n - cur - 1 );

  int all = 0;
  YYS( w , sz ){
    all += w;
  }

  Mod ans = fact[all];
  YYS( w , sz ){
    ans /= fact[w];
  }

  FOR( i , 1 , SZ(sz)-1 ){
    if( sz[i] != 0 ){
      Mod res = 0;
      REP( j , sz[i] ){
        res += fact[sz[i]-1] / ( fact[j] * fact[sz[i]-j-1] );
      }
      ans *= res;
    }
  }

  printf( "%d\n" , ans.n );
    
  return 0;
}