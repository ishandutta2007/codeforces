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


const int MAX_N = 100010;


ll n, m, k;
ll sum;
ll t[MAX_N];
ll c[MAX_N];

bool ng;

ll dist[512][512];

Unionfind uf;

typedef pair<ll,pl> edge;

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &k );
  REP( i , k ) scanf( "%lld" , &c[i] );
  REP( i , k ){
    sum += c[i];
    t[sum]++;
  }
  REP( i , n ) t[i+1] += t[i];

  uf.init( n );

  REP( i , k ) REP( j , k ) dist[i][j] = INFLL;
  REP( i , k ) dist[i][i] = 0;
  
  REP( i , m ){
    ll a, b, d;
    scanf( "%lld %lld %lld" , &a , &b , &d ); a--; b--;
    if( d == 0 ) uf.unite( a , b );
    chmin( dist[ t[a] ][ t[b] ] , d );
    chmin( dist[ t[b] ][ t[a] ] , d );
  }

  sum = 0;
  REP( i , k ){
    REP( j , c[i]-1 ) if( !uf.same( sum+j , sum+j+1 ) ) ng = true;
    sum += c[i];
  }

  REP( l , k ) REP( i , k ) REP( j , k ) chmin( dist[i][j] , dist[i][l] + dist[l][j] );
  REP( i , k ) REP( j , k ) if( dist[i][j] == INFLL ) dist[i][j] = -1;

  if( ng ) printf( "No\n" );
  else {
    printf( "Yes\n" );
    REP( i , k ) REP( j , k ) printf( "%lld%c" , dist[i][j] , j==k-1?'\n':' ' );
  }

  return 0;
}