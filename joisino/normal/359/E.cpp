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

const ll MAX_N = 512;

const ll dx[] = { 1 , 0 , -1 , 0 };
const ll dy[] = { 0 , -1 , 0 , 1 };
const char s[] = "RULD";

ll n, xa, ya;
ll a[MAX_N][MAX_N];

bool used[MAX_N][MAX_N];

string ans;

bool isin( ll y , ll x ){
  return 0 <= y && y < n && 0 <= x && x < n;
}

bool check( ll y , ll x , ll d ){
  while( 1 ){
    y += dy[d];
    x += dx[d];
    if( !isin( y , x ) ) return false;
    if( a[y][x] == 1 ) return true;
  }
}

void dfs( ll y , ll x ){
  if( a[y][x] == 0 ) ans += '1';
  a[y][x] = 0;
  used[y][x] = true;
  

  REP( i , 4 ) if( check( y , x , i ) && !used[y+dy[i]][x+dx[i]] ){
    ans += s[i];
    dfs( y+dy[i] , x+dx[i] );
    ans += s[(i+2)%4];
  }
  
  ans += '2';
}

int main(){

  scanf( "%lld %lld %lld" , &n , &ya , &xa ); ya--; xa--;
  REP( i , n ) REP( j , n ) scanf( "%lld" , &a[i][j] );

  dfs( ya , xa );

  REP( i , n ) REP( j , n ) if( a[i][j] == 1 ){
    printf( "NO\n" );
    return 0;
  }

  printf( "YES\n" );
  printf( "%s\n" , ans.c_str() );
  
  return 0;
}