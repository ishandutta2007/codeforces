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

const ll INF = 1e9+10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct Unionfind{
  vi size, par, gr;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n ) par[i] = i;
  }
  void init( int n ){
    size = vi( n , 1 );
    gr.resize( n );
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
    gr[y] += gr[x];
    return true;
  }
  bool same( int x , int y ){
    return find(x) == find(y);
  }
};

typedef pair<int,pi> ed;
vector<ed> edge;

Unionfind uf;

int n;
int sum;

bool check(){
  REP( i , n ) if( uf.find(i) == i && sum - uf.gr[i] < uf.size[i] ) return false;
  return true;
}

int answer( int ans ){
  printf( "%d\n" , ans );
  return 0;
}

int main(){

  scanf( "%d" , &n );
  edge.resize( n-1 );
  REP( i , n-1 ){
    scanf( "%d %d %d" , &edge[i].se.fi , &edge[i].se.se , &edge[i].fi ); edge[i].se.fi--; edge[i].se.se--;
  }

  uf.init( n );
  REP( i , n ) scanf( "%d" , &uf.gr[i] );
  REP( i , n ) sum += uf.gr[i];

  if( !check() ) return answer( 0 );
  
  SORT( edge );
  YYS( w , edge ){
    uf.unite( w.se.fi , w.se.se );
    if( !check() ) return answer( w.fi );
  }
  
  return 0;
}