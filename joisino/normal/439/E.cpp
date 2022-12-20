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

class Factorial : public vector<Mod> {
public:
  Factorial( int max_n ){
    resize( max_n );
    at(0) = 1;
    FOR( i , 1 , max_n ) at(i) = at(i-1) * i;
  }
};

class Mobius : public vi{
public:
  Mobius( int max_n ){
    resize( max_n );
    vb isp( max_n , true );
    REP( i , max_n ) at(i) = 1;
    for( ll i = 2; i < max_n; i++ ){
      if( isp[i] ){
	at(i) *= -1;
	for( ll j = i*2; j < max_n; j += i ){
	  if( j % (i*i) == 0 ) at(j) = 0;
	  else at(j) *= -1;
	  isp[j] = false;
	}
      }
    }
  }
};

vl factor( ll x ){
  vl res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}

const int MAX_N = 100010;

Factorial fact(MAX_N);
vector<Mod> ifact;

Mod C( int a , int b ){
  return fact[a] * ifact[a-b] * ifact[b];
}

Mobius mobius( MAX_N );

int main(){

  ifact.resize( MAX_N );
  REP( i , MAX_N ) ifact[i] = inv( fact[i] );

  int q;
  scanf( "%d" , &q );
  REP( query_cnt , q ){
    int n, f;
    scanf( "%d %d" , &n , &f );
    vl fa = factor( n );
    Mod ans = 0;
    YYS( w , fa ){
      if( w >= f ) ans += mobius[n/w] * C(w-1,f-1);
    }
    printf( "%d\n" , (int)ans.n );
  }
  
  return 0;
}