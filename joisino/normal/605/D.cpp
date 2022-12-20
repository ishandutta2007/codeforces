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

template<class T> vi compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

vpi nv;

struct Segtree{
  vector<set<pi> > node;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<set<pi> >( size*2-1 );
  }
  void add( int k , pi x ){
    k += size-1;
    node[k].insert( x );
    while( k > 0 ){
      k = (k-1)/2;
      node[k].insert( x );
    }
  }
  void del( int k , pi x ){
    k += size-1;
    node[k].erase( node[k].find( x ) );
    while( k > 0 ){
      k = (k-1)/2;
      node[k].erase( node[k].find( x ) );
    }
  }
  void query( int a , int b , int k , int l , int r ){
    if( r <= a ){
      YYS( w , node[k] ){
        if( w.fi <= b ){
          nv.pb( w );
        } else {
          break;
        }
      }
    } else if( a <= l ){

    } else {
      query( a , b , k*2+1 , l , (l+r)/2 );
      query( a , b , k*2+2 , (l+r)/2 , r );
    }
  }
  void query( int a , int b ){
    query( a , b , 0 , 0 , size );
  }
};


int n;

int dist[100010];
int pr[100010];

queue<int> que;

vi xs, ys;

int a[100010];
int b[100010];
int c[100010];
int d[100010];

Segtree seg;

int main(){

  n = in();
  REP( i , n ){
    dist[i] = INF;
  }
  REP( i , n ){
    xs.pb( in() );
    ys.pb( in() );
    if( xs.back() == 0 && ys.back() == 0 ){
      que.push( i );
      dist[i] = 1;
      pr[i] = -1;
    }
    xs.pb( in() );
    ys.pb( in() );
  }

  xs = compress( xs );
  ys = compress( ys );

  REP( i , n ){
    a[i] = xs[i*2];
    b[i] = ys[i*2];
    c[i] = xs[i*2+1];
    d[i] = ys[i*2+1];
  }

  seg.init( 2*n );

  REP( i , n ){
    if( dist[i] != 1 ){
      seg.add( a[i] , pi( b[i] , i ) );
    }
  }

  while( !que.empty() ){
    int x = que.front();
    que.pop();
    nv.clear();
    seg.query( c[x]+1 , d[x] );
    YYS( w , nv ){
      // cout << x << " " << w.fi << " " << w.se << endl;
      seg.del( a[w.se], w );
      dist[w.se] = dist[x] + 1;
      pr[w.se] = x;
      que.push( w.se );
    }
  }

  if( dist[n-1] == INF ){
    puts( "-1" );
  } else {
    vi ans(0);
    int cur = n-1;
    while( cur != -1 ){
      ans.pb( cur );
      cur = pr[cur];
    }
    REVERSE( ans );
    printf( "%d\n" , dist[n-1] );
    REP( i , SZ(ans) ){
      if( i != 0 ){
        printf( " " );
      }
      printf( "%d" , ans[i]+1 );
    }
    printf( "\n" );
  }
  
  return 0;
}