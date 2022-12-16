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


const int MAX_N = 128;

const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

int n, m;

int ma[MAX_N][MAX_N];

vi v;

bool check( int y , int x , int c ){
  REP( i , 4 ) if( ma[y+dy[i]][x+dx[i]] == c ) return true;
  return false;
}

int getsize( int y , int x , int col ){
  FOR( size , 1 , INF ){
    FOR( i , y , y+size+1 ) if( ma[i][x+size] != -1 || check( i , x+size , col ) ) return size;
    FOR( j , x , x+size+1 ) if( ma[y+size][j] != -1 || check( y+size , j , col ) ) return size;
    if( y + size > n || x + size > m ) return size;
  }
  return 1;
}

void paint( int y , int x ){

  if( !check( y , x , 0 ) ){
    int size = getsize( y , x , 0 );
    FOR( i , y , y+size ) FOR( j , x , x+size ) ma[i][j] = 0;
  } else if( !check( y , x , 1 ) ){
    int size = getsize( y , x , 1 );
    FOR( j , x+1 , x+size ) if( ma[y-1][j] != 0 ){
      size = j - x; break;
    }
    FOR( i , y , y+size ) FOR( j , x , x+size ) ma[i][j] = 1;
  } else {
    FOR( col , 2 , INF ){
      if( !check( y , x , col ) ){
	ma[y][x] = col;
	break;
      }
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );

  REP( i , n+2 ) REP( j , m+2 ) ma[i][j] = -1;
  FOR( i , 1 , n+1 ) FOR( j , 1 , m+1 ) if( ma[i][j] == -1 ) paint( i , j );

  FOR( i , 1 , n+1 ){
    FOR( j , 1 , m+1 ) printf( "%c" , 'A' + ma[i][j] );
    printf( "\n" );
  }
  
  return 0;
}