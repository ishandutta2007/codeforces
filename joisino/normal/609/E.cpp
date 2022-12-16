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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
// typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

   
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

typedef pair<int,pi> ed;
typedef pair<ed,int> ei;

Unionfind uf;

vector<ei> edges;

int n, m;

set<pi> T;

vpl G[200010];

ll sum = 0;

ll ans[200010];

int dep[200010];
ll par[20][200010];
ll ma[20][200010];

void dfs( int x , int p , ll d , ll pc ){
  dep[x] = d;
  par[0][x] = p;
  ma[0][x] = pc;
  YYS( w , G[x] ){
    if( w.fi != p ){
      dfs( w.fi , x , d + 1 , w.se );
    }
  }
}

int main(){

  n = in();
  m = in();

  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    int c = in();
    edges.pb( ed( c , pi( a , b ) ) , i );
  }

  SORT( edges );

  uf.init( n );
  
  YYS( w , edges ){
    int a = w.fi.se.fi;
    int b = w.fi.se.se;
    int c = w.fi.fi;
    if( !uf.same( a , b ) ){
      uf.unite( a , b );
      T.insert( pi( a , b ) );
      sum += c;
      G[a].pb( b , c );
      G[b].pb( a , c );
    }
  }

  dfs( 0 , -1 , 0 , -INFLL );

  REP( i , 19 ){
    REP( j , n ){
      if( par[i][j] == -1 ){
        par[i+1][j] = -1;
        ma[i+1][j] = ma[i][j];
      } else {
        par[i+1][j] = par[i][par[i][j]];
        ma[i+1][j] = max( ma[i][j] , ma[i][par[i][j]] );
      }
    }
  }
  
  YYS( w , edges ){
    int a = w.fi.se.fi;
    int b = w.fi.se.se;
    int c = w.fi.fi;
    int d = w.se;
    if( T.find( pi( a , b ) ) != T.end() ){
      ans[d] = sum;
    } else {
      if( dep[a] > dep[b] ){
        swap( a , b );
      }
      ll r = -INFLL;
      REP( i , 20 ){
        if( (dep[b]-dep[a])&PW(i) ){
          chmax( r , ma[i][b] );
          b = par[i][b];
        }
      }
      if( a != b ){
        for( int i = 19; i >= 0; i-- ){
          if( par[i][a] != par[i][b] ){
            chmax( r , ma[i][a] );
            chmax( r , ma[i][b] );
            a = par[i][a];
            b = par[i][b];
          }
        }
        chmax( r , ma[0][a] );
        chmax( r , ma[0][b] );
        a = par[0][a];
        b = par[0][b];
      }
      assert( a == b );
      ll add = c - r;
      assert( add >= 0 );
      ans[d] = sum + add;
    }
  }

  REP( i , m ){
    printf( "%lld\n" , ans[i] );
  }
  
  return 0;
}