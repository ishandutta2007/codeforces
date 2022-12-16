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

int x[3], y[3];
vi v(3);
 
int main(){

  REP( i , 3 ) scanf( "%d %d" , &x[i] , &y[i] );

  REP( i , 2 ){
    REP( j , 2 ){
      REP( k , 2 ){
	if( x[0] == x[1] && x[1] == x[2] && y[0] + y[1] + y[2] == x[0] ){
	  printf( "%d\n" , x[0] );
	  REP( l , 3 ){
	    REP( m , y[l] ){
	      REP( n , x[l] )printf( "%c" , 'A'+l );
	      printf( "\n" );
	    }
	  }
	  return 0;
	}
	swap( x[2] , y[2] );
      }
      swap( x[1] , y[1] );
    }
    swap( x[0] , y[0] );
  }

  REP( i , 3 ) v[i] = i;
  
  do{
    REP( i , 2 ){
      REP( j , 2 ){
	REP( k , 2 ){
	  if( x[ v[0] ] == x[ v[1] ] + x[ v[2] ] && x[ v[0] ] == y[ v[0] ] + y[ v[1] ] && y[ v[1] ] == y[ v[2] ] ){
	    printf( "%d\n" , x[ v[0] ] );
	    REP( l , y[ v[0] ] ){
	      REP( m , x[ v[0] ] ) printf( "%c" , 'A'+v[0] );
	      printf( "\n" );
	    }
	    REP( l , y[ v[1] ] ){
	      REP( m , x[ v[1] ] ) printf( "%c" , 'A'+v[1] );
	      REP( m , x[ v[2] ] ) printf( "%c" , 'A'+v[2] );
	      printf( "\n" );
	    }
	    return 0;
	  }
	  swap( x[ v[2] ] , y[ v[2] ] );
	}
	swap( x[ v[1] ] , y[ v[1] ] );	
      }
      swap( x[ v[0] ] , y[ v[0] ] );
    }
  } while( next_permutation( ALL(v) ) );

  printf( "-1\n" );

  return 0;
}