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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

int n, m;

vi G[500010];

bool used[500010];
list<int> u;

vi v[500010];

void bfs( int sx , int k ){
  queue<int> que;
  que.push( sx );
  while( !que.empty() ){
    int x = que.front();
    que.pop();

    used[x] = true;
    v[k].pb( x );
    
    auto ite = u.begin();
    auto ee = G[x].begin();
    while( ite != u.end() ){
      int y = *ite;
      if( y == x ){
	ite = u.erase( ite );
	continue;
      }
      while( ee != G[x].end() && (*ee) < y ) ee++;
      // cout << x << " " << y << " " << (*ee) << endl;
      if( ee == G[x].end() || y != *ee ){
	que.push( y );
	ite = u.erase( ite );
      } else {
	ite++;
      }
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) SORT( G[i] );

  REP( i , n ) u.push_back( i );
  
  int k = 0;
  REP( i , n ) if( !used[i] ) bfs( i , k++ );

  printf( "%d\n" , k );
  REP( i , k ){
    printf( "%lld" , SZ(v[i]) );
    YYS( w , v[i] ) printf( " %d" , w+1 );
    printf( "\n" );
  }
  
  return 0;
}