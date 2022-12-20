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

const int MAX_N = 100010;

typedef pair<pi,pi> st;

int n, m;
int dist[MAX_N], pr[MAX_N], prd[MAX_N];
int cnt;

vpi G[MAX_N];

queue<int> q;
priority_queue<st,vector<st>,greater<st> > cur, nex, to;

bool used[MAX_N];
int prt[MAX_N];
int mid;

vi ans, ansv;

void dijkstra(){
  REP( i , n ) dist[i] = INF;
  dist[0] = 0;
  pr[0] = -1;
  q.push( 0 );
  while( !q.empty() ){
    while( !q.empty() ){
      YYS( w , G[ q.front() ] ) if( dist[w.se] == INF ) to.emplace( pi( w.fi , dist[ q.front() ] ) , pi( w.se , q.front() ) );
      q.pop();
    }
    while( !to.empty() ){
      pi d = to.top().fi;
      int x = to.top().se.fi;
      int p = to.top().se.se;
      to.pop();
      if( dist[x] == INF ){
	pr[x] = p;
	prd[x] = d.fi;
	dist[x] = cnt;
	q.push( x );
      }
      if( to.empty() || to.top().fi != d ) cnt++;
    }
  }
}

void bfs(){
  mid = n-1;
  while( !q.empty() ) q.pop();
  q.push( n-1 );
  used[n-1] = true;
  prt[n-1] = -1;
  while( !q.empty() ){
    int x = q.front();
    q.pop();
    if( dist[x] < dist[mid] ) mid = x;
    YYS( w , G[x] ) if( !used[w.se] && w.fi == 0 ){
      prt[w.se] = x;
      used[w.se] = true;
      q.push( w.se );
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c );
    G[a].pb( c , b );
    G[b].pb( c , a );
  }

  dijkstra();

  // REP( i , n ) cout << i << " " << dist[i] << " " << pr[i] << " " << prd[i] << endl;
  
  bfs();

  int c = mid;
  while( c != -1 ){
    ans.pb( c );
    c = prt[c];
  }
  REVERSE( ans );
  ans.pop_back();

  c = mid;
  while( c != -1 ){
    ans.pb( c );

    if( c != 0 ) ansv.pb( prd[c] );
    c = pr[c];
  }

  REVERSE( ans );

  YYS( w , ansv ) printf( "%d" , w );
  printf( "\n" );
  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ) printf( "%d%c" , ans[i] , i == SZ(ans)-1 ? '\n':' ' );
  
  return 0;
}