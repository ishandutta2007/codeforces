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

const int MAX_N = 64;
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

int n, m;

char col[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];

bool ans = false;

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs( int y , int x , int py , int px ){
  if( used[y][x] ){
    ans = true;
    return;
  }
  used[y][x] = true;
  
  REP( i , 4 ){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if( !( ny == py && nx == px ) && isin( ny , nx ) && col[y][x] == col[ny][nx] ) dfs( ny , nx , y , x );
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , col[i] );

  REP( i , n ) REP( j , m ) if( !used[i][j] ) dfs( i , j , -1 , -1 );

  if( ans ) puts( "Yes" );
  else puts( "No" );
  
  return 0;
}