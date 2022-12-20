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

struct Unionfind{
  vi size, par;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n ) par[i] = i;
  }
  void init( int n ){
    size = vi( n , 1 );
    par.resize( n );
    REP( i , n ) par[i] = i;
  }
  int find( int x ){
    if( par[x] == x ) return x;
    return par[x] = find( par[x] );
  }
  bool unite( int x , int y ){
    x = find(x);
    y = find(y);
    if( x == y ) return false;
    if( size[y] < size[x] ) swap( x , y );
    par[x] = y;
    size[y] += size[x];
    return true;
  }
  bool same( int x , int y ){
    return find(x) == find(y);
  }
};

const int MAX_N = 1000010;
const string s[] = { "none" , "any" , "at least one" };

typedef pair<pi,int> ed;

int n, m;

Unionfind uf;

int ans[MAX_N];

vector<ed> es[MAX_N];

vpi G[MAX_N];

vector<ed> ces;
bool used[MAX_N];
int ord[MAX_N], lowlink[MAX_N];
int cnt;
void dfs( int x , int pid ){
  used[x] = true;
  ord[x] = lowlink[x] = cnt++;
  YYS( w , G[x] ){
    if( !used[ w.fi ] ){
      ces.pb( pi( x , w.fi ) , w.se );
      dfs( w.fi , w.se );
      chmin( lowlink[x] , lowlink[w.fi] );
    } else if( w.se != pid ){
      ces.pb( pi( x , w.fi ) , w.se );
      chmin( lowlink[x] , ord[w.fi] );
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c ); a--; b--;
    es[c].pb( pi( a , b ) , i );
  }

  uf.init( n );

  REP( i , MAX_N ){
    vi v(0);
    YYS( w , es[i] ){
      int a = uf.find( w.fi.fi );
      int b = uf.find( w.fi.se );
      if( a == b ) continue;
      v.pb( a ); v.pb( b );
      G[a].pb( b , w.se );
      G[b].pb( a , w.se );
    }
    
    YYS( w , v ) if( !used[w] ){
      cnt = 0;
      dfs( w , -1 );
    }

    YYS( w , ces ){
      if( ord[w.fi.fi] < lowlink[w.fi.se] ) ans[w.se] = 1;
      else ans[w.se] = 2;
      uf.unite( w.fi.fi , w.fi.se );
    }
    ces.clear();
    
    YYS( w , v ){
      used[w] = false;
      G[w].clear();
    }
  }

  REP( i , m ) printf( "%s\n" , s[ ans[i] ].c_str() );

  return 0;
}