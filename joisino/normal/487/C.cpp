#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
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

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
//const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll MOD;

struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};
typedef vector<Mod> vm;

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



vi ps;
vb notp;
int max_p;
void init_p( int mp = 1000010 ){
  max_p = mp;
  notp.resize( max_p , false );
  notp[0] = notp[1] = true;
  FOR( i , 2 , max_p ){
    if( !notp[i] ){
      ps.pb( i );
      for( int j = i*2; j < max_p; j += i )
	notp[j] = true;
    }
  }
}
bool is_prime( int x ){
  if( max_p <= x ) init_p( x+1 );
  return !notp[x];
}

ll n;

int main(){

  init_p();
  cin >> n;
  MOD = n;

  if( n == 1 ) return puts( "YES\n1" );
  if( n == 4 ) return puts( "YES\n1\n3\n2\n4" );
  if( !is_prime( n ) ) return puts( "NO" );

  printf( "YES\n1\n" );
  FOR( i , 2 , n )
    printf( "%d\n" , (int)(Mod(i)/Mod(i-1)).n );
  printf( "%d\n" , (int)n );

  return 0;
}