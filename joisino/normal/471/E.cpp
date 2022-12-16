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

vl compress( vl a ){
  vl ord = a, res;
  SORT( ord );
  ord.erase( unique( ALL( ord ) ) , ord.end() );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

Unionfind uf;


struct Segtree{
  vector<ll> cnt, an;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    cnt = vector<ll>( size*2-1 , 0 );
    an = vector<ll>( size*2-1 , -2 );
  }
  void add( int k , int id ){
    k += size-1;
    cnt[k] = 1;
    an[k] = id;
    while( k > 0 ){
      k = (k-1)/2;
      cnt[k] = cnt[k*2+1] + cnt[k*2+2];
      if( an[k] == -2 ) an[k] = id;
      else an[k] = -1;
    }
  }
  void del( int k ){
    k += size-1;
    cnt[k] = 0;
    an[k] = -2;
    while( k > 0 ){
      k = (k-1)/2;
      cnt[k] = cnt[k*2+1] + cnt[k*2+2];
      an[k] = -1;
      if( an[k*2+1] == -2 && an[k*2+2] == -2 ) an[k] = -2;
    }
  }
  ll query( int a , int b , int id , int k , int l , int r ){
    if( an[k] == -2 ) return 0;
    if( a <= l && r <= b ){
      if( an[k] != -1 ){
	if( uf.same( an[k] , id ) ) return cnt[k];
	uf.unite( an[k] , id );
	return cnt[k]-1;
      }
      an[k] = id;
    } else if( b <= l || r <= a ){
      return 0;
    }
    ll chl = query( a , b , id , k*2+1 , l , (l+r)/2 );
    ll chr = query( a , b , id , k*2+2 , (l+r)/2 , r );
    return chl + chr;
  }
  ll query( int a , int b , int id ){
    return query( a , b , id , 0 , 0 , size );
  }
};


typedef pair<pl,pl> plpl;
typedef vector<plpl> vplpl;

#define ADD -1
#define DEL INFLL

const int MAX_N = 200010;

int n;

ll x1[MAX_N], x2[MAX_N];
ll z1[MAX_N], z2[MAX_N];
vl ix, iy;
vl xs, ys;

Segtree seg;

vplpl qu;

ll res[MAX_N];
ll ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%lld %lld %lld %lld" , &x1[i] , &z1[i] , &x2[i] , &z2[i] );
    ix.pb( x1[i] ); ix.pb( x2[i] );
    iy.pb( z1[i] ); iy.pb( z2[i] );
  }
  xs = compress( ix );
  ys = compress( iy );

  REP( i , n ){
    if( xs[i*2] == xs[i*2+1] ) qu.pb( pl( xs[i*2] , ys[i*2] ) , pl( ys[i*2+1] , i ) );
    else{
      qu.pb( pl( xs[i*2] , ADD ) , pl( ys[i*2] , i ) );
      qu.pb( pl( xs[i*2+1] , DEL ) , pl( ys[i*2] , i ) );
      res[i] = x2[i] - x1[i];
    }
  }

  SORT( qu );
  uf.init( n );
  seg.init( 3*n );

  YYS( q , qu ){
    int id = q.se.se;
    if( q.fi.se == ADD ) seg.add( q.se.fi , id );
    else if( q.fi.se == DEL ) seg.del( q.se.fi );
    else res[id] = z2[id] - z1[id] - seg.query( q.fi.se , q.se.fi+1 , id );
  }

  REP( i , n ) if( uf.find( i ) != i ) res[uf.find(i)] += res[i];
  REP( i , n ) if( uf.find( i ) == i ) chmax( ans , res[i] );
  cout << ans << endl;
  
  return 0;
}