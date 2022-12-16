#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
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

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};
typedef vector<Mod> vm;

Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( ( (ll)a.n * inv(b).n ) % MOD ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


struct Bit{
  vl bit;
  int size;
  void init( int n ){
    n++;
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
  }
  void add( int k , ll x ){
    k++;
    while( k <= size ){
      bit[k] += x;
      k += k & -k;
    }
  }
  ll sum( int k ){
    k++;
    ll res = 0;
    while( k > 0 ){
      res += bit[k];
      k -= k & -k;
    }
    return res;
  }
  ll get( int k ){
    return sum(k)-sum(k-1);
  }
  ll update( int k , ll x ){
    add( k , x-get(k) );
  }
};


struct Tree{
  gr G;
  int n, logn, r;
  vi nst, sst;
  vi dep;
  vl w;
  vi par;
  vb used;
  mi ps;
  vi in, out;
  int etcnt;
  bool dfs_f, lca_f, et_f;
  Bit etbit;
  void init( int num , int root = 0 ){
    n = num;
    r = root;
    G = gr( n );
    par = vi( n , -1 );
    w = vl( n , 1 );
    dfs_f = lca_f = et_f = false;
  }
  Tree( int num , int root = 0 ){
    init( num , root );
  }
  Tree(){}
  void set_weight( const vl &weight ){
    w = weight;
  }
  void set_graph_dfs( const gr &g , int x ){
    used[x] = true;
    REPR( w , g[x] ){
      if( !used[w.fi] ){
	G[x].pb( w );
	set_graph_dfs( g , w.fi );
      }
    }
  }
  void set_graph( const gr &g , int root = 0 ){
    init( g.size() , root );
    used = vb( n , 0 );
    G = gr( n );
    set_graph_dfs( g , root );
  }
  void set_graph( int root = 0 ){
    gr tempg = G;
    set_graph( tempg , root );
  }
  void add_edge( int x , int p , ll co = 1 ){
    G[p].pb( pl( x , co ) );
  }
  void add_biedge( int a , int b , ll co = 1 ){
    G[a].pb( pl( b , co ) );
    G[b].pb( pl( a , co ) );
  }
  void dfs( int x , int p , int d ){
    used[x] = true;
    dep[x] = d;
    nst[x] = 1;
    sst[x] = w[x];
    par[x] = p;
    REPR( w , G[x] ){
      if( p != x && !used[w.fi] ){
	dfs( w.fi , x , d+1 );
	nst[x] += nst[w.fi];
	sst[x] += sst[w.fi];
      }
    }
  }
  void dfs(){
    used = vb( n , false );
    nst = sst = vi( n );
    dep = vi( n );
    dfs( r , -1 , 0 );
    dfs_f = true;
  }
  void init_lca(){
    if( !dfs_f ) dfs();
    
    logn = (int)log2( n ) + 1;
    
    ps = mi( logn , vi( n , -1 ) );
    ps[0] = par;
    
    FOR( i , 1 , logn ){
      REP( j , n ){
	if( ps[i-1][j] == -1 ) ps[i][j] = -1;
	else ps[i][j] = ps[i-1][ps[i-1][j]];
      }
    }

    lca_f = true;
  }
  int lca( int a , int b ){
    if( !lca_f ) init_lca();
    if( dep[a] > dep[b] ) swap( a , b );
    for( int i = logn; i >= 0; i-- )
      if( (dep[b]-dep[a])&(1<<i) ) b = ps[i][b];
    if( a == b ) return a;
    for( int i = logn-1; i >= 0; i-- ){
      if( ps[i][a] != ps[i][b] ){
	a = ps[i][a];
	b = ps[i][b];
      }
    }
    return ps[0][a];
  }
  void etdfs( int x ){
    in[x] = etcnt++;
    REPR( w , G[x] ){
      etdfs( w.fi );
      etbit.add(  in[w.fi] ,  w.se );
      etbit.add( out[w.fi] , -w.se );
    }
    out[x] = etcnt++;
  }
  void etdfs(){
    if( !dfs_f ) dfs();
    if( !lca_f ) init_lca();
    etcnt = 0;
    in  = vi( n );
    out = vi( n );
    etbit.init( 2*n );
    etdfs( r );
    et_f = true;    
  }
  void etupdate( int x , ll d ){
    if( !et_f ) etdfs();
    etbit.update(  in[x] ,  d );
    etbit.update( out[x] , -d );
  }
  ll dist( int a , int b ){
    if( !et_f ) etdfs();
    return etbit.sum( in[a] ) + etbit.sum( in[b] ) - etbit.sum( in[lca(a,b)] ) * 2;
  }

  vm ds, dss;
  void dsdfs( int x ){
    REPR( w , G[x] ){
      dsdfs( w.fi );
      Mod c = w.se;
      ds[x]  += ds[w.fi] + Mod(nst[w.fi]) * c;
      dss[x] += dss[w.fi] + Mod(2) * c * ds[w.fi] + c * c * Mod(nst[w.fi]);
    }
  }
  void dsdfs(){
    ds  = dss = vm( n , 0 );
    dsdfs( r );
  }

  vm ss, sss;
  void qdfs( int x , Mod sum , Mod sums ){
    ss[x] = sum;
    sss[x] = sums;
    REPR( w , G[x] ){
      int t = w.fi;
      Mod c = w.se;
      qdfs( t , sum + Mod( n - 2 * nst[t] ) * c , sums + c * c * Mod(n) - Mod(4) * ( ds[t] + c * Mod(nst[t]) ) * c + Mod(2) * sum * c );
    }
  }
  void qdfs(){
    dsdfs();
    ss = sss = vm( n );
    qdfs( r , ds[r] , dss[r] );
  }
  Mod mdist( int u , int v ){
    return Mod(dist(u,v));
  }
  Mod querya( int u , int v ){
    if( lca( u , v ) == v ){
      return sss[u] - ( sss[v] - dss[v] + mdist(u,v)*mdist(u,v) * Mod( n - nst[v] ) + Mod(2) * mdist(u,v) * ( ss[v] - ds[v] ) );
    } else {
      return dss[v] + mdist(u,v)*mdist(u,v)*Mod(nst[v]) + Mod(2) * mdist(u,v) * ds[v];
    }
  }
  Mod query( int u , int v ){
    return Mod(2) * querya( u , v ) - sss[u];
  }
};

Tree T;

int n, q;

int main(){

  cin >> n;
  T.init( n );
  REP( i , n-1 ){
    int a , b , c;
    cin >> a >> b >> c; a--; b--;
    T.add_biedge( a , b , c );
  }
  T.set_graph( 0 );

  T.dfs();
  T.init_lca();
  T.etdfs();
  T.qdfs();

  cin >> q;
  REP( i , q ){
    int u, v;
    cin >> u >> v; u--; v--;
    cout << T.query( u , v ).n << endl;
  }
  
  return 0;
}