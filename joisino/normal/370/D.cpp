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

const ll MAX_N = 2010;

ll n, m;
char s[MAX_N][MAX_N];
char ans[MAX_N][MAX_N];

ll sumw;
ll minx = INFLL, maxx = -INFLL, miny = INFLL, maxy = -INFLL;

bool check( ll top , ll bottom , ll left , ll right ){
  if( top < 0 || bottom >= n || left < 0 || right >= m ) return false;

  ll res = 0;
  FOR( i , top , bottom+1 ) if( s[i][left] == 'w' ) res++;
  FOR( i , top , bottom+1 ) if( s[i][right] == 'w' ) res++;
  FOR( j , left+1 , right ) if( s[top][j] == 'w' ) res++;
  FOR( j , left+1 , right ) if( s[bottom][j] == 'w' ) res++;

  if( res == sumw || ( top == bottom && s[top][left] == 'w' && sumw == 1 ) ){
    FOR( i , top , bottom+1 ) if( s[i][left] != 'w' ) s[i][left] = '+';
    FOR( i , top , bottom+1 ) if( s[i][right] != 'w' ) s[i][right] = '+';
    FOR( j , left+1 , right ) if( s[top][j] != 'w' ) s[top][j] = '+';
    FOR( j , left+1 , right ) if( s[bottom][j] != 'w' ) s[bottom][j] = '+';
    REP( i , n ) printf( "%s\n" , s[i] );
    return true;
  }
  return false;
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );
  REP( i , n ) REP( j , m ) if( s[i][j] == 'w' ){
    sumw++;
    chmin( miny , i );
    chmax( maxy , i );
    chmin( minx , j );
    chmax( maxx , j );
  }

  if( maxy - miny < maxx - minx ){
    if( check( maxy - ( maxx - minx ) , maxy , minx , maxx ) ) return 0;
    if( check( miny , miny + ( maxx - minx ) , minx , maxx ) ) return 0;
    if( check( n-1 - ( maxx - minx ) , n-1 , minx , maxx ) ) return 0;
    if( check( 0 , maxx - minx , minx , maxx ) ) return 0;
  } else {
    if( check( miny , maxy , maxx - ( maxy - miny ) , maxx ) ) return 0;
    if( check( miny , maxy , minx , minx + ( maxy - miny ) ) ) return 0;
    if( check( miny , maxy , m-1 - ( maxy - miny ) , m-1 ) ) return 0;
    if( check( miny , maxy , 0 , maxy - miny ) ) return 0;
  }

  printf( "-1\n" );
  
  return 0;
}