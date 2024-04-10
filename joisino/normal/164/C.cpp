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


template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}


struct edge{
  int to, cap, cost, rev;
  edge(){}
  edge( int to, int cap, int cost, int rev ): to(to), cap(cap), cost(cost), rev(rev) {}
};

struct MinCostFlow{
  int n;
  vector<vector<edge> > G;
  vi dist, prevv, preve;
  MinCostFlow( int size ){
    n = size;
    G = vector<vector<edge> >( n, vector<edge>(0) );
  }
  int add_edge( int from, int to, int cap, int cost ){
    G[from].pb( to, cap, cost, SZ(G[to]) );
    G[to].pb( from, 0, -cost, SZ(G[from])-1 );
    return SZ(G[from])-1;
  }
  int min_cost_flow( int s, int t, int f ){
    int res = 0;
    while( f > 0 ){
      bool update = true;
      dist = prevv = preve = vi( n, INF );
      dist[s] = 0;
      while( update ){
	update = false;
	REP( i, n ){
	  if( dist[i] == INF ) continue;
	  REP( j, SZ(G[i]) ){
	    edge &e = G[i][j];
	    if( e.cap > 0 and dist[e.to] > dist[i] + e.cost ){
	      dist[e.to] = dist[i] + e.cost;
	      prevv[e.to] = i;
	      preve[e.to] = j;
	      update = true;
	    }
	  }
	}
      }

      if( dist[t] == INF ) return INF;

      int d = f;
      for( int p = t; p != s; p = prevv[p] ){
	chmin( d, G[prevv[p]][preve[p]].cap );
      }

      f -= d;
      res += d * dist[t];
      for( int p = t; p != s; p = prevv[p] ){
	edge &e = G[prevv[p]][preve[p]];
	e.cap -= d;
	G[p][e.rev].cap += d;
      }
    }
    return res;
  }
};

int n, k;
int s[1024], t[1024], c[1024];

vi st, es;

int main(){

  scanf( "%d %d" , &n , &k );
  REP( i, n ){
    scanf( "%d %d %d" , &s[i], &t[i], &c[i] ); t[i] += s[i];
    st.pb( s[i] );
    st.pb( t[i] );
  }

  auto cr = compress( st );
  st = cr.fi;
  int m = SZ(cr.se);

  MinCostFlow mcf(m+2);
  int s = m;
  int t = s+1;

  mcf.add_edge( s, 0, k, 0 );
  mcf.add_edge( m-1, t, k, 0 );
  REP( i, m-1 ) mcf.add_edge( i, i+1, k, 0 );
  
  REP( i, n ) es.pb( mcf.add_edge( st[i*2], st[i*2+1], 1, -c[i] ) );

  int res = mcf.min_cost_flow( s, t, k );
  assert( res != INF );

  REP( i, n ){
    if( mcf.G[st[i*2]][es[i]].cap == 0 ) printf( "1" );
    else printf( "0" );

    if( i == n-1 ) printf( "\n" );
    else printf( " " );
  }
  
  return 0;
}