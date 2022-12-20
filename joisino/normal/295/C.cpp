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



vector<vm> comb;
void init_comb( int max_n ){
  comb = vector<vm>( max_n , vm( max_n ) );
  REP( i , max_n ){
    comb[i][0] = comb[i][i] = 1;
    FOR( j , 1 , i )
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
  }
}


Mod memo[256][64][64];
bool used[256][64][64];
int cnt50, cnt100;

int n, k;
int ans = INF;

Mod rec( int t , int a , int b ){
  if( t == ans ){
    if( a == 0 && b == 0 ) return Mod(1);
    return Mod(0);
  }
  if( used[t][a][b] ) return memo[t][a][b];
  used[t][a][b] = true;
  int c = cnt50-a;
  int d = cnt100-b;
  Mod res = 0;
  if( t % 2 == 0 ){
    REP( i , a+1 ){
      REP( j , b+1 ){
	if( i * 50 + j * 100 > k ) break;
	if( i + j == 0 ) continue;
	res += rec( t+1 , a-i , b-j ) * comb[a][i] * comb[b][j];
      }
    }
  } else {
    REP( i , c+1 ){
      REP( j , d+1 ){
	if( i * 50 + j * 100 > k ) break;
	if( i + j == 0 ) continue;
	res += rec( t+1 , a+i , b+j ) * comb[c][i] * comb[d][j];
      }
    }
  }
  return memo[t][a][b] = res;
}

void rec2( int t , int a , int b ){
  if( t == 256 ) return;
  if( used[t][a][b] ) return;
  used[t][a][b] = true;
  if( a == 0 && b == 0 ) chmin( ans , t );
  if( t >= ans ) return;
  int c = cnt50-a;
  int d = cnt100-b;
  Mod res = 0;
  if( t % 2 == 0 ){
    REP( i , a+1 ){
      REP( j , b+1 ){
	if( i * 50 + j * 100 > k ) break;
	if( i + j == 0 ) continue;
	rec2( t+1 , a-i , b-j );
      }
    }
  } else {
    REP( i , c+1 ){
      REP( j , d+1 ){
	if( i * 50 + j * 100 > k ) break;
	if( i + j == 0 ) continue;
	rec2( t+1 , a+i , b+j );
      }
    }
  }
}


int main(){

  cin >> n >> k;
  REP( i , n ){
    int a;
    cin >> a;
    if( a == 50 ) cnt50++;
    else cnt100++;
  }

  init_comb( 256 );
  
  rec2( 0 , cnt50 , cnt100 );
  REP( i , 256 ) REP( j , 64 ) REP( k , 64 ) used[i][j][k] = false;

  if( ans == INF ){
    cout << -1 << endl;
    cout << 0 << endl;
    return 0;
  }
  
  cout << ans << endl;
  cout << rec( 0 , cnt50 , cnt100 ).n << endl;

  
  
  return 0;
}