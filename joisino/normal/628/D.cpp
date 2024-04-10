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

const ll MAX_N = 2010;

int n;
int m, d;

char s[MAX_N], t[MAX_N];
int a[MAX_N], b[MAX_N];

Mod cur[MAX_N][2], nex[MAX_N][2];

Mod solve( int *x ){
  REP( i , MAX_N ) REP( j , 2 ) cur[i][j] = 0;
  cur[0][1] = 1;
  
  REP( i , n ){
    REP( i , MAX_N ) REP( j , 2 ) nex[i][j] = 0;
    REP( j , m ){
      if( i % 2 == 1 ){
	nex[(j*10+d)%m][0] += cur[j][0];
	if( d <  x[i] ) nex[(j*10+d)%m][0] += cur[j][1];
	if( d == x[i] ) nex[(j*10+d)%m][1] += cur[j][1];
      } else {
	REP( k , 10   ) if( k != d ) nex[(j*10+k)%m][0] += cur[j][0];
	REP( k , x[i] ) if( k != d ) nex[(j*10+k)%m][0] += cur[j][1];
	if( x[i] != d ) nex[(j*10+x[i])%m][1] += cur[j][1];
      }
    }
    swap( nex , cur );
  }
  return cur[0][0] + cur[0][1];
}

int main(){

  scanf( "%d %d" , &m , &d );
  scanf( "%s %s" , s , t );
  n = strlen( s );
  REP( i , n ) a[i] = s[i] - '0', b[i] = t[i] - '0';

  ll p = n-1;
  while( a[p] == 0 ){
    a[p] = 9;
    p--;
  }
  a[p]--;

  Mod ans = solve( b ) - solve( a );

  printf( "%d\n" , (int)ans.n );
  
  return 0;
}