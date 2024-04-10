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


class Factorial{
public:
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

class Factorial_inv{
public:
  vector<Mod> v;
  Factorial_inv( Factorial &f ){
    v = vector<Mod>( f.size() );
    REP( i , f.size() ) v[i] = inv( f[i] );
  }
  Mod operator [] ( int id ){
    return v[id];
  }
};

class Combination{
public:
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
  

const ll MAX_N = 512;
const ll MAX_X = 100010;

ll n;
ll a[MAX_N];

unordered_map<ll,ll> ma;

Mod ans = 1;

Factorial fact( MAX_X );
Factorial_inv ifact( fact );
Combination C( fact , ifact );

vl factor( ll x ){
  vl res(0);
  for( ll i = 2; i * i <= x; i++ ){
    while( x % i == 0 ) res.pb( i ), x /= i;
  }
  if( x > 1 ) res.pb( x );
  return res;
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ){
    vl v = factor( a[i] );
    YYS( w , v ) ma[w]++;
  }

  YYS( w , ma ) ans *= C(n-1+w.se,w.se);

  printf( "%lld\n" , (ll)ans.n );
  
  return 0;
}