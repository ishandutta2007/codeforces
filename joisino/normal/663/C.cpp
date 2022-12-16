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
typedef vector<vi> mi;
     
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

typedef pair<pi,int> ed;

int n, m;

vector<ed> edges;

Unionfind uf;

int cnt[100010][2];

pair<int,vi> calc( int p ){
  uf.init( 2 * n );
  YYS( w , edges ){
    int a = w.fi.fi;
    int b = w.fi.se;
    int c = ( w.se + p ) % 2;
    if( c == 0 ){
      uf.unite( a * 2 , b * 2 );
      uf.unite( a * 2 + 1 , b * 2 + 1 );
    } else {
      uf.unite( a * 2 , b * 2 + 1 );
      uf.unite( a * 2 + 1 , b * 2 );
    }
  }
  REP( i , n ){
    if( uf.same( i * 2 , i * 2 + 1 ) ){
      return make_pair( INF , vi({}) );
    }
  }
  REP( i , n ){
    REP( j , 2 ){
      cnt[i][j] = 0;
    }
  }
  REP( i , n ){
    int a = uf.find( i * 2 );
    int b = uf.find( i * 2 + 1 );
    int p = min( a , b ) / 2;
    if( uf.same( p * 2 , i * 2 + 1 ) ){
      assert( uf.same( p * 2 + 1 , i * 2 ) );
      cnt[p][0]++;
    } else if( uf.same( p * 2 + 1 , i * 2 + 1 ) ){
      assert( uf.same( p * 2 , i * 2 ) );
      cnt[p][1]++;
    }
  }
  vi res(0);
  REP( i , n ){
    int a = uf.find( i * 2 );
    int b = uf.find( i * 2 + 1 );
    int p = min( a , b ) / 2;
    if( cnt[p][0] <= cnt[p][1] ){
      if( uf.same( p * 2 , i * 2 + 1 ) ){
        res.pb( i );
      }      
    } else {
      if( uf.same( p * 2 + 1 , i * 2 + 1 ) ){
        res.pb( i );
      }
    }
  }
  return make_pair( SZ(res) , res );
}

int main(){

  n = in();
  m = in();
  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    string s = stin();
    if( s[0] == 'B' ){
      edges.pb( pi( a , b ) , 0 );
    } else if( s[0] == 'R' ){
      edges.pb( pi( a , b ) , 1 );
    } else {
      assert( false );
    }
  }

  auto resa = calc( 0 );
  auto resb = calc( 1 );

  auto ans = min( resa , resb );

  if( ans.fi == INF ){
    puts( "-1" );
    return 0;
  }

  printf( "%d\n" , ans.fi );
  REP( i , ans.fi ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , ans.se[i]+1 );
  }
  printf( "\n" );
  
  return 0;
}