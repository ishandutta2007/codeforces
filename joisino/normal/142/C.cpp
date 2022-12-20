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

const int MAX_N = 10;
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

const int ofsx[] = { 0 , 1 , 0 , 0 };
const int ofsy[]  { 1 , 0 , 1 , 2 };

int n, m;

int ans;
string best[10];
string s[10];

bool f = false;

int posxb( int x , int d , int e ){
  if( e == 4 ) return x;
  if( e == d ) return x - 2 * dx[e];
  return x + dx[e];
}

int posyb( int y , int d , int e ){
  if( e == 4 ) return y;
  if( e == d ) return y - 2 * dy[e];
  return y + dy[e];
}

int posx( int x , int d , int e ){ return posxb( x , d , e ) + ofsx[d]; }
int posy( int y , int d , int e ){ return posyb( y , d , e ) + ofsy[d]; }

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

bool check( int y , int x , int t ){
  REP( i , 5 ){
    int ny = posy( y , t , i );
    int nx = posx( x , t , i );
    if( !isin( ny , nx ) || s[ny][nx] != '.' ) return false;
  }
  return true;
}

void dfs( int y , int x , int cur , int rest ){
  if( x == m ){
    dfs( y+1 , 0 , cur , rest );
    return;
  }
  if( cur + rest / 5 <= ans ) return;
  if( y == n ){
    if( cur > ans ){
      f = true;
      ans = cur;
      REP( i , n ) best[i] = s[i];
    }
    return;
  }

  REP( i , 4 ){
    if( check( y , x , i ) ){
      REP( j , 5 ) s[ posy( y , i , j ) ][ posx( x , i , j ) ] = 'A' + cur;
      dfs( y , x+1 , cur+1 , rest-5 );
      REP( j , 5 ) s[ posy( y , i , j ) ][ posx( x , i , j ) ] = '.';
    }
  }
  
  dfs( y , x+1 , cur , s[y][x] == '.' ? rest-1 : rest );
}

int main(){

  scanf( "%d %d" , &n , &m );
  ans = n*m/5;
  while( 1 ){
    REP( i , n ){
      s[i] = "";
      REP( j , m ) s[i] += '.';
      best[i] = s[i];
    }
    dfs( 0 , 0 , 0 , n*m );
    if( f ) break;
    ans--;
  }

  printf( "%d\n" , ans );
  REP( i , n ) printf( "%s\n" , best[i].c_str() );

  return 0;
}