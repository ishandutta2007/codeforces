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

vl compress( vl a ){
  vl ord = a, res;
  SORT( ord );
  ord.erase( unique( ALL( ord ) ) , ord.end() );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

const int MAX_N = 100010;

int n, m;

vl coo;

pi bus[MAX_N];

Mod dp[MAX_N], sum[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  coo.resize( 2*m );
  REP( i , m ) scanf( "%lld %lld" , &coo[i*2] , &coo[i*2+1] );
  coo.pb( 0 );
  coo.pb( n );
  coo = compress( coo );

  REP( i , m ){
    bus[i].se = coo[i*2];
    bus[i].fi = coo[i*2+1];
  }

  sort( bus , bus+m );
  
  sum[0] = 1;
  int p = 0;
  REP( i , m ){
    while( p != bus[i].fi ){
      sum[p+1] = sum[p]; p++;
    }
    int t = bus[i].fi;
    int s = bus[i].se;
    sum[t] += sum[t-1];
    if( s > 0 ) sum[t] -= sum[s-1];
  }
  while( p != coo.back() ){ sum[p+1] = sum[p]; p++; }

  cout << ( sum[ coo.back() ] - sum[ coo.back()-1 ] ).n << endl;

  return 0;
}