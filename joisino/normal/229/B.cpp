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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct edge{
  ll fr , to, co;
  ll id;
  edge(){}
  edge( ll to ) : to(to){}
  edge( ll to , ll co ) : to(to) , co(co){}
  edge( ll fr , ll to , ll co ) : fr(fr) , to(to) , co(co){}
  edge( ll fr , ll to , ll co , ll id ) : fr(fr) , to(to) , co(co) , id(id){}  
};
typedef vector<vector<edge> > Graph;

const int MAX_N = 100010;

vl ts[MAX_N];

const int DIJKSTRA_MAX_N = 1000010;
struct Dijkstra{
  Graph G;
  vl dist;
  int size;
  vb used;
  
  void init( int n ){
    size = n;
    G.resize( size );
    dist.resize( size );
    used.resize( size );
  }
  
  Dijkstra(){
    init( DIJKSTRA_MAX_N );
  }
  
  void add_biedge( ll fr , ll to , ll co ){
    G[fr].pb( edge( to , co ) );
    G[to].pb( edge( fr , co ) );
  }
  
  void add_edge( ll fr , ll to , ll co ){
    G[fr].pb( edge( to , co ) );
  }

  ll dijkstra( ll s , ll t = 0 ){
    REP( i , size )
      dist[i] = INFLL;
    dist[s] = 0;
  
    priority_queue<pl,vector<pl>,greater<pl> > que;
    que.push( pl( 0 , s ) );

    int c = 0;
    while( !que.empty() ){
      ll d = que.top().fi;
      ll p = que.top().se;
      que.pop();
      if( used[p] ) continue;
      used[p] = true;

      if( t == p ) return dist[t];

      ll a = 0;
      while( a < ts[p].size() && ts[p][a] < d ) a++;
      while( a < ts[p].size() && ts[p][a] == d ){ d++; a++; }
      
      REP( i , G[p].size() ){
	ll to = G[p][i].to;
	ll co = G[p][i].co;
	if( d+co < dist[to] ){
	  dist[to] = d+co;
	  que.push( pl( dist[to] , to ) );
	}
      }
    }
    return -1;
  }
};

Dijkstra dij;

int n, m;
int a, b, c;



int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    scanf( "%d %d %d" , &a , &b , &c ); a--; b--;
    dij.add_biedge( a , b , c );
  }

  REP( i , n ){
    scanf( "%d" , &a );
    REP( j , a ){
      scanf( "%d" , &b );
      ts[i].pb( b );
    }
  }

  cout << dij.dijkstra( 0 , n-1 ) << endl;
  
  return 0;
}