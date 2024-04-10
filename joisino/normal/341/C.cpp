#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

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




const int MAX_N = 2010;

int n;
int a[MAX_N];

int cnt, cnt2;
set<int> ss;

Mod ans;

vm fact;
void init_fact( int max_n ){
  fact.resize( max_n );
  fact[0] = 1;
  FOR( i , 1 , max_n ) fact[i] = fact[i-1] * i;
}

vector<vm> comb;
void init_comb( int max_n ){
  comb = vector<vm>( max_n , vm( max_n ) );
  REP( i , max_n ){
    comb[i][0] = comb[i][i] = 1;
    FOR( j , 1 , i )
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
  }
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) if( a[i] == -1 ){
    cnt++;
    ss.insert( i+1 );
  }
  REP( i , n ) if( a[i] != -1 && ss.find( a[i] ) != ss.end() ) cnt2++;
  cnt2 = cnt - cnt2;

  init_fact( cnt+1 );
  init_comb( cnt+1 );

  ans = fact[cnt];
  FOR( i , 1 , cnt2+1 ){
    if( i % 2 == 0 ) ans += fact[cnt-i]*comb[cnt2][i];
    else ans -= fact[cnt-i]*comb[cnt2][i];
  }
  
  printf( "%d\n" , (int)ans.n );
  
  return 0;
}