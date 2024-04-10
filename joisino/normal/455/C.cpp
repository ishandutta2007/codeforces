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

struct Unionfind{
  vector<int> size;
  vector<int> par;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n )
      par[i] = i;
  }
  void init( int n ){
    size.resize( n );
    par.resize( n );
    REP( i , n ){
      size[i] = 1;
      par[i] = i;
    }
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

const int MAX_N = 300010;

vector<int> G[MAX_N];

pi diameter_dfs( int x , int p ){
  pi res = pi( 0 , x );
  REPR( w , G[x] ){
    if( w == p ) continue;
    pi ret = diameter_dfs( w , x );
    ret.fi++;
    if( res.fi < ret.fi ) res = ret;
  }
  return res;
}
int diameter( int x ){
  pi resf = diameter_dfs( x , -1 );
  pi ress = diameter_dfs( resf.se , -1 );
  return ress.fi;
}


Unionfind uf;

int n, m, q;
int a, b, c;

int d[MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &m , &q  );

  uf.init( n );
  
  REP( i , m ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
    uf.unite( a , b );
  }

  REP( i , n )
    if( uf.find( i ) == i ) d[i] = diameter( i );

  REP( i , q ){
    scanf( "%d" , &a );
    if( a == 2 ){
      scanf( "%d %d" , &b , &c ); b--; c--;
      if( !uf.same( b , c ) ){
	b = uf.find( b );
	c = uf.find( c );
	uf.unite( b , c );
	d[uf.find(b)] = max( (d[b]+1)/2 + (d[c]+1)/2 + 1 , max( d[b] , d[c] ) );
      }
    } else if( a == 1 ){
      scanf( "%d" , &b ); b--;
      cout << d[uf.find(b)] << endl;
    }
  }
  
  return 0;
}