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


pl operator -( const pl &a , const pl &b ){ return pl( a.fi-b.fi , a.se-b.se ); }
inline ll det( const pl &a , const pl &b ){ return a.fi*b.se-a.se*b.fi; }
inline ll dot( const pl &a , const pl &b ){ return a.fi*b.fi+a.se*b.se; }
inline int ccw( pl a , pl b , pl c ){
  ll detc = det(b-a,c-a);
  if( detc > 0 ) return 1;
  if( detc < 0 ) return -1;
  return 0;
}
inline int ccw2( pl a , pl b , pl c ){
  ll detc = det(b-a,c-a);
  if( detc > 0 ) return 1;
  if( detc < 0 ) return -1;
  if( dot(b-a,c-a) <= 0 ) return 2;
  return 0;
}

inline bool cross( const pl &a , const pl &b , const pl &c , const pl &d ){ return ccw(a,c,b)*ccw(a,d,b)==-1&&ccw(c,a,d)*ccw(c,b,d)==-1; }

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

const int MAX_N = 256;

int n;
bool cr[MAX_N][MAX_N];

int x[MAX_N];
int y[MAX_N];
pl p[MAX_N];

Mod memo[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];

bool isin( pl pp ){
  pl qq = pl( (rand()%200-100)*(ll)INF , (rand()%200-100)*(ll)INF );
  int cnt = 0;
  REP( i , n ) if( cross( pp , qq , p[i] , p[(i+1)%n] ) ) cnt++;
  if( cnt % 2 == 1 ) return true;
  REP( i , n ) if( ccw2( pp , p[i] , p[(i+1)%n] ) == 2 ) return true;
  return false;
}

bool isin_rep( pl pp ){
  int  cnt = 0;
  REP( i , 10 ) if( isin( pp ) ) cnt++;
  //cout << cnt << endl;
  return cnt > 7;
}

Mod rec( int a , int b ){
  //cout << a << " " << b << endl;
  if( used[a][b] ) return memo[a][b];
  used[a][b] = true;
  if( a+2 >= b ) return memo[a][b] = 1;
  Mod res = 0;
  for( int i = a+1; i < b; i++ ){
    if( !cr[a][i] && !cr[i][b] ) res += rec( a , i ) * rec( i , b );
  }
  return memo[a][b] = res;
}

int main(){

  srand( time(NULL) );

  
  cin >> n;
  REP( i , n ) cin >> x[i] >> y[i];
  REP( i , n ) x[i] *= 2;
  REP( i , n ) y[i] *= 2;
  REP( i , n ) p[i] = pl( x[i] , y[i] );

  
  REP( i , n ) REP( j , n ){
    REP( k , n ) if( i != k && i != (k+1)%n && j != k && j != (k+1)%n && !cr[i][j] ) cr[i][j] |= cross( p[i] , p[j] , p[k] , p[(k+1)%n] );
    REP( k , n ) if( i != k && j != k && !cr[i][j] && ccw2( p[k] , p[i] , p[j] ) == 2 ) cr[i][j] = true;
    if( !cr[i][j] && !isin_rep( pl( (p[i].fi+p[j].fi)/2 , (p[i].se+p[j].se)/2 ) ) ) cr[i][j] = true;
  }
  
  /*
  REP( i , n ){
    REP( j , n ){
      if( !cr[i][j] ) printf( "ok " );
      else printf( "ng " );
    }
    printf( "\n" );
  }
  */
  
  cout << rec( 0 , n-1 ).n << endl;

  /*
  REP( i , n ){
    REP( j , n ) cout << memo[i][j].n << " ";
    cout << endl;
  }
  */
  
  return 0;
}