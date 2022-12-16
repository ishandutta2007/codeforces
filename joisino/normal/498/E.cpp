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
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll MOD = 1e9 + 7;

struct Mod{
  ll n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( ( a.n + b.n ) % MOD ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( ( a.n - b.n + MOD ) % MOD ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( ( a.n * b.n ) % MOD ); }
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
Mod operator / ( Mod a  , Mod b ){ return Mod( ( a.n * inv(b).n ) % MOD ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


typedef vector<Mod> vec;
typedef vector<vec> mat;

mat mul( mat a , mat b ){
  mat c = mat( a.size() , vec( b[0].size() , 0 ) );
  REP( i , c.size() )
    REP( j , c[i].size() )
      REP( k , a[i].size() )
      c[i][j] = c[i][j] + a[i][k]*b[k][j];
  return c;
}

mat pow( mat a , ll k ){
  mat res = mat( a.size() , vec( a.size() , 0 ) );
  REP( i , res.size() )
    res[i][i] = 1;
  
  while( k > 0 ){
    if( k % 2 == 1 ){
      res = mul( res , a );
    }
    a = mul( a , a );
    k /= 2;
  }
  return res;
}


Mod nx[1<<7];
Mod x[1<<7];

int a;
int main(){
  REP( i , 1<<7 )
    nx[i] = x[i] = 0;
  nx[0] = 1;
  
  bool st = false;
  REP( i , 7 ){
    cin >> a;
    for( int j = (1<<i)-1; j >= 0; j-- )
      x[j+(1<<i)] = nx[j];
    
    mat A( 1<<(i+1) , vec( 1<<(i+1) , 0 ) );
    REP( j , 1<<(i+1) ) REP( k , 1<<(i+1) ){
      REP( l , 1<<i ){
	bool ok = true;
	int o = 1 + l*2 + (1<<(i+1));
	REP( m ,  i+1 )
	  if( (j&(1<<m)) && (k&(1<<m)) && (o&(1<<m)) && (o&(1<<(m+1))) )
	    ok = false;
	if( ok ) A[j][k] += 1;
      }
    }
    
    A = pow( A , a );

    REP( j , (1<<(i+1)) )
      nx[j] = 0;
    REP( j , (1<<(i+1)) )
      FOR( k , (1<<i) , (1<<(i+1)) )
      nx[j] += A[j][k] * x[k];
  }

  cout << nx[(1<<7)-1].n << endl;

  return 0;
}