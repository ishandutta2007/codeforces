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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1024;

ll k;
int c = 2;

int n = 1000;

vi G[MAX_N];
bool g[MAX_N][MAX_N];
queue<int> que;

int main(){

  scanf( "%lld" , &k );

  G[999].pb( 1 );
  FOR( i , 900 , 999 ) G[i].pb( i+1 );

  G[0].pb( 2 );
  REP( i , 100 ){
    que.push( c );
    G[c].pb( c+1 ); G[c].pb( c+2 ); G[c+1].pb( c+3 ); G[c+2].pb( c+3 );
    c += 3;
  }

  REP( i , 100 ){
    if( k % 2 == 1 ) G[que.front()].pb( 900+i*2 );
    que.pop(); k/= 2;
  }
  
  REP( i , n ) YYS( w , G[i] ) g[i][w] = g[w][i] = true;

  printf( "%d\n" , n );
  REP( i , n ){
    REP( j , n ){
      if( g[i][j] ) printf( "Y" );
      else printf( "N" );
    }
    printf( "\n" );
  }
  
  return 0;
}