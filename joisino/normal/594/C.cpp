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
const ld EPS = 1e-7;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

struct st{
  ll id, x, y;
  st(){}
  st( ll id , ll x , ll y ) : id(id) , x(x) , y(y) {}
};

int n, k;
vector<st> xs, ys;

bool cmpx( const st &a , const st &b ){
  if( a.x != b.x ) return a.x < b.x;
  return a.y < b.y;
}

bool cmpy( const st &a , const st &b ){
  if( a.y != b.y ) return a.y < b.y;
  return a.x < b.x;
}

int main(){

  scanf( "%d %d" , &n , &k );
  REP( i , n ){
    ll a, b, c, d;
    scanf( "%lld %lld %lld %lld" , &a , &b , &c , &d );
    a *= 2; b *= 2; c *= 2; d *= 2;
    ll x = ( a + c ) / 2;
    ll y = ( b + d ) / 2;
    xs.pb( i , x , y );
    ys.pb( i , x , y );
  }

  sort( ALL(xs) , cmpx );
  sort( ALL(ys) , cmpy );

  ll ans = INFLL;
  REP( a , k+1 ) REP( b , k+1 ) REP( c , k+1 ) REP( d , k+1 ){
    set<int> ss;
    REP( i , a ) ss.insert( xs[i].id );
    REP( i , b ) ss.insert( xs[n-1-i].id );
    REP( i , c ) ss.insert( ys[i].id );
    REP( i , d ) ss.insert( ys[n-1-i].id );
    if( SZ(ss) == k ){
      ll w = max( 1LL , xs[n-1-b].x - xs[a].x ); if( w % 2 == 1 ) w++;
      ll h = max( 1LL , ys[n-1-d].y - ys[c].y ); if( h % 2 == 1 ) h++;
      chmin( ans , ( w * h ) / 4 );
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}