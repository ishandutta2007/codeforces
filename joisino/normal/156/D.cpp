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

struct UnionFind{
  vi par, size;
  UnionFind( int n ){
    par = size = vi(n, 1);
    REP( i, n ) par[i] = i;
  }
  int find( int x ){
    if( x == par[x] ) return x;
    return par[x] = find( par[x] );
  }
  void unite( int x, int y ){
    x = find( x );
    y = find( y );
    if( x == y ) return;
    par[x] = y;
    size[y] += size[x];
  }
};

ll n, m, k;

int main(){

  scanf( "%lld %lld %lld", &n, &m, &k );

  UnionFind uf(n);

  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    uf.unite( a, b );
  }

  ll ans = 1;
  ll cmp = 0;
  REP( i , n ) if( uf.find(i) == i ){
    cmp++;
    ans = ( ans * uf.size[i] ) % k;
  }

  if( cmp == 1 ){
    printf( "%lld\n" , 1 % k );
    return 0;
  }

  REP( i, cmp-2 ) ans = ( ans * n ) % k;

  printf( "%lld\n" , ans );
  
  return 0;
}