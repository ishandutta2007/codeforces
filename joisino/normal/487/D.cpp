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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 101010;
const int B = 765;

int n, m, q;

char s[MAX_N][16];

pi a[MAX_N][16];
pi b[MAX_N/B][16];

void set_line( int x ){
  REP( i , m ){
    int p = i;
    REP( k , 16 ){
      if( s[x][p] == '^' ) break;
      if( s[x][p] == '>' ) p++;
      if( s[x][p] == '<' ) p--;
      if( p == -1 || p == m ) break;
      if( k == 15 ) p = INF;
    }
    a[x][i].fi = p;
    if( p == -1 || p == m || p == INF ) a[x][i].se = x;
  }
}

void set_b( int x ){
  REP( i , m ){
    int p = i;
    for( int j = (x+1)*B-1; j >= x*B; j-- ){
      p = a[j][p].fi;
      if( p == -1 || p == m || p == INF ){
	b[x][i].se = j;
	break;
      }
    }
    b[x][i].fi = p;
  }
}

pi query( int x , int y ){
  int p = y;
  for( int j = x; j >= (x/B)*B; j-- ){
    if( a[j][p].fi == -1 || a[j][p].fi == m || a[j][p].fi == INF ) return a[j][p];    
    p = a[j][p].fi;
  }
  for( int j = (x/B)-1; j >= 0; j-- ){
    if( b[j][p].fi == -1 || b[j][p].fi == m || b[j][p].fi == INF ) return b[j][p];
    p = b[j][p].fi;
  }
  return pi( p , 0 );
}

int main(){

  scanf( "%d %d %d\n" , &n , &m , &q );
  REP( i , n ) scanf( "%s\n" , s[i] );

  REP( i , n ) set_line( i );
  int l = (n-1)/B+1;
  REP( i , l ) set_b( i );

  REP( query_cnt , q ){
    char t, z;
    int x, y;
    scanf( "%c " , &t );
    if( t == 'A' ){
      scanf( "%d %d\n" , &x , &y ); x--; y--;
      pi res = query( x , y );
      if( res.fi == -1 ) printf( "%d 0\n" , res.se+1 );
      else if( res.fi == m ) printf( "%d %d \n" , res.se+1 , m+1 );
      else if( res.fi == INF ) printf( "-1 -1\n" );
      else printf( "0 %d\n" , res.fi+1 );
    } else if( t == 'C' ){
      scanf( "%d %d %c\n" , &x , &y , &z ); x--; y--;
      s[x][y] = z;
      set_line( x );
      set_b( x/B );      
    }
  }
  
  return 0;
}