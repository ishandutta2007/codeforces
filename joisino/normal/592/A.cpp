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

char board[16][16];

int ansa = INF, ansb = INF;

int main(){

  REP( i , 8 ) scanf( "%s" , board[i] );

  REP( i , 8 ) REP( j , 8 ){
    bool ng = false;
    if( board[i][j] == 'W' ){
      REP( k , i ) if( board[k][j] != '.' ) ng = true;
      if( !ng ) chmin( ansa , i );
    }
    if( board[i][j] == 'B' ){
      FOR( k , i+1 , 8 ) if( board[k][j] != '.' ) ng = true;
      if( !ng ) chmin( ansb , 7-i );
    }
  }

  if( ansa <= ansb ) printf( "A\n" );
  else printf( "B\n" );
  
  return 0;
}